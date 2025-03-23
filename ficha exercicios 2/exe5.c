#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    // Alocar um bloco de 8 bytes na memória
    char *ptr = malloc(8);
    if (ptr == NULL) {
        perror("Erro ao alocar memória");
        exit(1);
    }

    // Guardar a string "pai" no bloco
    strcpy(ptr, "pai");
    printf("Pai: %s\n", ptr);

    // Criar o processo filho
    pid_t r = fork();
    if (r == 0) {  // Código do processo filho
        strcpy(ptr, "filho");
        printf("Filho: %s\n", ptr);
        exit(0);
    }

    // Processo pai espera o filho terminar
    waitpid(r, NULL, 0);
    printf("Pai após o filho: %s\n", ptr);

    // Liberar memória
    free(ptr);
    return 0;
}
