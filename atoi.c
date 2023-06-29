#include "header.h"

int _atoin(const char *s, int len)
{
	/* declarations */
	int i, base, res, digit;

	/* inits */
	res = 0;
	base = 1;

	for (i = 0; i < len; i++)
	{
		digit = s[len - i - 1] - 48;
		res += digit * base;
		base = base * 10;
	}

	return (res);
}
