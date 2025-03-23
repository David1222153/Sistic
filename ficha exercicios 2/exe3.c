#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define NELEM 20  // Número de elementos no vetor

int main() {
    double *dados;
    pid_t r1, r2;

    // Alocar memória para o vetor
    dados = malloc(NELEM * sizeof(double));
    if (dados == NULL) {
        perror("Erro ao alocar memória");
        exit(1);
    }

    // Inicializar o vetor com valores de 0 a 19
    for (int i = 0; i < NELEM; ++i) {
        dados[i] = i;
    }

    // Criar o primeiro processo filho
    r1 = fork();
    if (r1 == 0) {  // Código do processo filho 1
        for (int i = 0; i < NELEM / 2; ++i) {
            dados[i] *= 2.0;  // Multiplicar os primeiros elementos por 2
        }
        exit(0);
    }

    // Criar o segundo processo filho
    r2 = fork();
    if (r2 == 0) {  // Código do processo filho 2
        for (int i = NELEM / 2; i < NELEM; ++i) {
            dados[i] *= 2.0;  // Multiplicar os últimos elementos por 2
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
    

    // Liberar memória alocada
    free(dados);
    return 0;
}

//O vetor dados mantém os valores iniciais porque cada processo filho possui uma cópia própria da memória do processo pai. As alterações feitas pelos filhos não afetam a memória do pai.


