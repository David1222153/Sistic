#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>

#define NELEM 20  // Número de elementos no vetor

// Função para alocação de memória partilhada
void *shmalloc(size_t size) {
    return mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
}

int main() {
    // Alocar memória partilhada
    double *dados = shmalloc(NELEM * sizeof(double));
    pid_t r1, r2;

    // Inicializar o vetor com valores de 0 a 19
    for (int i = 0; i < NELEM; ++i) {
        dados[i] = i;
    }

    // Criar o primeiro processo filho
    r1 = fork();
    if (r1 == 0) {
        for (int i = 0; i < NELEM / 2; ++i) {
            dados[i] *= 2.0;
        }
        exit(0);
    }

    // Criar o segundo processo filho
    r2 = fork();
    if (r2 == 0) {
        for (int i = NELEM / 2; i < NELEM; ++i) {
            dados[i] *= 2.0;
        }
        exit(0);
    }

    // Esperar ambos os filhos terminarem
    waitpid(r1, NULL, 0);
    waitpid(r2, NULL, 0);

    // Imprimir os valores do vetor
    for (int i = 0; i < NELEM; ++i) {
        printf("%f ", dados[i]);
        printf("\n");
    }
    

    return 0;
}
