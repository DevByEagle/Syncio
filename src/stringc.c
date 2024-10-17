#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/stringc.h"

StringC strinit(const char* initial) {
    StringC str = { 0 };
    if (initial) {
        str.length = strlen(initial);
        str.data = (char*)malloc(str.length + 1);
        if (str.data) {
            strcpy(str.data, initial);
        } else {
            str.length = 0;
            str.data = (char*)malloc(1); // Allocate space for the null terminator
            if (str.data) {
                str.data[0] = '\0';
            }
        }
    }

    return str;
}

void join(StringC* str, const char* additional) {
    if (additional) {
        size_t additional_length = strlen(additional);
        str->data = (char*)realloc(str->data, str->length + additional_length + 1);
        if (str->data) {
            strcat(str->data, additional);
            str->length += additional_length;
        }
    }
}

int cmpstr(const StringC* str1, const StringC* str2) {
    return strcmp(str1->data, str2->data);
}

bool ptrstr(const StringC* str) {
    if (!str) {
        raise("[ERROR] No data provided");
        return false;
    } else {
        println("%s\n", str->data);
        return true;
    }
}

size_t size(StringC* str) {
    return str->length;
}

void strfree(StringC* str) {
    free(str->data);
    str->data = NULL;
    str->length = false;
}