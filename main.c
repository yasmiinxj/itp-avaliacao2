
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ESTUDANTES 10
#define MAX_NOME 50
#define NUM_NOTAS 3

void limparEntrada() {
    int c;

    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

int lerQuantidade() {
    int quantidade;

    while (1) {
        printf("Quantidade de estudantes (1 a 10): ");

        if (scanf("%d", &quantidade) != 1) {
            printf("Entrada invalida! Digite um numero inteiro.\n");
            limparEntrada();
            continue;
        }

        limparEntrada();

        if (quantidade >= 1 && quantidade <= MAX_ESTUDANTES) {
            return quantidade;
        }

        printf("A quantidade deve estar entre 1 e 10.\n");
    }
}

void lerNome(char nome[]) {
    while (1) {
        printf("Nome do estudante: ");

        if (fgets(nome, MAX_NOME, stdin) == NULL) {
            nome[0] = '\0';
            continue;
        }

        if (strchr(nome, '\n') == NULL) {
            int c = getchar();

            if (c != '\n' && c != EOF) {
                limparEntrada();
                printf("Nome muito longo! Digite ate 49 caracteres.\n");
                continue;
            }
        }

        nome[strcspn(nome, "\n")] = '\0';

        if (strspn(nome, " \t\r") == strlen(nome)) {
            printf("O nome nao pode ficar vazio.\n");
            continue;
        }

        return;
    }
}

float lerNota(int numero) {
    float nota;

    while (1) {
        printf("Digite a nota %d (0 a 10): ", numero);

        if (scanf("%f", &nota) != 1) {
            printf("Entrada invalida! Digite um numero.\n");
            limparEntrada();
            continue;
        }

        limparEntrada();

        if (nota >= 0 && nota <= 10) {
            return nota;
        }

        printf("Nota invalida! Digite um valor entre 0 e 10.\n");
    }
}

void calcularMedias(float notas[][NUM_NOTAS],
                    float *medias, int quantidade) {
    int i, j;
    float soma;

    for (i = 0; i < quantidade; i++) {
        soma = 0;

        for (j = 0; j < NUM_NOTAS; j++) {
            soma += notas[i][j];
        }

        medias[i] = soma / NUM_NOTAS;
    }
}

void exibirBoletim(char nomes[][MAX_NOME],
                   float notas[][NUM_NOTAS],
                   float medias[], int quantidade) {
    int i;
    float somaMedias = 0;
    float maiorMedia = medias[0];

    printf("\n========== BOLETIM DA TURMA ==========\n");

    for (i = 0; i < quantidade; i++) {
        printf("\nEstudante: %s\n", nomes[i]);
        printf("Notas: %.2f | %.2f | %.2f\n",
               notas[i][0], notas[i][1], notas[i][2]);
        printf("Media: %.2f\n", medias[i]);

        if (medias[i] >= 6) {
            printf("Situacao: Atingiu a meta\n");
        } else {
            printf("Situacao: Abaixo da meta\n");
        }

        somaMedias += medias[i];

        if (medias[i] > maiorMedia) {
            maiorMedia = medias[i];
        }
    }

    printf("\nMedia geral da turma: %.2f\n",
           somaMedias / quantidade);

    printf("Maior media: %.2f\n", maiorMedia);
    printf("Estudante(s) com a maior media:\n");

    for (i = 0; i < quantidade; i++) {
        if (medias[i] == maiorMedia) {
            printf("- %s\n", nomes[i]);
        }
    }
}

int main() {
    int quantidade;
    int i, j;

    char nomes[MAX_ESTUDANTES][MAX_NOME];
    float notas[MAX_ESTUDANTES][NUM_NOTAS];
    float *medias;

    printf("=== BOLETIM DE UMA PEQUENA TURMA ===\n\n");

    quantidade = lerQuantidade();

    medias = malloc(quantidade * sizeof(float));

    if (medias == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    for (i = 0; i < quantidade; i++) {
        printf("\n--- Estudante %d ---\n", i + 1);

        lerNome(nomes[i]);

        for (j = 0; j < NUM_NOTAS; j++) {
            notas[i][j] = lerNota(j + 1);
        }
    }

    calcularMedias(notas, medias, quantidade);

    exibirBoletim(nomes, notas, medias, quantidade);

    free(medias);
    medias = NULL;

    printf("\nPrograma finalizado.\n");

    return 0;
}
