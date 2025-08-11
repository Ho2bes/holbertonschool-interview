#include "regex.h"

/**
 * regex_match - checks if a pattern matches a string
 * Supports:
 *  - '.'  : matches any single character
 *  - 'x*' : matches zero or more of the preceding character 'x'
 *
 * @str:     string to scan (may be empty; will not contain '.' or '*')
 * @pattern: regex pattern (may be empty; may contain '.' and '*')
 *
 * Return: 1 if the pattern matches the entire string, 0 otherwise
 */
int regex_match(char const *str, char const *pattern)
{
    /* If pattern is empty, match only if string is also empty */
    if (*pattern == '\0')
        return (*str == '\0');

    /* Check if first character matches (taking '.' into account) */
    int first_match = (*str != '\0') &&
                      (*pattern == *str || *pattern == '.');

    /* Handle the '*' quantifier (applies to the preceding char) */
    if (*(pattern + 1) == '*')
    {
        /*
         * Two possibilities:
         * 1) Use zero occurrence of preceding char: advance pattern by 2
         * 2) Use one occurrence (if first matches): advance string by 1, keep pattern
         */
        return (regex_match(str, pattern + 2) ||
                (first_match && regex_match(str + 1, pattern)));
    }

    /* Otherwise, consume one char from both if they match and continue */
    return (first_match && regex_match(str + 1, pattern + 1));
}
