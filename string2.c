#include "header.h"

/**
 * _cstrcmp - cut string compare, meaning it will cut both strings to the
 * smallest length of the two, and then perform the comparison.
 *
 * @s1: first string
 * @s2: second string
 *
 * Return: 0 if cut strings are equal, > 0 if s1 is lexicographically greater,
 * < 0 if smaller.
 */
int _cstrcmp(const char *s1, const char *s2)
{
	int i, s1_len, s2_len, s_len;

	s1_len = _strlen(s1);
	s2_len = _strlen(s2);

	/* printf("s1_len: %d\n", s1_len); */
	/* printf("s2_len: %d\n", s2_len); */

	s_len = _min(s1_len, s2_len);

	/* printf("min: %d\n", s_len); */

	for (i = 0; i < s_len; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}

	return (0);
}

/* gives the max of two numbers */
int _max(int n, int m)
{
	if (n > m)
	{
		return (n);
	}

	return (m);
}

/* gives the min of two numbers */
int _min(int n, int m)
{
	if (n < m)
	{
		return (n);
	}

	return (m);
}

/**
 * _strcmp - compare two strings
 *
 * @s1: first string
 * @s2: second string
 *
 * Return: < 0 if s1 < s2, > 0 if s2 > s1, 0 if strings match
 */
int _strcmp(const char *s1, const char *s2)
{
        int i = 0;
        int j = 0;

        for ( ; s1[i] != '\0'; i++)
        {
                if (s1[j] != s2[j]) /* if chars are different, break */
                {
                        break;
                }
                j++;
        }
        return (s1[j] - s2[j]); /* return difference in chars */
}
