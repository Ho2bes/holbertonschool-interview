#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>

typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

listint_t *find_listint_loop(listint_t *head);  // 👈 AJOUT ICI

#endif /* LISTS_H */
