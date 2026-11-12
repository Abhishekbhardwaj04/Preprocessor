#include "header.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./mypreprocessor <filename.c>\n");
        return 1;
    }

    char *infile = argv[1];
    char outfile[100];
    strcpy(outfile, infile);
    strcat(outfile, ".i");

    FILE *fin = fopen(infile, "r");
    if (!fin) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE *ftemp = fopen("temp.tmp", "w+");
    remove_comments(fin, ftemp);
    fclose(fin);

    rewind(ftemp);
    FILE *fout = fopen(outfile, "w");
    process_includes(ftemp, fout);
    fclose(ftemp);
    fclose(fout);

    remove("temp.tmp");
    printf("Successfully generated: %s\n", outfile);
    return 0;
}