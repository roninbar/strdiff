
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystrlib.h"

char *mygets(char *str, int len)
{
	char *retval;
	char *strterm;

	retval = fgets(str, len, stdin);
	strterm = strchr(str,'\n');
	if (strterm != NULL)
	{
		*strterm = '\0';
	} else {
		str[len] = '\0';
	}
	return retval;
}

int mystrdiff(char *str1, char *str2)
{
	int retval;
	int len, len1, len2;
	int i;

	len1 = strlen(str1);
	len2 = strlen(str2);
	len = (len1 < len2) ? len1 : len2;
	retval = abs(len1 - len2);
	for (i = 0; i < len ; i++)
	{
		if (str1[i] != str2[i])
		{
			retval++;
		}
	}
	return retval;
}


