#include "holberton.h"

/**
 * wildcmp - Compare two strings considering the wildcard '*'
 * @s1: First string
 * @s2: Second string, may contain the special character '*'
 *
 * Return: 1 if strings can be considered identical, otherwise 0
 */
int wildcmp(char *s1, char *s2)
{
    if (*s1 == '\0' && *s2 == '\0')
        return (1);

    if (*s2 == '*')
    {
        if (*(s2 + 1) == '\0')
            return (1);
        if (wildcmp(s1, s2 + 1))
            return (1);
        if (*s1 != '\0' && wildcmp(s1 + 1, s2))
            return (1);
    }
    else if (*s1 == *s2)
    {
        return (wildcmp(s1 + 1, s2 + 1));
    }

    return (0);
}
