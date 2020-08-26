#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include "mystrlib.h"

#define STRLEN (80)

int main(int argc, char *argv[])
{
    char str1[STRLEN + 1], str2[STRLEN + 1];

    while ((mygets(str1, STRLEN) != NULL) && (mygets(str2, STRLEN) != NULL))
    {
        __pid_t pid;
        int status;
        switch (pid = fork())
        {
        case -1:
            fprintf(stderr, "Failed to fork a new process.\n");
            return 1;
        case 0:
            execl("mystrdiff", "mystrdiff", str1, str2, NULL);
            fprintf(stderr, "Failed to exec 'mystrdiff'.\n");
            return 1;
        default:
            waitpid(pid, &status, 0);
            if (WIFEXITED(status))
            {
                printf("%d\n", WEXITSTATUS(status));
            }
            else if (WIFSIGNALED(status))
            {
                printf("Child process %d terminated abnormally (because of signal %d).\n", pid, WTERMSIG(status));
                return 1;
            }
            else
            {
                printf("Child process %d terminated for an unknown reason.\n", pid);
                return 1;
            }
            break;
        }
    }

    return 0;
}
