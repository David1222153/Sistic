#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void wait_something();
void do_something();
void myHandler(int);

int main() {
  printf("1222153 - %s\n", __FILE__);
    // Bloquear SIGINT e SIGQUIT no processo principal
    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGINT);
    sigaddset(&mask, SIGQUIT);
    sigprocmask(SIG_BLOCK, &mask, NULL);

    // Ignorar SIGTERM em todos os processos
    signal(SIGTERM, SIG_IGN);

    // Definir handler para SIGCHLD no processo inicial
    signal(SIGCHLD, myHandler);

    while(1) {
        wait_something();
        pid_t r = fork();
        
        if (r == -1) {
          perror("Erro ao criar processo");
          exit(1);
      }

        if (r == 0) {  // Processo filho
            // Bloquear SIGTSTP apenas no filho
            sigset_t child_mask;
            sigemptyset(&child_mask);
            sigaddset(&child_mask, SIGTSTP);
            sigprocmask(SIG_BLOCK, &child_mask, NULL);

            // Restaurar SIGCHLD para o comportamento padrão no filho
            signal(SIGCHLD, SIG_DFL);

            do_something();
            return 0;
        }
    }
    return 0;
}

void wait_something() {
    sleep(1);
}

void do_something() {
    sleep(1);
}

// Handler para SIGCHLD no processo pai
void myHandler(int signum) {
    int wstatus;
    wait(&wstatus);
    if (WIFSIGNALED(wstatus)) {
        printf("Child terminated by signal %d\n", WTERMSIG(wstatus));
    }
}
