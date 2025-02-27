#ifndef PALINDROME_H
#define PALINDROME_H

int is_palindrome(unsigned long n);

#endif /* PALINDROME_H */

#include "palindrome.h"

/**
 * is_palindrome - Checks if an unsigned long number is a palindrome
 * @n: The number to be checked
 *
 * Return: 1 if n is a palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long reversed = 0, original = n, remainder;

	while (n != 0)
	{
		remainder = n % 10;
		reversed = reversed * 10 + remainder;
		n /= 10;
	}

	return (original == reversed);
}
