#ifndef MEGASENA_H
#define MEGASENA_H

void titulo();
int volante_dezenas();
void volante_QuantidadeApostasManuais(int quantidade_ApostasManuais, int quantidade_dezenas, int apostas[][15]);
void gerar_Surpresinhas(int quantidade_Surpresinhas, int quantidade_dezenas, int surpresinhas[][15]);
void mostrar_ApostasManuais(int quantidade_ApostasManuais, int quantidade_dezenas, int apostas[][15]);
float calcular_ValorDezenas(int quantidade_dezenas);
int quantidade_Teimosinha();
float calcular_ValorTotal(int quantidade_teimosinha, float valor_dezenas, int quantidade_ApostasManuais, int quantidade_Surpresinhas);
void realizar_Sorteio(int quantidade_teimosinha, int sorteios[][6]);
void validar_Apostas(int sorteios[][6], int apostas[][15], int linhas, int quantidade_dezenas);


#endif //MEGASENA_H
