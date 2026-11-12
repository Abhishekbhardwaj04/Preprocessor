#include "header.h"

char m_names[50][30];
char m_vals[50][100];
int m_count = 0;

void add_macro(char *line) {
    char name[30], val[100];
    if (sscanf(line, "#define %s %[^\n]", name, val) == 2) {
        strcpy(m_names[m_count], name);
        strcpy(m_vals[m_count], val);
        m_count++;
    }
}

void substitute_macros(char *line, FILE *out) {
    char temp[256];
    strcpy(temp, line);

    for (int i = 0; i < m_count; i++) {
        char *pos = strstr(temp, m_names[i]);
        if (pos) {
            int idx = pos - temp;
            char new_line[256];
            strncpy(new_line, temp, idx);
            new_line[idx] = '\0';
            strcat(new_line, m_vals[i]);
            strcat(new_line, pos + strlen(m_names[i]));
            strcpy(temp, new_line);
        }
    }
    fputs(temp, out);
}