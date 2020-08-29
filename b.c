#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include "mystrlib.h"

#define STRLEN (80)

int main(int argc, char *argv[])
{
    char str1[STRLEN + 1], str2[STRLEN + 1];
    int toChild[2], fromChild[2];
    __pid_t pid;

    if (pipe(toChild) || pipe(fromChild))
    {
        fprintf(stderr, "Failed to create pipes.\n");
        return 1;
    }

    switch (pid = fork())
    {
        int status;
        FILE *fToChild, *fFromChild;

    case -1:
        fprintf(stderr, "Failed to fork a new process.\n");
        return 1;

    case 0: // In the child process:

        // Redirect stdin and stdout to the pipes.
        dup2(toChild[0], STDIN_FILENO);
        dup2(fromChild[1], STDOUT_FILENO);

        // Close original pipe file descriptors.
        close(toChild[0]);
        close(toChild[1]);
        close(fromChild[0]);
        close(fromChild[1]);

        // Exec
        execl("multistrdiff", "multistrdiff", NULL);

        // If we get to this point, execl has failed.
        fprintf(stderr, "Failed to exec 'multistrdiff'.\n");
        return 1;

    default: // In the parent process:

        // Close unneeded file descriptors.
        close(toChild[0]);
        close(fromChild[1]);

        // Create streams from pipes.
        fToChild = fdopen(toChild[1], "w");
        fFromChild = fdopen(fromChild[0], "r");

        // Read two input strings from stdin.
        while (NULL != mygets(str1, STRLEN) && NULL != mygets(str2, STRLEN))
        {
            char line[STRLEN + 1];

            // Send the strings to the child.
            fprintf(fToChild, "%s\n", str1);
            fprintf(fToChild, "%s\n", str2);
            fflush(fToChild);

            // Read the result back from the child and write it to stdout.
            fgets(line, STRLEN + 1, fFromChild);
            fputs(line, stdout);
        }

        fclose(fFromChild);
        fclose(fToChild);

        waitpid(pid, &status, 0);
        if (!WIFEXITED(status) || 0 != WEXITSTATUS(status)) {
            fprintf(stderr, "Child process (PID %d) terminated abnormally.\n", pid);
            return 1;
        }
        
        break;
    }

    return 0;
}
