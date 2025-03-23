#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int i = 0;

int main() {
    pid_t r = fork();  // Criação do processo filho

    if (r == 0) {  // Código do processo filho
        sleep(10);  // Pausa de 10 segundos
        printf("%d: %d %d\n", getpid(), i, r);
        return 0;
    }

    i = i + 1;  // Atualiza o valor da variável no processo pai
    wait(NULL);  // Pai espera o término do filho
    printf("%d: %d %d\n", getpid(), i, r);

    return 0;
}


//a) A primeira mensagem a aparecer é a do processo pai, seguida pela do processo filho após 10 segundos.

//b) A impressão da linha 8 é feita antes da linha 14 porque o processo pai continua sua execução enquanto o filho está em pausa.

//c) Sem a linha wait(NULL);, o processo pai pode terminar antes do filho, fazendo com que a impressão do filho não ocorra.