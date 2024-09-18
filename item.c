#include "item.h"
#include "file_ops.h"
#include <stdio.h>
#include <string.h>

#define FILENAME "itens.txt"

void cadastrar_item() {
    char item[100];
    printf("Digite o nome do item: ");
    scanf("%s", item);
    save_item(FILENAME, item);
}

void listar_itens() {
    list_items(FILENAME);
}

void editar_item() {
    char old_item[100], new_item[100];
    printf("Digite o nome do item a ser editado: ");
    scanf("%s", old_item);
    printf("Digite o novo nome do item: ");
    scanf("%s", new_item);
    edit_item(FILENAME, old_item, new_item);
}

void excluir_item() {
    char item[100];
    printf("Digite o nome do item a ser excluído: ");
    scanf("%s", item);
    delete_item(FILENAME, item);
}