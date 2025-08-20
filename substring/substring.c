#include <stdlib.h>
#include <string.h>
#include "substring.h"


typedef struct {
    const char *word; /* pointeur vers la chaîne word[] passée en entrée */
    int count;        /* occurrences attendues de ce mot */
    int id;           /* id unique compact (0..unique_words-1) */
    int used;         /* slot occupé ? */
} entry_t;

typedef struct {
    entry_t *tab;
    int size;         /* taille de la table (puissance de 2 recommandée) */
    int word_len;     /* longueur commune des mots */
    int next_id;      /* compteur d'id attribués aux mots uniques */
} wmap_t;

static unsigned long hash_str_fixed(const char *s, int len)
{
    unsigned long h = 5381;
    for (int i = 0; i < len; i++)
        h = ((h << 5) + h) ^ (unsigned char)s[i];
    return h;
}

static int next_pow2(int x)
{
    int p = 1;
    while (p < x) p <<= 1;
    return p;
}

static wmap_t *wmap_create(const char **words, int nb_words, int word_len)
{
    if (nb_words <= 0) return NULL;

    wmap_t *m = malloc(sizeof(*m));
    if (!m) return NULL;

    int cap = next_pow2(nb_words * 2);
    m->tab = calloc((size_t)cap, sizeof(entry_t));
    if (!m->tab) { free(m); return NULL; }

    m->size = cap;
    m->word_len = word_len;
    m->next_id = 0;

    for (int i = 0; i < nb_words; i++) {
        const char *w = words[i];
        unsigned long h = hash_str_fixed(w, word_len);
        int idx = (int)(h & (unsigned long)(cap - 1));

        /* linear probing */
        while (m->tab[idx].used) {
            if (strncmp(m->tab[idx].word, w, word_len) == 0) {
                m->tab[idx].count += 1; /* mot déjà présent : incrémente */
                goto inserted;
            }
            idx = (idx + 1) & (cap - 1);
        }

        /* nouveau mot unique */
        m->tab[idx].used = 1;
        m->tab[idx].word = w;
        m->tab[idx].count = 1;
        m->tab[idx].id = m->next_id++;
    inserted:
        ;
    }

    return m;
}

static void wmap_free(wmap_t *m)
{
    if (!m) return;
    free(m->tab);
    free(m);
}

/* Renvoie l'id du mot si trouvé, -1 sinon. key n'est pas NUL-terminé (pris dans s). */
static int wmap_lookup_id(const wmap_t *m, const char *key)
{
    unsigned long h = hash_str_fixed(key, m->word_len);
    int idx = (int)(h & (unsigned long)(m->size - 1));

    while (m->tab[idx].used) {
        if (strncmp(m->tab[idx].word, key, m->word_len) == 0)
            return m->tab[idx].id;
        idx = (idx + 1) & (m->size - 1);
    }
    return -1;
}

/* Récupère le count attendu pour un id (parcours simple, taille petite). */
static int wmap_expected_count_by_id(const wmap_t *m, int id)
{
    /* Comme id est attribué séquentiellement aux mots uniques, il existe. */
    /* On parcourt la table pour trouver l'entrée avec l'id donné. */
    for (int i = 0; i < m->size; i++) {
        if (m->tab[i].used && m->tab[i].id == id)
            return m->tab[i].count;
    }
    return 0;
}

/* --------- Fonction principale --------- */

int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
    int *result = NULL;
    int res_cap = 0, res_len = 0;

    if (n) *n = 0;
    if (!s || !words || nb_words <= 0) return NULL;

    int s_len = (int)strlen(s);
    int word_len = (int)strlen(words[0]);
    if (word_len == 0) return NULL;

    for (int i = 1; i < nb_words; i++) {
        if ((int)strlen(words[i]) != word_len)
            return NULL;
    }

    int window_len = nb_words * word_len;
    if (s_len < window_len) return NULL;

    wmap_t *m = wmap_create(words, nb_words, word_len);
    if (!m) return NULL;

    int uniq = m->next_id;
    int *win_count = calloc((size_t)uniq, sizeof(int));
    if (!win_count) { wmap_free(m); return NULL; }

    for (int offset = 0; offset < word_len; offset++) {
        int left = offset;
        int right = offset;
        int matched = 0; /* nombre total de mots (avec répétitions) dans la fenêtre */

        /* remet à zéro les compteurs de fenêtre */
        memset(win_count, 0, (size_t)uniq * sizeof(int));

        while (right + word_len <= s_len) {
            const char *token = s + right;
            int id = wmap_lookup_id(m, token);

            if (id == -1) {
                /* mot inconnu : on réinitialise la fenêtre après ce token */
                memset(win_count, 0, (size_t)uniq * sizeof(int));
                matched = 0;
                right += word_len;
                left  = right;
                continue;
            }

            /* on ajoute le mot à la fenêtre */
            win_count[id] += 1;
            matched += 1;
            right += word_len;

            while (win_count[id] > wmap_expected_count_by_id(m, id)) {
                int left_id = wmap_lookup_id(m, s + left);
                win_count[left_id] -= 1;
                matched -= 1;
                left += word_len;
            }

            if (matched == nb_words) {
                /* push left dans result */
                if (res_len == res_cap) {
                    int new_cap = (res_cap == 0) ? 8 : res_cap * 2;
                    int *tmp = realloc(result, (size_t)new_cap * sizeof(int));
                    if (!tmp) { /* en cas d'échec, on nettoie et sort */
                        free(result);
                        free(win_count);
                        wmap_free(m);
                        return NULL;
                    }
                    result = tmp;
                    res_cap = new_cap;
                }
                result[res_len++] = left;

                /* puis on décale d'un mot (on enlève le mot de gauche) */
                {
                    int left_id = wmap_lookup_id(m, s + left);
                    win_count[left_id] -= 1;
                    matched -= 1;
                    left += word_len;
                }
            }
        }
    }

    free(win_count);
    wmap_free(m);

    if (res_len == 0) {
        free(result);
        return NULL;
    }

    if (n) *n = res_len;
    return result;
}
