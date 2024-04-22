#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "megasena.h"

void titulo()
{
    printf("-------------------------------------------\n");
    printf("   Bem-Vindo(a) ao Simulador Megasena\n");
    printf("-------------------------------------------\n");
}

int volante_dezenas()
{
    int quantidade_dezenas;

    do 
    {
        printf ("\nQuantas dezenas voce quer apostar?(6 a 15): ");
        scanf("%i", &quantidade_dezenas);
        if (quantidade_dezenas < 6 || quantidade_dezenas > 15)
        {
            printf("Por favor, apenas de 6 a 15 dezenas\n");
        }
    } while (quantidade_dezenas < 6 || quantidade_dezenas > 15);

    return quantidade_dezenas;
}

void volante_QuantidadeApostasManuais(int quantidade_ApostasManuais, int quantidade_dezenas, int apostas[][15]) 
{
    for (int i = 0; i < quantidade_ApostasManuais; i++) 
    {
        printf("\nAposta manual %d:\n", i + 1);

        // Lógica para obter e validar as dezenas da aposta manual de acordo com quantidade_dezenas
        for (int j = 0; j < quantidade_dezenas; j++) 
        {
            printf("Digite a dezena %d (entre 1 e 60): ", j + 1);
            scanf("%d", &apostas[i][j]);

            // Validação se a dezena está dentro do intervalo permitido
            if (apostas[i][j] < 1 || apostas[i][j] > 60) 
            {
                printf("Dezena invalida. Digite novamente.\n");
                j--; // Volta para pedir a dezena novamente
            } else 
            {
                // Validação se a dezena já foi escolhida anteriormente na mesma aposta
                for (int k = 0; k < j; k++) 
                {
                    if (apostas[i][j] == apostas[i][k]) 
                    {
                        printf("Dezena repetida. Digite novamente.\n");
                        j--; // Volta para pedir a dezena novamente
                        break;
                    }
                }
            }
        }
    }
}

void gerar_Surpresinhas(int quantidade_Surpresinhas, int quantidade_dezenas, int surpresinhas[][15]) 
{
    srand(time(NULL)); // Inicializa números aleatórios

    for (int i = 0; i < quantidade_Surpresinhas; i++) 
    {
        // Inicializa a matriz de surpresinhas com zeros
        for (int j = 0; j < quantidade_dezenas; j++) 
        {
            surpresinhas[i][j] = 0;
        }

        // Gera as dezenas aleatórias para a surpresinha
        for (int j = 0; j < quantidade_dezenas; j++) 
        {
            int dezena;
            int repetida;

            do 
            {
                dezena = rand() % 60 + 1;
                repetida = 0;

                // Verifica se a dezena já foi gerada anteriormente na mesma surpresinha
                for (int k = 0; k < j; k++) 
                {
                    if (dezena == surpresinhas[i][k]) 
                    {
                        repetida = 1;
                        break;
                    }
                }
            } while (repetida);

            surpresinhas[i][j] = dezena;
        }
    }
}


int quantidade_Teimosinha() 
{
    int quantidade_teimosinha;
    do 
    {
        printf("\nQuantas teimosinhas voce deseja fazer? (0, 2 ou 8): ");
        scanf("%d", &quantidade_teimosinha);
    } while (quantidade_teimosinha != 0 && quantidade_teimosinha != 2 && quantidade_teimosinha != 8);

    return quantidade_teimosinha;
}

void mostrar_Surpresinhas(int quantidade_Surpresinhas, int quantidade_dezenas, int surpresinhas[][15]) 
{
    printf("\nSurpresinhas:\n");
    for (int i = 0; i < quantidade_Surpresinhas; i++) 
    {
        printf("Surpresinha %d: ", i + 1);
        for (int j = 0; j < quantidade_dezenas; j++) 
        {
            printf("%d ", surpresinhas[i][j]);
        }
        printf("\n");
    }
}

void mostrar_ApostasManuais(int quantidade_ApostasManuais, int quantidade_dezenas, int apostas[][15]) 
{
    printf("\nApostas Manuais:\n");
    for (int i = 0; i < quantidade_ApostasManuais; i++) 
    {
        printf("Aposta manual %d: ", i + 1);
        for (int j = 0; j < quantidade_dezenas; j++) 
        {
            printf("%d ", apostas[i][j]);
        }
        printf("\n");
    }
}

float calcular_ValorDezenas(int quantidade_dezenas) 
{
    float valor_dezenas = 0.0;

    switch (quantidade_dezenas) 
    {
        case 6:
            valor_dezenas = 5.00;
            break;
        case 7:
            valor_dezenas = 35.00;
            break;
        case 8:
            valor_dezenas = 140.00;
            break;
        case 9:
            valor_dezenas = 420.00;
            break;
        case 10:
            valor_dezenas = 1050.00;
            break;
        case 11:
            valor_dezenas = 2310.00;
            break;
        case 12:
            valor_dezenas = 4620.00;
            break;
        case 13:
            valor_dezenas = 8580.00;
            break;
        case 14:
            valor_dezenas = 15015.00;
            break;
        case 15:
            valor_dezenas = 25025.00;
            break;
        default:
            printf("Quantidade de dezenas invalida.\n");
            break;
    }

    return valor_dezenas;
}

float calcular_ValorTotal(int quantidade_teimosinha, float valor_dezenas, int quantidade_ApostasManuais, int quantidade_Surpresinhas) 
{
    if (quantidade_teimosinha > 0)
    {
        float valor_total = quantidade_teimosinha * (valor_dezenas * (quantidade_ApostasManuais + quantidade_Surpresinhas));
        return valor_total;
    } else
    {
        float valor_total = (valor_dezenas * (quantidade_ApostasManuais + quantidade_Surpresinhas));
        return valor_total;
    }
}

void realizar_Sorteio(int quantidade_teimosinha, int sorteios[][6]) {
    srand(time(NULL)); // Inicializa a semente para números aleatórios

    for (int i = 0; i < quantidade_teimosinha + 1; i++) {
        int numeros_sorteados[60] = {0}; // Inicializa o vetor de controle de números sorteados

        for (int j = 0; j < 6; j++) {
            int numero_sorteado;
            do {
                numero_sorteado = rand() % 60 + 1; // Gera um número aleatório entre 1 e 60
            } while (numeros_sorteados[numero_sorteado - 1] != 0); // Verifica se o número já foi sorteado

            numeros_sorteados[numero_sorteado - 1] = 1; // Marca o número como sorteado

            sorteios[i][j] = numero_sorteado; // Armazena o número sorteado na matriz
        }
    }
}


void validar_Apostas(int sorteios[][6], int apostas[][15], int linhas, int quantidade_dezenas) {
    for (int i = 0; i < linhas; i++) {
        int contagem = 0; // Contador para contar as dezenas correspondentes

        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < quantidade_dezenas; k++) {
                // Verifica se a dezena do sorteio está presente na linha k das apostas
                for (int l = 0; l < quantidade_dezenas; l++) {
                    if (sorteios[i][j] == apostas[k][l]) {
                        contagem++; // Incrementa a contagem se a dezena está presente
                        break; // Sai do loop interno, pois a dezena já foi encontrada
                    }
                }
            }
        }

        // Verifica se houve quadra, quina ou sena
        if (contagem == 4) {
            printf("Quadra no sorteio %d\n", i + 1);
        } else if (contagem == 5) {
            printf("Quina no sorteio %d\n", i + 1);
        } else if (contagem == 6) {
            printf("Sena no sorteio %d\n", i + 1);
        } else {
            printf("Nenhum acerto no sorteio %d\n", i + 1);
        }
    }
}











