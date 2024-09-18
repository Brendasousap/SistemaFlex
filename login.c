#include "login.h"
#include <stdio.h>
#include <string.h>

#define USERNAME "admin"
#define PASSWORD "password123"

int login() {
    char username[50];
    char password[50];
    int attempts = 3;

    while (attempts > 0) {
        printf("Digite o nome de usuário: ");
        scanf("%s", username);
        printf("Digite a senha: ");
        scanf("%s", password);

        if (strcmp(username, USERNAME) == 0 && strcmp(password, PASSWORD) == 0) {
            printf("Login bem-sucedido!\n");
            return 1; // Login com sucesso
        } else {
            attempts--;
            printf("Nome de usuário ou senha incorretos. Restam %d tentativas.\n", attempts);
        }
    }
    return 0; // Falha no login após 3 tentativas
}