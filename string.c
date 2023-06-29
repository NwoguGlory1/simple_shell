#include "header.h"

int _strncmp(char *s1, char *s2, int n)
{
	int i;

	for (i = 0; i < n - 1; i++)
	{
		if (s1[i] == '\0' || s2[i] == '\0')
		{
			break;
		}

		if (s1[i] != s2[i]) /* if chars are different, break */
		{
			break;
		}
	}

	return (s1[i] - s2[i]); /* return difference in chars */
}

int _strlen(const char *str)
{
	int i;			/* i used as a counter */

	i = 0;			/* initialize at 0 */

	/* while string isn't over */
	while (*str != '\0')
	{
		i++;		/* increase counter */
		str++;		/* pointer arithmetic for next char */
	}

	return (i);
}

char *_strcat(char *dest, const char *src)
{
	size_t dest_len = _strlen(dest);
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[dest_len + i] = src[i];
	}

	dest[dest_len + i] = '\0';

	return (dest);
}

char *_strcpy(char *dest, const char *src)
{
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	i++;
	dest[i] = '\0';

	return (dest);
}

/* on error, returns NULL */
char *_strdup(char *str)
{
	int i, length;
	char *str2; 			/* hold the second string */

	for (i = 0; *str != '\0'; i++) /* get the length */
	{
		str++;
	}

	length = i;

	str = str - length; 		/* pointer arithmetic to first element */

	str2 = malloc(sizeof(char) * (length + 1)); /* assign the memory */

	if (str2 == NULL)	/* check the memory */
	{
		perror("strdup");
		return (NULL);
	}

	for (i = 0; i <= length; i++)	/* copy null char as well */
	{
		*str2 = *str; 		/* copy char */
		str++;			/* increase */
		str2++;			/* char */
	}

	return (str2 - length - 1); 	/* return the pointer */
}
