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
    printf("\nEscolha o tipo de missao: \n");

    //ciclo que imprime todos os tipos de missao carregados no SIGIT
    imprimir_funcoes(todas_funcoes);
    scanf("%d",&escolha);

    printf("Insira a data, no formato DD/MM/AAAA");

    //programa faz a leitura da data no formato comum e transforma no formato esperado pelo programa AAAAMMDD
    scanf("%d/%d/%d",&data[0], &data[1], &data[2]);
    data_final = data[0] + data[1] *100 + data[2]*10000;

    //insere-se a data no vetor das missoes no formato do programa AAAAMMDD
    total_missoes->conj_missoes[total_missoes->cont_missoes].data = data_final;

    //criação da equipa
    criar_equipa(todos_militares, &tipos_missao->conj_tipos_missao[escolha],data_final, total_missoes, escolha);
    getchar();
}

void listar_missoes (Total_missoes * lista_de_missoes, Total_tipos_missao * lista_tipos_missao, Total_funcoes_mil * lista_funcoes_mil){

    if (lista_de_missoes->cont_missoes==0){
        printf("nao ha missoes para imprimir\n");
        return;
    }


    int temp, data1, data2, data, controlo=0, escolha, escolha2;

    printf("insira a data mais antiga no formato DDMMAAAA\n");
    scanf("%d", &temp);
    data1 = temp/1000000 + temp%1000000/10000*100 + temp%10000*10000;
    printf("insira a data mais recente no formato DDMMAAAA\n");
    scanf("%d", &temp);
    data2 = temp/1000000 + temp%1000000/10000*100 + temp%10000*10000;

    if (data1>data2){
        printf("as datas nao respeitam o que foi pedido");
        return;
    }

    for (int i = 0; i < lista_de_missoes->cont_missoes; i++) {

        data = lista_de_missoes->conj_missoes[i].data;

        if (data >= data1 && data<=data2) {

            printf("\n%d\n%d/%d/%d\n%s", lista_de_missoes->conj_missoes[i].n_voo, data % 100, data % 10000 / 100,
                   data/10000, lista_tipos_missao->conj_tipos_missao[lista_de_missoes->conj_missoes[i].tipo_de_missao].nome);

            for (int j = 0; j < lista_de_missoes->conj_missoes[i].cont_tripulantes; j++) {
                printf("\n%s\t%s", lista_de_missoes->conj_missoes[i].conj_trip[j].nome,
                       lista_funcoes_mil->todas_funcoes[lista_de_missoes->conj_missoes[i].conj_trip[j].funcao].mil_funcao);
            }
            printf("\n");
            controlo = 1;
        }
    }
    if (controlo == 0){
        printf("Nao ha missoes nas datas marcadas");
        return;
    }
    printf("\nDeseja ver detalhes de uma missao, se desejar introduza o numero de voo ou introduza -1 para sair\n");
    scanf("%d",&escolha);

    if (escolha == -1)return;
    else{
        imprimir_dados_voo(lista_de_missoes, escolha, lista_tipos_missao,lista_funcoes_mil);
        printf("\nDeseja eliminar a missao? 1-S 2-N");
        scanf("%d",&escolha2);
        if(escolha2!=1 && escolha2!=2){
            printf("opcao invalida");
            return;
        }
        if (escolha==2)return;
        eliminar_missao(lista_de_missoes, escolha);
        return;
    }


}

void listar_tripulantes(Total_militares * lista_de_militares, Total_funcoes_mil * lista_funcoes_mil){

    int escolha, escolha2,nip;

    if (lista_de_militares->cont_militares==0){
        printf("nao ha militares para imprimir\n");
        return;
    }


    printf("Selecione a opcao:\n1 - lista total de militares OP\n2 - lista total de militares INOP\n3 - lista por funcao OP\n4 - lista por funcao INOP\n5 - lista global\n6 - sair\n");
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
                printf("escolha a funcao\n");
                imprimir_funcoes(lista_funcoes_mil);
                scanf("%d", &escolha2);
                imprimir_lista_militares(lista_de_militares, 0, escolha2);
                break;
            case 4:
                printf("escolha a funcao");
                imprimir_funcoes(lista_funcoes_mil);
                scanf("%d", &escolha2);
                imprimir_lista_militares(lista_de_militares, 0, escolha2);
                break;

            case 5:
                imprimir_lista_militares(lista_de_militares, -1, -1);
                break;
            case 6:
                getchar();
                system("clear");
                return;

            default:
                printf("numero introduzido não faz parte do menu");
        }

        printf("\ndeseja ver detalhes de um tripulante, se desejar introduza o nip ou introduza -1\n");
        scanf("%d",&nip);
        if (nip!=-1){
            imprimir_horas_militar(lista_de_militares, nip);
        }
        printf("\n\nSelecione a opcao:\n1 - lista total de militares OP\n2 - lista total de militares INOP\n3 - lista por funcao OP\n4 - lista por funcao INOP\n5 - lista global\n6 - sair\n");
        scanf(" %d", &escolha);

    }


}

void atualizar_estado(Total_militares * lista_de_militares){

    if (lista_de_militares->cont_militares==0){
        printf("nao ha militares para imprimir\n");
        return;
    }

    int nip, escolha, indice, data;

    printf("introduza o nip do militar que pretende modificar o estado\n");
    scanf("%d", &nip);

    indice = imprimir_militar(lista_de_militares, nip);

    printf("para atualizar o estado insira 1 para mudar para OPERACIONAL, 2 para mudar para INOPERACIONAL e 3 para sair\n");
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

void ler_ficheiro_mil(Total_militares * lista_mil, Total_funcoes_mil * lista_func, char nome_ficheiro[]){

    char caminho [CAMINHO];
    char buffer [CAMINHO];
    int controlo=0, i, a=1;
    FILE *fp;

    printf("\n--Carregar Militares--\n");
    getchar();

    while(a==1){
        /*
        printf("Introduza caminho do ficheiro: ");
        fgets(caminho, CAMINHO, stdin);

        for (i = 0; caminho[i] != '\n'; i++);
        caminho[i]='\0';
        */
        fp=fopen(nome_ficheiro, "r");
        if(fp==NULL){
            printf("ERRO: Ficheiro nao existente!\n\n");
            a=1;
        }else
            a=0;
        if (a == 1) {
            printf("deseja sair? 1-S 0-N\n");
            scanf("%d", &controlo);
        }
        if(controlo == 1)return;
    };

    controlo=0;
    fgets(buffer, 100, fp);
    while (fgets(buffer, 100, fp)){
        if (controlo=0){
            controlo=1;
            a=2;
            continue;
        }
        fgets(buffer, 100, fp);
        adicionar_dados_militares(buffer, lista_mil, lista_func);
    }
    fclose(fp);
    printf("BD carregada com sucesso!\n");
    printf("Novo numero de militares: %d", lista_mil->cont_militares);
}


#endif //FUNCOES_PRINCIPAIS_H
