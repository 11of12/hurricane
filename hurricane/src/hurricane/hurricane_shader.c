#include "stdlib.h"
#include "string.h"
#include "stdio.h"
const char* hurricane_load_shader(const char* filepath) {
    FILE *file = fopen(filepath, "r");
    if (file == NULL) {
        printf("Failed to open file\n");
        return NULL;
    }
    char* file_contents = NULL;
    char* line = NULL;
    size_t length = 0;
    size_t file_length = 0;
    ssize_t return_code = 0;

    while ((return_code = getline(&line, &length, file)) != -1) {
        file_length += return_code;
        
        file_contents = realloc(file_contents, file_length + 1);
        if (file_contents == NULL) {
            printf("Failed to allocate memory\n");
            free(line);
            fclose(file);
        }

        memcpy(file_contents + file_length - return_code, line, return_code);
        file_contents[file_length] = '\0';  // Null-terminate the string
    } 

    fclose(file);
    return file_contents;
}
