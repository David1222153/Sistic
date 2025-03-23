#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    pid_t r;

    printf("\nProcesso %d a executar %s\n\n", getpid(), argv[0]);

    r = fork(); // Criação do processo filho

    printf("Valor de retorno da função fork para o processo %d: %d\n\n", getpid(), r);

    if (r == 0) { // Código do processo filho
        for (int i = 0; i < 10; ++i) {
            sleep(1);
            printf("Novo processo, com PID = %d (\"filho\" de %d)\n", getpid(), getppid());
        }
        exit(0);
    }

    // Código do processo pai
    for (int i = 0; i < 10; ++i) {
        sleep(2);
        printf("Processo inicial (PID = %d, \"filho\" de %d).\n", getpid(), getppid());
    }

    return 0;
}


//a) Ambos os ciclos for são executados em simultâneo porque o fork() cria um processo filho que é uma cópia do processo pai e ambos continuam a partir da linha seguinte ao fork().

//b) No processo pai, o valor de retorno da função fork() é o PID do processo filho. Isso significa que o processo pai pode identificar e gerenciar o filho.

//c) O printf() da linha 13 é executado duas vezes porque ambos os processos (pai e filho) continuam a execução após o fork(), imprimindo a mesma mensagem.

//d) O processo pai do programa é o interpretador de comandos (shell). Podemos verificar isso com o comando:

//ps j


//e) Sem a instrução exit(0);, o processo filho continua a executar as instruções seguintes ao bloco if, o que resulta em saídas duplicadas.