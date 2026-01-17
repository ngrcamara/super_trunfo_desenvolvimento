//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    //declaracao e inicializacao de variaveis...
    char estado1 = '\0';
    char codigo_carta1[4] = "";
    char nome_cidade1[100] = "";
    unsigned long int populacao1 = 0;
    float area1 = 0.0;
    float pib1 = 0.0;
    int pontos_turisticos1 = 0;
    float dens_pop1 = 0;
    float pib_percapita1 = 0;
    float super_poder1 = 0;

    char estado2 = '\0';
    char codigo_carta2[4] = "";
    char nome_cidade2[100] = "";
    unsigned long int populacao2 = 0;
    float area2 = 0.0;
    float pib2 = 0.0;
    int pontos_turisticos2 = 0;
    float dens_pop2 = 0;
    float pib_percapita2 = 0;
    float super_poder2 = 0;

    //leitura dos dados...
    printf("Informe os dados da carta 1:\n");
    printf("Estado: \n");
    scanf("%c", &estado1);
    printf("Código da Carta: \n");
    scanf("%s", codigo_carta1);
    printf("Nome da Cidade: \n");
    scanf("%*c"); //descarta o newline anterior, senao pula o fgets
    fgets(nome_cidade1, 100, stdin);
    nome_cidade1[strcspn(nome_cidade1, "\n")] = 0;
    printf("População: \n");
    scanf("%ul", &populacao1);
    printf("Area: \n");
    scanf("%f", &area1);
    printf("PIB (em bilhoes de reais): \n");
    scanf("%f", &pib1);
    printf("Número de Pontos Turísticos: \n");
    scanf("%d", &pontos_turisticos1);
    dens_pop1 = populacao1 / area1;
    pib_percapita1 = (pib1 * 1000000000) / populacao1;
    printf("\n");

    scanf("%*c"); //descarta o newline anterior, senao pula o fgets
    printf("Informe os dados da carta 2:\n");
    printf("Estado: \n");
    scanf("%c", &estado2);
    printf("Código da Carta: \n");
    scanf("%s", codigo_carta2);
    printf("Nome da Cidade: \n");
    scanf("%*c"); //descarta o newline anterior, senao pula o fgets
    fgets(nome_cidade2, 100, stdin);
    nome_cidade2[strcspn(nome_cidade2, "\n")] = 0;
    printf("População: \n");
    scanf("%ul", &populacao2);
    printf("Area: \n");
    scanf("%f", &area2);
    printf("PIB (em bilhoes de reais): \n");
    scanf("%f", &pib2);
    printf("Número de Pontos Turísticos: \n");
    scanf("%d", &pontos_turisticos2);

    //calcula os indices...
    dens_pop1 = populacao1 / area1;
    pib_percapita1 = (pib1 * 1000000000) / populacao1;
    super_poder1 = (float)populacao1 + area1 + pib1 + (float)pontos_turisticos1 + pib_percapita1 + (1.0 / dens_pop1);

    dens_pop2 = populacao2 / area2;
    pib_percapita2 = (pib2 * 1000000000) / populacao2;
    super_poder2 = (float)populacao2 + area2 + pib2 + (float)pontos_turisticos2 + pib_percapita2 + (1.0 / dens_pop2);
    printf("\n\n");

    //exibicao dos dados...
    printf("Carta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Código da Carta: %s\n", codigo_carta1);
    printf("Nome da Cidade: %s\n", nome_cidade1);
    printf("População: %ul\n", populacao1);
    printf("Area: %.2f km2\n", area1);
    printf("PIB: %.2f bilhoes de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos1);
    printf("Densidade Populacional: %.2f hab/km2\n", dens_pop1);
    printf("PIB per Capita: %.2f reais\n", pib_percapita1);
    printf("Super Poder: %.2f\n", super_poder1);
    printf("\n");

    printf("Carta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Código da Carta: %s\n", codigo_carta2);
    printf("Nome da Cidade: %s\n", nome_cidade2);
    printf("População: %ul\n", populacao2);
    printf("Area: %.2f km2\n", area2);
    printf("PIB: %.2f bilhoes de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos2);
    printf("Densidade Populacional: %.2f hab/km2\n", dens_pop2);
    printf("PIB per Capita: %.2f reais\n", pib_percapita2);
    printf("Super Poder: %.2f\n", super_poder2);
    printf("\n");

    //menu interativo...
    //apresenta e le as opcoes...
    int opcao1 = 0;
    int opcao2 = 0;
    printf("MENU INTERATIVO\n"); 
    printf("Selecione o primeiro atributo a ser comparado...\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Opção 1: ");
    scanf("%d", &opcao1);

    printf("Selecione o segundo atributo a ser comparado...\n");
    if (opcao1 != 1) {
        printf("1 - População\n");
    }
    if (opcao1 != 2) {
        printf("2 - Área\n");
    }
    if (opcao1 != 3) {
        printf("3 - PIB\n");
    }
    if (opcao1 != 4) {
        printf("4 - Número de Pontos Turísticos\n");
    }
    if (opcao1 != 5) {
        printf("5 - Densidade Demográfica\n");
    }
    printf("Opção 2: ");
    scanf("%d", &opcao2);


    //avalia a validade das opcoes selecionadas...
    if ((opcao1 < 1) || (opcao1 > 5)) {
        printf("Erro! Opcao 1 inválida!");
        exit(1);
    }
    if ((opcao2 < 1) || (opcao2 > 5)) {
        printf("Erro! Opcao 2 inválida!");
        exit(1);
    }
    if (opcao1 == opcao2) {
        printf("Erro! Opcao 1 não pode ser igual a opção 2!");
        exit(1);
    }

    // compara os atributos...
    printf("Nome Cidade Carta 1: %s\n", nome_cidade1);
    printf("Nome Cidade Carta 2: %s\n", nome_cidade2);
    float soma1 = 0;
    float soma2 = 0;
    switch (opcao1) {
        case 1:
            printf("Atributo de Comparacao 1: Populacao\n");
            printf("Valor do atributo 1 para a carta 1: %l\n", populacao1);
            printf("Valor do atributo 1 para a carta 2: %l\n", populacao2);
            soma1 += populacao1;
            soma2 += populacao2;
            switch (opcao2) {
                case 2:
                    printf("Atributo de Comparacao 2: Area\n");
                    printf("Valor do atributo 2 para a carta 1: %.2f\n", area1);
                    printf("Valor do atributo 2 para a carta 2: %.2f\n", area2);
                    soma1 += area1;
                    soma2 += area2;
                    break;
                case 3:
                    printf("Atributo de Comparacao 2: PIB\n");
                    printf("Valor do atributo 2 para a carta 1: %.2f\n", pib1);
                    printf("Valor do atributo 2 para a carta 2: %.2f\n", pib2);
                    soma1 += pib1;
                    soma2 += pib2;
                    break;
                case 4:
                    printf("Atributo de Comparacao 2: Pontos Turisticos\n");
                    printf("Valor do atributo 2 para a carta 1: %d\n", pontos_turisticos1);
                    printf("Valor do atributo 2 para a carta 2: %d\n", pontos_turisticos2);
                    soma1 += pontos_turisticos1;
                    soma2 += pontos_turisticos2;
                    break;
                case 5:
                    printf("Atributo de Comparacao 2: Densidade Demografica\n");
                    printf("Valor do atributo 2 para a carta 1: %.2f\n", dens_pop1);
                    printf("Valor do atributo 2 para a carta 2: %.2f\n", dens_pop2);
                    soma1 += (1/dens_pop1);
                    soma2 += (1/dens_pop2);
                    break;
            }
            break;
        case 2:
            printf("Atributo de Comparacao 1: Area\n");
            printf("Valor do atributo 1 para a carta 1: %.2f\n", area1);
            printf("Valor do atributo 1 para a carta 2: %.2f\n", area2);
            soma1 += area1;
            soma2 += area2;
            switch (opcao2) {
            case 1:
                printf("Atributo de Comparacao 2: Populacao\n");
                printf("Valor do atributo 2 para a carta 1: %l\n", populacao1);
                printf("Valor do atributo 2 para a carta 2: %l\n", populacao2);
                soma1 += populacao1;
                soma2 += populacao2;
                break;
            case 3:
                printf("Atributo de Comparacao 2: PIB\n");
                printf("Valor do atributo 2 para a carta 1: %.2f\n", pib1);
                printf("Valor do atributo 2 para a carta 2: %.2f\n", pib2);
                soma1 += pib1;
                soma2 += pib2;
                break;
            case 4:
                printf("Atributo de Comparacao 2: Pontos Turisticos\n");
                printf("Valor do atributo 2 para a carta 1: %d\n", pontos_turisticos1);
                printf("Valor do atributo 2 para a carta 2: %d\n", pontos_turisticos2);
                soma1 += pontos_turisticos1;
                soma2 += pontos_turisticos2;
                break;
            case 5:
                printf("Atributo de Comparacao 2: Densidade Demografica\n");
                printf("Valor do atributo 2 para a carta 1: %.2f\n", dens_pop1);
                printf("Valor do atributo 2 para a carta 2: %.2f\n", dens_pop2);
                soma1 += (1/dens_pop1);
                soma2 += (1/dens_pop2);
                break;
            }
            break;
        case 3:
            printf("Atributo de Comparacao 1: PIB\n");
            printf("Valor do atributo 1 para a carta 1: %.2f\n", pib1);
            printf("Valor do atributo 1 para a carta 2: %.2f\n", pib2);
            soma1 += pib1;
            soma2 += pib2;
            switch (opcao2) {
            case 1:
                printf("Atributo de Comparacao 2: Populacao\n");
                printf("Valor do atributo 2 para a carta 1: %l\n", populacao1);
                printf("Valor do atributo 2 para a carta 2: %l\n", populacao2);
                soma1 += populacao1;
                soma2 += populacao2;
                break;
            case 2:
                printf("Atributo de Comparacao 2: Area\n");
                printf("Valor do atributo 2 para a carta 1: %.2f\n", area1);
                printf("Valor do atributo 2 para a carta 2: %.2f\n", area2);
                soma1 += area1;
                soma2 += area2;
                break;
            case 4:
                printf("Atributo de Comparacao 2: Pontos Turisticos\n");
                printf("Valor do atributo 2 para a carta 1: %d\n", pontos_turisticos1);
                printf("Valor do atributo 2 para a carta 2: %d\n", pontos_turisticos2);
                soma1 += pontos_turisticos1;
                soma2 += pontos_turisticos2;
                break;
            case 5:
                printf("Atributo de Comparacao 2: Densidade Demografica\n");
                printf("Valor do atributo 2 para a carta 1: %.2f\n", dens_pop1);
                printf("Valor do atributo 2 para a carta 2: %.2f\n", dens_pop2);
                soma1 += (1 / dens_pop1);
                soma2 += (1 / dens_pop2);
                break;
            }
            break;
        case 4:
            printf("Atributo de Comparacao 1: Numero de Pontos Turisticos\n");
            printf("Valor do atributo 1 para a carta 1: %.2f\n", pontos_turisticos1);
            printf("Valor do atributo 1 para a carta 2: %.2f\n", pontos_turisticos2);
            soma1 += pontos_turisticos1;
            soma2 += pontos_turisticos2;
            switch (opcao2) {
            case 1:
                printf("Atributo de Comparacao 2: Populacao\n");
                printf("Valor do atributo 2 para a carta 1: %l\n", populacao1);
                printf("Valor do atributo 2 para a carta 2: %l\n", populacao2);
                soma1 += populacao1;
                soma2 += populacao2;
                break;
            case 2:
                printf("Atributo de Comparacao 2: Area\n");
                printf("Valor do atributo 2 para a carta 1: %.2f\n", area1);
                printf("Valor do atributo 2 para a carta 2: %.2f\n", area2);
                soma1 += area1;
                soma2 += area2;
                break;
            case 3:
                printf("Atributo de Comparacao 2: PIB\n");
                printf("Valor do atributo 2 para a carta 1: %d\n", pib1);
                printf("Valor do atributo 2 para a carta 2: %d\n", pib2);
                soma1 += pib1;
                soma2 += pib2;
                break;
            case 5:
                printf("Atributo de Comparacao 2: Densidade Demografica\n");
                printf("Valor do atributo 2 para a carta 1: %.2f\n", dens_pop1);
                printf("Valor do atributo 2 para a carta 2: %.2f\n", dens_pop2);
                soma1 += (1 / dens_pop1);
                soma2 += (1 / dens_pop2);
                break;
            }
            break;
        case 5:
            printf("Atributo de Comparacao 1: Densidade Demografica\n");
            printf("Valor do atributo 1 para a carta 1: %d\n", dens_pop1);
            printf("Valor do atributo 1 para a carta 2: %d\n", dens_pop2);
            soma1 += (1/dens_pop1);
            soma2 += (1/dens_pop2);
            switch (opcao2) {
            case 1:
                printf("Atributo de Comparacao 2: Populacao\n");
                printf("Valor do atributo 2 para a carta 1: %l\n", populacao1);
                printf("Valor do atributo 2 para a carta 2: %l\n", populacao2);
                soma1 += populacao1;
                soma2 += populacao2;
                break;
            case 2:
                printf("Atributo de Comparacao 2: Area\n");
                printf("Valor do atributo 2 para a carta 1: %.2f\n", area1);
                printf("Valor do atributo 2 para a carta 2: %.2f\n", area2);
                soma1 += area1;
                soma2 += area2;
                break;
            case 3:
                printf("Atributo de Comparacao 2: PIB\n");
                printf("Valor do atributo 2 para a carta 1: %.2f\n", pib1);
                printf("Valor do atributo 2 para a carta 2: %.2f\n", pib2);
                soma1 += pib1;
                soma2 += pib2;
                break;
            case 4:
                printf("Atributo de Comparacao 2: Pontos Turisticos\n");
                printf("Valor do atributo 2 para a carta 1: %d\n", pontos_turisticos1);
                printf("Valor do atributo 2 para a carta 2: %d\n", pontos_turisticos2);
                soma1 += pontos_turisticos1;
                soma2 += pontos_turisticos2;
                break;
            }
            break;

    }
    printf("Soma dos atributos para carta 1: %f\n", soma1);
    printf("Soma dos atributos para carta 2: %f\n", soma2);
    if (soma1 > soma2) {
        printf("Carta 1 Venceu!\n");
    }
    else if (soma2 > soma1) {
        printf("Carta 2 Venceu!\n");
    }
    else {
        printf("Empate!");
    }

    return 0;
}
