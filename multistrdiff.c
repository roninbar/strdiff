#include <stdio.h>
#include <string.h>
#include "mystrlib.h"

#define STRLEN (80)

int main(int argc, char *argv[])
{
	char str1[STRLEN + 1], str2[STRLEN + 1];

	while ((mygets(str1, STRLEN) != NULL) && (mygets(str2, STRLEN) != NULL))
	{
		printf("%d\n", mystrdiff(str1, str2));
	}
	return 0;
}

