#include "header.h"

void remove_comments(FILE *in, FILE *out) {
    int c, next;
    int in_comment = 0;

    while ((c = fgetc(in)) != EOF) {
        if (!in_comment) {
            if (c == '/') {
                next = fgetc(in);
                if (next == '/') {
                    while ((c = fgetc(in)) != EOF && c != '\n');
                    if (c == '\n') fputc(c, out);
                    continue;
                } else if (next == '*') {
                    in_comment = 1;
                    continue;
                } else {
                    ungetc(next, in);
                }
            }
            fputc(c, out);
        } else {
            if (c == '*') {
                next = fgetc(in);
                if (next == '/') {
                    in_comment = 0;
                } else {
                    ungetc(next, in);
                }
            }
        }
    }
}