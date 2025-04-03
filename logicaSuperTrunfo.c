
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

// Função para comparar duas cartas com base no atributo escolhido pelo usuário
void compararCartas(struct CartaSuperTrunfo c1, struct CartaSuperTrunfo c2, int opcao) {
    float valor1, valor2;
    printf("\nComparação entre %s e %s\n", c1.nomeCidade, c2.nomeCidade);
    
    switch (opcao) {
        case 1: // População
            valor1 = c1.populacao;
            valor2 = c2.populacao;
            break;
        case 2: // Área
            valor1 = c1.area;
            valor2 = c2.area;
            break;
        case 3: // PIB
            valor1 = c1.pib;
            valor2 = c2.pib;
            break;
        case 4: // Pontos Turísticos
            valor1 = c1.pontosTuristicos;
            valor2 = c2.pontosTuristicos;
            break;
        case 5: // Densidade Populacional (Critério invertido)
            valor1 = c1.densidadePopulacional;
            valor2 = c2.densidadePopulacional;
            printf("(Critério invertido: menor valor vence)\n");
            break;
        default:
            printf("Opção inválida!\n");
            return;
    }
    
    printf("%s: %.2f\n", c1.nomeCidade, valor1);
    printf("%s: %.2f\n", c2.nomeCidade, valor2);
    
    if (opcao == 5) {
        if (valor1 < valor2) {
            printf("%s venceu!\n", c1.nomeCidade);
        } else if (valor2 < valor1) {
            printf("%s venceu!\n", c2.nomeCidade);
        } else {
            printf("Empate!\n");
        }
    } else {
        if (valor1 > valor2) {
            printf("%s venceu!\n", c1.nomeCidade);
        } else if (valor2 > valor1) {
            printf("%s venceu!\n", c2.nomeCidade);
        } else {
            printf("Empate!\n");
        }
    }
}

int main() {
    struct CartaSuperTrunfo carta1, carta2;
    int opcao;
    
    printf("Insira os dados da primeira carta:\n");
    carta1 = lerCarta();
    printf("\nInsira os dados da segunda carta:\n");
    carta2 = lerCarta();
    
    do {
        printf("\nEscolha o atributo para comparar:\n");
        printf("1 - População\n");
        printf("2 - Área\n");
        printf("3 - PIB\n");
        printf("4 - Pontos Turísticos\n");
        printf("5 - Densidade Populacional (menor valor vence)\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        
        if (opcao != 0) {
            compararCartas(carta1, carta2, opcao);
        }
    } while (opcao != 0);
    
    printf("Encerrando o jogo...\n");
    return 0;
}
