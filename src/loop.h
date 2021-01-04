#ifndef LOOP_H
#define LOOP_H

#include "read_line.h"
#include "split_line.h"
#include "execute.h"

void loop(void)
{
    char *line;
    char **args;
    int status;

    do {
        printf("> ");
        line = read_line();
        args = split_line(line);
        status = execute(args);

        free(line);
        free(args);
    } while (status);
}

#endif