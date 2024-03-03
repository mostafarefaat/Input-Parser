#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Option{
    char shortname;
    char *longname;
    char *description;
    void (*action)(void *);
};

void arg_parse(struct Option *options, int argc, char *argv[]);
void _help(void *h);