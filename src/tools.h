#ifndef TOOLS_H
#define TOOLS_H

#include <stdio.h>
#include <unistd.h>

/*
  Function Declarations for builtin shell commands:
 */
int cd(char **args);
int help(char **args);
int shellexit(char **args);

/*
  List of builtin commands, followed by their corresponding functions.
 */
char *builtin_str[] = {
    "cd",
    "help",
    "shellexit"
};

int (*builtin_func[]) (char **) = {
    &cd,
    &help,
    &shellexit
};

int num_builtins() {
    return sizeof(builtin_str) / sizeof(char *);
}

/*
  Builtin function implementations.
*/
int cd(char **args)
{
    if (args[1] == NULL) {
        fprintf(stderr, "cshell: expected argument to \"cd\"\n");
    } else {
        if (chdir(args[1]) != 0) {
            perror("cshell");
        }
    }
    return 1;
}

int help(char **args)
{
    int i;
    printf("Hugo's CShell\n");
    printf("Type program names and arguments, and hit enter.\n");
    printf("The following are built in:\n");

    for (i = 0; i < num_builtins(); i++) {
        printf("  %s\n", builtin_str[i]);
    }

    printf("Use the man command for information on other programs.\n");
    return 1;
}

int shellexit(char **args)
{
  return 0;
}

#endif