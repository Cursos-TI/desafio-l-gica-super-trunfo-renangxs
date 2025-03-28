#include <stdio.h> 
#include <string.h>

// Estrutura da carta Super Trunfo
struct CartaSuperTrunfo {
    char estado;
    char codigo[5];
    char nomeCidade[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

// Função para calcular atributos derivados
void calcularAtributos(struct CartaSuperTrunfo *carta) {
    if (carta->area > 0)
        carta->densidadePopulacional = carta->populacao / carta->area;
    else
        carta->densidadePopulacional = 0;

    if (carta->populacao > 0)
        carta->pibPerCapita = (carta->pib * 1000000000) / carta->populacao;
    else
        carta->pibPerCapita = 0;
}

// Função para cadastrar uma carta
struct CartaSuperTrunfo lerCarta() {
    struct CartaSuperTrunfo carta;
    printf("Digite o estado (A a H): ");
    scanf(" %c", &carta.estado);
    printf("Digite o código da carta (ex: A01, B03): ");
    scanf("%4s", carta.codigo);
    printf("Digite o nome da cidade: ");
    getchar();
    fgets(carta.nomeCidade, sizeof(carta.nomeCidade), stdin);
    carta.nomeCidade[strcspn(carta.nomeCidade, "\n")] = '\0';
    printf("Digite a população da cidade: ");
    scanf("%lu", &carta.populacao);
    printf("Digite a área da cidade (km²): ");
    scanf("%f", &carta.area);
    printf("Digite o PIB da cidade (bilhões de reais): ");
    scanf("%f", &carta.pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta.pontosTuristicos);
    
    calcularAtributos(&carta);
    return carta;
}

// Função para exibir os dados de uma carta
void exibirCarta(struct CartaSuperTrunfo carta) {
    printf("------------------------------------\n");
    printf("Estado: %c\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Cidade: %s\n", carta.nomeCidade);
    printf("População: %lu\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: R$ %.2f bilhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per capita: R$ %.2f\n", carta.pibPerCapita);
    printf("------------------------------------\n");
}

// Função para comparar duas cartas
void compararCartas(struct CartaSuperTrunfo c1, struct CartaSuperTrunfo c2) {
    printf("\nDados das Cartas:\n");
    exibirCarta(c1);
    exibirCarta(c2);
    
    printf("\nComparacão de Cartas (Atributo: População)\n");
    printf("Carta 1 - %s (%c): %lu\n", c1.nomeCidade, c1.estado, c1.populacao);
    printf("Carta 2 - %s (%c): %lu\n", c2.nomeCidade, c2.estado, c2.populacao);
    
    printf("\nResultado da Comparacão:\n");
    if (c1.populacao > c2.populacao) {
        printf("Carta 1 (%s) venceu!\n", c1.nomeCidade);
    } else if (c2.populacao > c1.populacao) {
        printf("Carta 2 (%s) venceu!\n", c2.nomeCidade);
    } else {
        printf("Resultado: Empate!\n");
    }
}

int main() {
    struct CartaSuperTrunfo carta1, carta2;
    
    printf("Insira os dados da primeira carta:\n");
    carta1 = lerCarta();
    printf("\nInsira os dados da segunda carta:\n");
    carta2 = lerCarta();
    
    compararCartas(carta1, carta2);
    
    return 0;
}
