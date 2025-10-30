#define _CRT_SECURE_NO_WARNINGS
#include "method_c.h"
#include <string.h>
#include <ctype.h>

void process_cstring(char str[]) {
    int len = (int)strlen(str);
    char result[256] = { 0 };
    int result_index = 0;

    int space_count = 0;

    for (int i = 0; i <= len; i++) {
        if (str[i] == ' ') {
            space_count++;
        }
        else {
            if (space_count > 0) {
                if (space_count > 4) {
                    result[result_index++] = '_';
                }
                else {
                }
                space_count = 0;
            }

            if (i < len) {
                result[result_index++] = str[i];
            }
        }
    }

    strcpy(str, result);
}