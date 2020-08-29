# Operating Systems
### Programming Exercise 1

The program `multistrdiff` compares pairs of strings. The source code for this program is as follows:

```c
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
```

In this exercise you are asked to implement the program `multistrdiff` again, in _three_ different versions. In each version, the parent process will be used to interact with the user (and won't be used for computation) and a child process will be used for computation (and won't be used for interacting with the user). The versions differ by the mechanism used for communication between the parent process and the child process:
- Version A - The parent should create a separate child for each pair of strings. The child should get the strings in `argv` and return the result of the comparison as the return value of `main`. The child must call `execve` and use the program `mystrdiff` (the source code for which, `mystrdiff.c`, is provided in the exercise folder).
- Version B - The parent should create a single child that should call `execve` and use the program `multistrdiff`. The communication between the parent and the child should be done using pipes.
- Version C - The parent should create a single child. The communication between the parent and the child should be done using shared memory (`mmap`). There's no need to call `execve`.
