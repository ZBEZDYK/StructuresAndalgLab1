#define _CRT_SECURE_NO_WARNINGS
#include "method_fille.h"
#include <direct.h>
#include <string.h>
#include <ctype.h>

void process_string(char str[]);

void process_file_string() {
    _mkdir("Laba1");

    FILE* in = fopen("Laba1/input.txt", "r");
    if (!in) return;

    FILE* out = fopen("Laba1/output.txt", "w");
    if (!out) {
        fclose(in);
        return;
    }

    char buffer[1000] = "";
    if (fgets(buffer, sizeof(buffer), in)) {
        int len = (int)strlen(buffer);
        char result[1000] = { 0 };
        int result_index = 0;

        int space_count = 0;

        for (int i = 0; i <= len; i++) {
            if (buffer[i] == ' ') {
                space_count++;
            }
            else {
                if (space_count > 0) {
                    if (space_count > 4) {
                        result[result_index++] = '_';
                    }
                    space_count = 0;
                }

                if (i < len) {
                    result[result_index++] = buffer[i];
                }
            }
        }

        fputs(result, out);
    }

    fclose(in);
    fclose(out);
}