#ifndef FUNCOES_PRINCIPAIS_H
#define FUNCOES_PRINCIPAIS_H

#include "estruturas.h"
#include "funcoes-secundarias.h"
#include <stdio.h>
#include <time.h>
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
                   FUNÇÕES PRINCIPAIS
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void marcar_missao(Total_missoes * total_missoes, Total_tipos_missao * tipos_missao){

    int escolha,data[3], data_final=0;
    printf("\n Escolha o tipo de missao:\n");

    //ciclo que imprime todos os tipos de missao carregados no SIGIT
    for (int i = 1; i <= tipos_missao->cont_tipos_missao ; i++) {
        printf("%d - %s\n", i, tipos_missao->conj_tipos_missao[i].nome);
    }
    scanf("%d",&escolha);

    printf("Insira a data, no formato DD/MM/AAAA");

    //programa faz a leitura da data no formato comum e transforma no formato esperado pelo programa AAAAMMDD
    scanf("%d//%d//%d",&data[0], &data[1], &data[2]);
    data_final = data[0] + data[1] *100 + data[2]*10000;

    //insere-se a data no vetor das missoes no formato do programa AAAAMMDD
    total_missoes->conj_missoes[total_missoes->cont_missoes].data = data_final;

    //criação da equipa

}



#endif //FUNCOES_PRINCIPAIS_H
