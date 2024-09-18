#include "email.h"
#include <stdio.h>
#include <string.h>

#define MAX_EMAILS 10
char registered_emails[MAX_EMAILS][80];
int email_count = 0;

int is_valid_email(const char *email) {
    if (strchr(email, '@') == NULL || strlen(email) >= 80) {
        return 0; // E-mail inválido
    }
    for (int i = 0; i < email_count; i++) {
        if (strcmp(email, registered_emails[i]) == 0) {
            return 0; // E-mail já cadastrado
        }
    }
    strcpy(registered_emails[email_count++], email); // Registrar o e-mail
    return 1; // E-mail válido
}