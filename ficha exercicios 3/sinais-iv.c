#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

// Função que evita processos zombi
void handle_sigchld(int signum) {
    while (waitpid(-1, NULL, WNOHANG) > 0);
}

void fun1(int *d) {
    (*d)++;
    printf("Novo valor gerado: %d\n", *d);
    sleep(2);
}

void fun2(int *d) {
    sleep(1);
    printf("Valor processado: %d\n", *d);
}

int main() {
  printf("1222153 - %s\n", __FILE__);
    int dados = 0;

    // Configurar o sinal SIGCHLD para evitar processos zumbi
    signal(SIGCHLD, handle_sigchld);

    while (1) {
        fun1(&dados);
        pid_t r = fork();

        if (r == -1) {
            perror("fork");
            exit(1);
        }

        if (r == 0) {  // Código do processo filho
            fun2(&dados);
            exit(0);
        }
    }
}

