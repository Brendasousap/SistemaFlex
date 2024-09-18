#include "file_ops.h"
#include <stdio.h>
#include <string.h>

void save_item(const char *filename, const char *item) {
    FILE *file = fopen(filename, "a");
    if (file != NULL) {
        fprintf(file, "%s\n", item);
        fclose(file);
    } else {
        printf("Erro ao abrir o arquivo.\n");
    }
}

void list_items(const char *filename) {
    FILE *file = fopen(filename, "r");
    char buffer[256];
    if (file != NULL) {
        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            printf("%s", buffer);
        }
        fclose(file);
    } else {
        printf("Erro ao abrir o arquivo.\n");
    }
}

void edit_item(const char *filename, const char *old_item, const char *new_item) {
    FILE *file = fopen(filename, "r");
    FILE *temp_file = fopen("temp.txt", "w");
    char buffer[256];
    if (file != NULL && temp_file != NULL) {
        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            if (strstr(buffer, old_item) == NULL) {
                fputs(buffer, temp_file);
            } else {
                fprintf(temp_file, "%s\n", new_item);
            }
        }
        fclose(file);
        fclose(temp_file);
        remove(filename);
        rename("temp.txt", filename);
    } else {
        printf("Erro ao abrir o arquivo.\n");
    }
}

void delete_item(const char *filename, const char *item) {
    edit_item(filename, item, "");
}