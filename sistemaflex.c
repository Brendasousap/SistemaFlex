#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define USERNAME "admin"
#define PASSWORD "password123"
#define FILENAME "itens.txt"
#define MAX_EMAILS 10

char registered_emails[MAX_EMAILS][80];
int email_count = 0;

int login() {
    char username[50];
    char password[50];
    int attempts = 3;

    while (attempts > 0) {
        printf("Digite o nome de usuario: ");
        scanf("%s", username);
        printf("Digite a senha: ");
        scanf("%s", password);

        if (strcmp(username, USERNAME) == 0 && strcmp(password, PASSWORD) == 0) {
            printf("Login bem-sucedido!\n");
            return 1; // Login com sucesso
        } else {
            attempts--;
            printf("Nome de usuario ou senha incorretos. Restam %d tentativas.\n", attempts);
        }
    }
    return 0; // Falha no login apos 3 tentativas
}

int is_valid_email(const char *email) {
    int i;
    if (strchr(email, '@') == NULL || strlen(email) >= 80) {
        return 0; // E-mail invalido
    }
    for (i = 0; i < email_count; i++) {
        if (strcmp(email, registered_emails[i]) == 0) {
            return 0; // E-mail ja cadastrado
        }
    }
    strcpy(registered_emails[email_count++], email); // Registrar o e-mail
    return 1; // E-mail valido
}

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

void display_menu() {
    printf("Menu de Opcoes:\n");
    printf("1. Cadastrar Item\n");
    printf("2. Listar Itens\n");
    printf("3. Editar Item\n");
    printf("4. Excluir Item\n");
    printf("5. Sair\n");
}

void handle_menu_option(int option) {
    switch (option) {
        case 1: {
            char item[100];
            printf("Digite o nome do item: ");
            scanf("%s", item);
            save_item(FILENAME, item);
            break;
        }
        case 2:
            list_items(FILENAME);
            break;
        case 3: {
            char old_item[100], new_item[100];
            printf("Digite o nome do item a ser editado: ");
            scanf("%s", old_item);
            printf("Digite o novo nome do item: ");
            scanf("%s", new_item);
            edit_item(FILENAME, old_item, new_item);
            break;
        }
        case 4: {
            char item[100];
            printf("Digite o nome do item a ser excluido: ");
            scanf("%s", item);
            delete_item(FILENAME, item);
            break;
        }
        case 5:
            printf("Saindo do programa...\n");
            break;
        default:
            printf("Opcao invalida.\n");
    }
}

int main() {
    // Realizar login
    if (login() == 1) {
        int option;
        do {
            display_menu();
            printf("Escolha uma opcao: ");
            scanf("%d", &option);
            handle_menu_option(option);
        } while (option != 5); // 5 é a opcao de sair
    } else {
        printf("Login falhou. Encerrando o programa.\n");
    }

    return 0;
}