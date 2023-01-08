#ifndef FUNCOES_PRINCIPAIS_H
#define FUNCOES_PRINCIPAIS_H

#include <stdio.h>
#include <time.h>
#include <string.h>
#include "estruturas.h"
#include "funcoes-secundarias.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
                   FUNÇÕES PRINCIPAIS
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void marcar_missao(Total_missoes * total_missoes, Total_tipos_missao * tipos_missao, Total_militares * todos_militares ,Total_funcoes_mil * todas_funcoes){


    int escolha,data[3], data_final;
    printf("\n Escolha o tipo de missao: \n");

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
    criar_equipa(todos_militares, todas_funcoes, &tipos_missao->conj_tipos_missao[escolha],data_final, total_missoes, escolha);

}

void listar_missoes (Total_missoes * lista_de_missoes, Total_tipos_missao * lista_tipos_missao, Total_funcoes_mil * lista_funcoes_mil){

    if (lista_de_missoes->cont_missoes==0){
        printf("não há missoes para imprimir\n");
        return;
    }

    int temp, data1, data2, data, controlo=0;

    printf("insira a data mais antiga no formato DDMMAAAA");
    scanf("%d", &temp);
    data1 = temp/1000000 + temp%1000000/10000 + temp%10000;
    printf("insira a data mais recente no formato DDMMAAAA");
    scanf("%d", &temp);
    data2 = temp/1000000 + temp%1000000/10000 + temp%10000;

    if (data1>data2){
        printf("as datas nao respeitam o que foi pedido");
        return;
    }

    for (int i = 0; i < lista_de_missoes->cont_missoes; i++) {

        data = lista_de_missoes->conj_missoes[i].data;

        if (data >= data1 && data<=data2) {

            printf("\n%d\n%d//%d//%d\n%s", lista_de_missoes->conj_missoes[i].n_voo, data / 10000, data % 10000 / 100,
                   data / 100, lista_tipos_missao->conj_tipos_missao[lista_de_missoes->conj_missoes[i].tipo_de_missao].nome);

            for (int j = 0; j < lista_de_missoes->conj_missoes[i].cont_tripulantes; j++) {
                printf("\n%s\t%s", lista_de_missoes->conj_missoes[i].conj_trip[j].nome,
                       lista_funcoes_mil->todas_funcoes[lista_de_missoes->conj_missoes[i].conj_trip[j].funcao].mil_funcao);
            }
            printf("\n");
            controlo = 1;
        }
    }

    if (controlo == 0){
        printf("Não ha missoes nas datas marcadas");
    }
}

void listar_tripulantes(Total_militares * lista_de_militares, Total_funcoes_mil * lista_funcoes_mil){

    int escolha, escolha2,nip;

    if (lista_de_militares->cont_militares==0){
        printf("nao ha militares para imprimir\n");
        return;
    }

    printf("Selecione a opcao:\n1 - lista total de militares OP\n2 - lista total de militares INOP\n3 - lista por funcao OP\n4 - lista por funcao INOP\n5 - lista global\n6 - sair");
    scanf(" %d", &escolha);


    while (escolha!=6) {
        switch (escolha) {

            case 1:
                imprimir_lista_militares(lista_de_militares, 0, -1);
                break;
            case 2:
                imprimir_lista_militares(lista_de_militares, 1, -1);
                break;
            case 3:
                imprimir_funcoes(lista_funcoes_mil);
                printf("escolha a funcao\n");
                scanf("%d", &escolha2);
                imprimir_lista_militares(lista_de_militares, 0, escolha2);
                break;
            case 4:
                imprimir_funcoes(lista_funcoes_mil);
                printf("escolha a funcao");
                scanf("%d", &escolha2);
                imprimir_lista_militares(lista_de_militares, 0, escolha2);
                break;

            case 5:
                imprimir_lista_militares(lista_de_militares, -1, -1);
            case 6:
                return;

            default:
                printf("numero introduzido não faz parte do menu");
        }

        printf("deseja ver detalhes de um tripulante, se desejar introduza o nip ou introduza -1");
        scanf("%d",&nip);
        if (escolha!=-1){
            imprimir_horas_militar(lista_de_militares, nip);
        }

    }


}

void atualizar_estado(Total_militares * lista_de_militares){

    int nip, escolha, indice, data;

    printf("introduza o nip do militar que pretende modificar o estado\n");
    scanf("%d", &nip);

    indice = imprimir_militar(lista_de_militares, nip);

    printf("para atualizar o estado insira 1 para mudar para OPERACIONAL, 2 para mudar para INOPERACIONAL e 3 para sair");
    scanf("%d", &escolha);

    if (escolha == 3)return;

    else if (escolha == 1){

        if (lista_de_militares->total_tripulantes[indice].estado == 0){
            printf("militar ja se encontra operacional\n");
            return;
        }

        lista_de_militares->total_tripulantes[indice].estado = 0;
        lista_de_militares->total_tripulantes[indice].oper = -1;
    }

    else if (escolha == 2){
        if (lista_de_militares->total_tripulantes[indice].estado == 1){
            printf("militar ja se encontra inoperacional\n");
            return;
        }
        printf("insira a data em que o militar ficará operacional de novo no formato AAAAMMDD");
        scanf("%d", &data);
        lista_de_militares->total_tripulantes[indice].estado=1;
        lista_de_militares->total_tripulantes[indice].oper = data;
    }

    else {
        printf("operacao invalida");
    }

}



#endif //FUNCOES_PRINCIPAIS_H
