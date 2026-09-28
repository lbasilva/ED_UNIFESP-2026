#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int quantidade; 
    double *numeros; 

    printf("Quantos números na sua série (N): ");
    scanf("%d", &quantidade);

    // 1. Alocação dinâmica da memória para N números
    numeros = (double *) malloc(quantidade * sizeof(double));

    // verifica se a alocação funcionou
    if (numeros == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    printf("Entre com números:\n");

    // 2. Loop com o scanf para preencher o vetor
    for (int i = 0; i < quantidade; i++) {
        printf("> ");
        scanf("%lf", &numeros[i]);
    }

    // A partir daqui os cálculos do máximo, mínimo, média, etc.
    double maximo = numeros[0];
    double minimo = numeros[0];
    double soma = 0.0;

    for (int i = 0; i < quantidade; i++) {
    // Acumula a soma de todos os elementos
        soma += numeros[i];

    // Atualiza o máximo
        if (numeros[i] > maximo) {
            maximo = numeros[i];
        }
    // Atualiza o mínimo
        if (numeros[i] < minimo) {
            minimo = numeros[i];
        }
    }

    // Cálculo da média 
    double media = soma / quantidade;

    // Cálculo do desvio padrão
    double soma_diferencas = 0.0;
    for (int i = 0; i < quantidade; i++) {
        double diferenca = numeros[i] - media;
        soma_diferencas += diferenca * diferenca;
    }

    double variancia = soma_diferencas / quantidade;
    double desvio_padrao = sqrt(variancia);

    // Bubble sort para ordenar o vetor e encontrar a mediana
    for (int i = 0; i < quantidade - 1; i++) {
        for (int j = 0; j < quantidade - 1 - i; j++) {
            if (numeros[j] > numeros[j + 1]) {
                double temp = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temp;
            }
        }
    }

    // Cálculo da mediana                                                       
    double mediana;
    if (quantidade % 2 != 0) {
        mediana = numeros[quantidade / 2];
    } else {
        mediana = (numeros[(quantidade / 2) - 1] + numeros[quantidade / 2]) / 2.0;
    }

    // Resultados
    printf("Valor mínimo: %g\n", minimo);
    printf("Valor Máximo: %g\n", maximo);
    printf("Média: %.2f\n", media);
    printf("Mediana: %.2f\n", mediana);
    printf("Desvio Padrão: %.14lf\n", desvio_padrao);

    // Liberação da memória alocada
    free(numeros);

    return 0;
}