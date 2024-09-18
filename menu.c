#include "menu.h"
#include <stdio.h>
#include "item.h"

void display_menu() {
    printf("Menu de Opções:\n");
    printf("1. Cadastrar Item\n");
    printf("2. Listar Itens\n");
    printf("3. Editar Item\n");
    printf("4. Excluir Item\n");
    printf("5. Sair\n");
}

void handle_menu_option(int option) {
    switch (option) {
        case 1:
            cadastrar_item();
            break;
        case 2:
            listar_itens();
            break;
        case 3:
            editar_item();
            break;
        case 4:
            excluir_item();
            break;
        case 5:
            printf("Saindo do programa...\n");
            break;
        default:
            printf("Opção inválida.\n");
    }
}