#include <stdio.h>
#include "megasena.h"

int main() 
{
    titulo();
    int quantidade_dezenas = volante_dezenas();
    int quantidade_ApostasManuais;

    do {
        printf("\nQuantas apostas manuais voce deseja fazer? (0 a 3): "); 
        scanf("%d", &quantidade_ApostasManuais);

        if (quantidade_ApostasManuais < 0 || quantidade_ApostasManuais > 3) {
            printf("Por favor, informe um valor entre 0 e 3.\n");
        }
    } while (quantidade_ApostasManuais < 0 || quantidade_ApostasManuais > 3);

    printf("Voce escolheu %d apostas manuais.\n", quantidade_ApostasManuais);

    int apostas[3][15];       // Matriz para armazenar as apostas manuais
    int surpresinhas[7][15];  // Matriz para armazenar as surpresinhas

    volante_QuantidadeApostasManuais(quantidade_ApostasManuais, quantidade_dezenas, apostas);

    char resposta;
    printf("\nVoce deseja jogar surpresinhas? (s/n): ");
    scanf(" %c", &resposta);

    int quantidade_Surpresinhas = 0;
    if (resposta == 's' || resposta == 'S') 
    {
        printf("Quantas surpresinhas voce deseja fazer?(0 a 7): "); 
        scanf("%d", &quantidade_Surpresinhas);
        
        if (quantidade_Surpresinhas > 0) 
        {
            gerar_Surpresinhas(quantidade_Surpresinhas, quantidade_dezenas, surpresinhas);
            // Mostra as surpresinhas geradas
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
        } else 
        {
            printf("\nNenhuma surpresinha gerada.\n");
        }
    }
    mostrar_ApostasManuais(quantidade_ApostasManuais, quantidade_dezenas, apostas);
    
    float valor_dezenas = calcular_ValorDezenas(quantidade_dezenas);

    int quantidade_teimosinha = quantidade_Teimosinha();
    printf("Quantidade de teimosinhas: %i\n", quantidade_teimosinha);



    printf("apostas manuais: %i | dezenas: %i | surpresinhas: %i | teimosinhas: %i | valor das dezenas: %.2f\n", quantidade_ApostasManuais, quantidade_dezenas, quantidade_Surpresinhas, quantidade_teimosinha, valor_dezenas);

    float valor_total = calcular_ValorTotal(quantidade_teimosinha, valor_dezenas, quantidade_ApostasManuais, quantidade_Surpresinhas);
    printf("O valor total das apostas e: %.2f R$\n", valor_total);

    char concorda;
    printf("Concorda com o valor? (s/n): ");
    scanf(" %c", &concorda);

    if (concorda == 's' || concorda == 'S') 
    {
        // Continua o programa
    } else 
    {
        printf("Programa finalizado.\n");
        return 0; // Finaliza o programa
    }

    int linhas = 1; // Definindo a variável linhas com valor padrão
    if (quantidade_teimosinha == 2) 
    {
        linhas = 3;
    } else if (quantidade_teimosinha == 8) 
    {
        linhas = 9;
    }

    int sorteios[linhas][6]; // Matriz para armazenar os sorteios

    realizar_Sorteio(quantidade_teimosinha, sorteios);

    // Mostra os sorteios gerados
    printf("\nSorteios da Mega-Sena:\n");
    for (int i = 0; i < linhas; i++) 
    {
        printf("Sorteio %d:", i + 1);
        for (int j = 0; j < 6; j++) 
        {
            printf(" %d", sorteios[i][j]);
        }
        printf("\n");
    }
    validar_Apostas(sorteios, apostas, linhas, quantidade_dezenas);


    return 0;
}



