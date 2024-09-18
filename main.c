#include <stdio.h>
#include "login.h"
#include "menu.h"

int main() {
    // Realizar login
    if (login() == 1) {
        int option;
        do {
            display_menu();
            printf("Escolha uma opção: ");
            scanf("%d", &option);
            handle_menu_option(option);
        } while (option != 5); // 5 é a opção de sair
    } else {
        printf("Login falhou. Encerrando o programa.\n");
    }

    return 0;
}
