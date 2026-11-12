# Preprocessor Project

This Project is written in C language that acts like a preprocessor to remove comments and handle file inclusions or macros.

# Files
- header.h: Header file and function declaration
- main.c: Main file 
- comment.c: Removes comments from code
- include.c: Handles header/file inclusions
- macro.c: Handles macro
- Makefile: To build the project easily

## How to Run
1. Open terminal in the project folder.

gcc main.c comment.c include.c macro.c -o mypreprocessor

.\mypreprocessor main.c




# Output
------------------------------------------------
# Remove header file and comments

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
