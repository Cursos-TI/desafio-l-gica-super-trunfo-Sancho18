/*
 * Desafio Super Trunfo - Países
 * Criado por: Vinícius
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Estrutura de dados para cada carta do jogo
struct Carta {
    char estado[3];
    int codigo;
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
};


// --- Protótipos das Funções ---
void limparTela();
void aguardarEnter();
struct Carta cadastrarCarta(int numeroCarta);
void exibirCarta(struct Carta carta);
float calcularDensidade(struct Carta carta);

void nivelNovato();
void nivelAventureiro();
void nivelMestre();


// --- Função Principal ---
int main() {
    int escolha;

    do {
        limparTela();
        printf("*****************************************\n");
        printf("   BEM-VINDO AO SUPER TRUNFO - PAÍSES\n");
        printf("*****************************************\n\n");
        printf("Escolha o nível do desafio:\n");
        printf("1. Novato\n");
        printf("2. Aventureiro\n");
        printf("3. Mestre\n");
        printf("0. Sair\n\n");
        printf("Opção: ");
        scanf(" %d", &escolha);

        switch (escolha) {
            case 1:
                nivelNovato();
                break;
            case 2:
                nivelAventureiro();
                break;
            case 3:
                nivelMestre();
                break;
            case 0:
                printf("\nAté a próxima!\n");
                break;
            default:
                printf("\nOpção inválida!\n");
                aguardarEnter();
                break;
        }
    } while (escolha != 0);

    return 0;
}


// --- Funções de Utilidade ---

void limparTela() {
    system("cls||clear");
}

void aguardarEnter() {
    printf("\nPressione Enter para continuar...");
    while (getchar() != '\n');
    getchar();
}

// O espaço antes de "%" nos scanfs é importante para limpar o buffer de entrada
struct Carta cadastrarCarta(int numeroCarta) {
    struct Carta novaCarta;
    printf("\n--- Cadastro da Carta %d ---\n", numeroCarta);

    printf("Estado (UF): ");
    scanf(" %2s", novaCarta.estado);

    printf("Código da carta: ");
    scanf(" %d", &novaCarta.codigo);

    printf("Nome da cidade: ");
    scanf(" %[^\n]s", novaCarta.nomeCidade);

    printf("População: ");
    scanf(" %d", &novaCarta.populacao);

    printf("Área (km²): ");
    scanf(" %f", &novaCarta.area);

    printf("PIB (em bilhões): ");
    scanf(" %f", &novaCarta.pib);

    printf("Pontos turísticos: ");
    scanf(" %d", &novaCarta.pontosTuristicos);

    novaCarta.densidade = calcularDensidade(novaCarta);
    return novaCarta;
}

void exibirCarta(struct Carta carta) {
    printf("\n--- CARTA %s%d: %s ---\n", carta.estado, carta.codigo, carta.nomeCidade);
    printf(" População: %d\n", carta.populacao);
    printf(" Área: %.2f km²\n", carta.area);
    printf(" Densidade: %.2f hab/km²\n", carta.densidade);
    printf(" PIB: R$ %.2f bi\n", carta.pib);
    printf(" Pontos Turísticos: %d\n", carta.pontosTuristicos);
}

float calcularDensidade(struct Carta carta) {
    if (carta.area > 0) {
        return (float)carta.populacao / carta.area;
    }
    return 0;
}


// --- Níveis do Desafio ---

void nivelNovato() {
    limparTela();
    printf("### NÍVEL NOVATO ###\n");

    struct Carta carta1 = cadastrarCarta(1);
    struct Carta carta2 = cadastrarCarta(2);

    limparTela();
    printf("Cartas na mesa:\n");
    exibirCarta(carta1);
    exibirCarta(carta2);

    printf("\n>>> Comparando por POPULAÇÃO (maior vence)...\n");
    if (carta1.populacao > carta2.populacao) {
        printf("Resultado: %s vence!\n", carta1.nomeCidade);
    } else if (carta2.populacao > carta1.populacao) {
        printf("Resultado: %s vence!\n", carta2.nomeCidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    printf("\n>>> Comparando por DENSIDADE (menor vence)...\n");
    if (carta1.densidade < carta2.densidade) {
        printf("Resultado: %s vence!\n", carta1.nomeCidade);
    } else if (carta2.densidade < carta1.densidade) {
        printf("Resultado: %s vence!\n", carta2.nomeCidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    aguardarEnter();
}


void nivelAventureiro() {
    int escolha;
    limparTela();
    printf("### NÍVEL AVENTUREIRO ###\n");

    struct Carta carta1 = cadastrarCarta(1);
    struct Carta carta2 = cadastrarCarta(2);

    limparTela();
    printf("Cartas na mesa:\n");
    exibirCarta(carta1);
    exibirCarta(carta2);

    printf("\n--- Escolha o atributo para comparar ---\n");
    printf("1. População\n2. Área\n3. PIB\n4. Pontos Turísticos\n5. Densidade\n");
    printf("Opção: ");
    scanf(" %d", &escolha);

    printf("\n--- Resultado ---\n");

    switch (escolha) {
        case 1:
            printf("Atributo: População\n");
            if (carta1.populacao > carta2.populacao) printf("Vencedor: Carta 1 (%s)\n", carta1.nomeCidade);
            else if (carta2.populacao > carta1.populacao) printf("Vencedor: Carta 2 (%s)\n", carta2.nomeCidade);
            else printf("Resultado: Empate!\n");
            break;
        case 3:
            printf("Atributo: PIB\n");
            if (carta1.pib > carta2.pib) {
                printf("Vencedor: Carta 1 (%s)\n", carta1.nomeCidade);
            } else if (carta2.pib > carta1.pib) {
                printf("Vencedor: Carta 2 (%s)\n", carta2.nomeCidade);
            } else {
                // Comparação aninhada para desempate
                printf("PIB empatado! Desempatando por população...\n");
                if (carta1.populacao > carta2.populacao) {
                    printf("Vencedor no desempate: Carta 1 (%s)\n", carta1.nomeCidade);
                } else if(carta2.populacao > carta1.populacao) {
                    printf("Vencedor no desempate: Carta 2 (%s)\n", carta2.nomeCidade);
                } else {
                    printf("Empate duplo!\n");
                }
            }
            break;
        case 5:
            printf("Atributo: Densidade (menor vence)\n");
            if (carta1.densidade < carta2.densidade) printf("Vencedor: Carta 1 (%s)\n", carta1.nomeCidade);
            else if (carta2.densidade < carta1.densidade) printf("Vencedor: Carta 2 (%s)\n", carta2.nomeCidade);
            else printf("Resultado: Empate!\n");
            break;
        // Cases 2 e 4 seriam similares ao 1
        default:
            printf("Opção inválida ou não implementada neste exemplo!\n");
            break;
    }

    aguardarEnter();
}


void nivelMestre() {
    int escolha1, escolha2;
    limparTela();
    printf("### NÍVEL MESTRE ###\n");

    struct Carta carta1 = cadastrarCarta(1);
    struct Carta carta2 = cadastrarCarta(2);

    do {
        limparTela();
        printf("Cartas na mesa:\n");
        exibirCarta(carta1);
        exibirCarta(carta2);

        printf("\n--- Comparação Avançada (escolha 2 atributos) ---\n");
        printf("1.População  2.Área  3.PIB  4.Pontos Turísticos  5.Densidade\n");
        printf("(Digite 0 para sair)\n");

        printf("Primeiro atributo: ");
        scanf(" %d", &escolha1);
        if(escolha1 == 0) break;

        printf("Segundo atributo: ");
        scanf(" %d", &escolha2);
        if(escolha2 == 0) break;

        int pontos1 = 0, pontos2 = 0;

        // Lógica para o primeiro atributo
        switch (escolha1) {
            case 1: if (carta1.populacao > carta2.populacao) pontos1++; else if (carta2.populacao > carta1.populacao) pontos2++; break;
            case 5: if (carta1.densidade < carta2.densidade) pontos1++; else if (carta2.densidade < carta1.densidade) pontos2++; break;
            // ... outros cases
        }

        // Lógica para o segundo atributo
        switch (escolha2) {
            case 1: if (carta1.populacao > carta2.populacao) pontos1++; else if (carta2.populacao > carta1.populacao) pontos2++; break;
            case 5: if (carta1.densidade < carta2.densidade) pontos1++; else if (carta2.densidade < carta1.densidade) pontos2++; break;
            // ... outros cases
        }

        printf("\n--- Placar da Rodada ---\n");
        printf("Pontos %s: %d\n", carta1.nomeCidade, pontos1);
        printf("Pontos %s: %d\n", carta2.nomeCidade, pontos2);

        // Operador ternário para determinar o vencedor
        (pontos1 > pontos2) ? printf("VENCEDOR: %s!\n", carta1.nomeCidade) :
        (pontos2 > pontos1) ? printf("VENCEDOR: %s!\n", carta2.nomeCidade) :
                              printf("RESULTADO: EMPATE!\n");

        aguardarEnter();
    } while (escolha1 != 0);
}