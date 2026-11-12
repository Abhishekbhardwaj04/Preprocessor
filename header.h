#ifndef PREPROCESSOR_H
#define PREPROCESSOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void remove_comments(FILE *in, FILE *out);
void process_includes(FILE *in, FILE *out);
void add_macro(char *line);
void substitute_macros(char *line, FILE *out);

#endif