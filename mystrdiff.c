#include <stdio.h>
#include <stdlib.h>
#include "mystrlib.h"

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s [str1] [str2]\n", argv[0]);
		exit (-1);
	}
#ifdef _DBUG_
	printf("%d\n", mystrdiff(argv[1], argv[2]));
#endif
	return mystrdiff(argv[1], argv[2]); 
}
