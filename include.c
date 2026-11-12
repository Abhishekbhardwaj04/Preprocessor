#include "header.h"

void process_includes(FILE *in, FILE *out) {
    char line[256];
    while (fgets(line, sizeof(line), in)) {
        if (strncmp(line, "#include", 8) == 0) {
            char fname[50];
            int i = 9, j = 0;
            while (line[i] != '"' && line[i] != '>' && line[i] != '\0') {
                fname[j++] = line[i++];
            }
            fname[j] = '\0';

            FILE *finc = fopen(fname, "r");
            if (finc) {
                char ch;
                while ((ch = fgetc(finc)) != EOF) {
                    fputc(ch, out);
                }
                fclose(finc);
            }
        } else if (strncmp(line, "#define", 7) == 0) {
            add_macro(line);
        } else {
            substitute_macros(line, out);
        }
    }
}