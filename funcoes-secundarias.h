#ifndef FUNCOES_SECUNDARIAS_H
#define FUNCOES_SECUNDARIAS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "estruturas.h"


#define CAMINHO 100

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
                   FUNÇÕES AUXILIARES
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
// Inicia as variaveis do programa a 0
void iniciar_valores(Total_funcoes_mil * a, Total_militares * b, Total_missoes * c, Total_tipos_missao * d){
    a->cont_funcoes=0;             //a,b,c,d sao variaveis a apontar para os tipos das estruturas
    b->cont_militares=0;           //meter os contadores a zero
    c->cont_missoes=0;
    d->cont_tipos_missao=0;
}

// Imprime o menu
void imprimir_menu(){

    printf("\n1-marcar missao\n2-listar missoes\n3-listar tripulantes\n4-atualizar estado de tripulantes\n5-Adicionar ficheiro a BD\n6-sair\n");
}

// Importa a estrutura das informacoes dos militares e o nip escolhido no menu
void adicionar_horas_missoes (Total_militares * todos_militares, int nip){

    //Ciclo que percorre a estrutura dos militares ate encontrar um militar com o nip importado na funcao
    //Quando encontrado adiciona uma missao e horas de voo

    for (int i = 0; i < todos_militares->cont_militares; i++) {
        if (todos_militares->total_tripulantes[i].nip == nip){
            todos_militares->total_tripulantes[i].missoes++;
            todos_militares->total_tripulantes[i].horas_voo+=2;
        }
    }

}

void criar_equipa (Total_militares * todos_militares, Mission_type * tipo_miss_escolhida, int data, Total_missoes * todas_missoes, int missao_escolhida){

    int controlo=0, controlo_militar_guardado = 0, j, indice = 0;

    todas_missoes->conj_missoes[todas_missoes->cont_missoes].data = data;
    todas_missoes->conj_missoes[todas_missoes->cont_missoes].cont_tripulantes = tipo_miss_escolhida->cont_tripulantes_missao;
    todas_missoes->conj_missoes[todas_missoes->cont_missoes].n_voo = 1000+todas_missoes->cont_missoes+1;
    todas_missoes->conj_missoes[todas_missoes->cont_missoes].tipo_de_missao = missao_escolhida;


    for (int i = 0; i < tipo_miss_escolhida->cont_tripulantes_missao; i++) {

        for (j = indice; j < todos_militares->cont_militares; j++) {


            if(todos_militares->total_tripulantes[j].funcao == tipo_miss_escolhida->tipo_tripulantes[i]){

                for (int k = 0; k < todos_militares->total_tripulantes[j].missoes; k++) {
                    if(todos_militares->total_tripulantes[j].data_missoes[k] == data){
                        controlo = 1;
                        break;
                    }
                }
                if (controlo == 0){
                    todas_missoes->conj_missoes[todas_missoes->cont_missoes].conj_trip[i] = todos_militares->total_tripulantes[j];
                    controlo_militar_guardado = 1;
                }
                else{
                    controlo = 0;
                }

            }
            if (controlo_militar_guardado == 1){
                indice = j+1;
                break;
            }
        }
        if (controlo_militar_guardado == 0){
            printf("Nao ha militares disponiveis para executar a missao");
            return;
        }
    }
    for (int i = 0; i < tipo_miss_escolhida->cont_tripulantes_missao; i++) {
        adicionar_horas_missoes(todos_militares,todas_missoes->conj_missoes[todas_missoes->cont_missoes].conj_trip[i].nip);
    }
    todas_missoes->cont_missoes++;

}

int verifica_funcao(char * tipos_funcoes, Total_funcoes_mil * todas_funcoes){

    for (int i = 0; i < todas_funcoes->cont_funcoes; ++i) {
        if (strcmp(tipos_funcoes,todas_funcoes->todas_funcoes[i].mil_funcao)==0){
            return i;
        }
    }

}

int verifica_militar (Total_militares * lista_mil, int nip){
    int i;
    for (i = 0; i < lista_mil->cont_militares; i++) {
        if (lista_mil->total_tripulantes[i].nip ==nip){
            return i;
        }
    }
    if (i == lista_mil->cont_militares)return -1;
}

void adicionar_dados_militares(char linha[], Total_militares * lista_mil_total, Total_funcoes_mil * lista_func){

    char s[2]=";";
    char *temp;
    int cont=0, help, verifica;

    /* get the first token */
    temp = strtok(linha, s);

    /* walk through other tokens */
    while( temp != NULL ) {

        switch (cont) {
            case 0:
                verifica = verifica_militar(lista_mil_total, atoi(temp));
                if(verifica != -1)return;
                lista_mil_total->total_tripulantes[lista_mil_total->cont_militares].nip = atoi(temp);
                break;
            case 1:
                strcpy(lista_mil_total->total_tripulantes[lista_mil_total->cont_militares].nome, temp);
                break;
            case 2:
                    lista_mil_total->total_tripulantes[lista_mil_total->cont_militares].funcao= verifica_funcao(temp, lista_func);
                    break;
            case 3:
                    help = strcmp(temp,"OP");
                    if(help==0)lista_mil_total->total_tripulantes[lista_mil_total->cont_militares].estado = 0;
                    else lista_mil_total->total_tripulantes[lista_mil_total->cont_militares].estado = 1;
                    break;
            case 4:
                    if (help!=0)lista_mil_total->total_tripulantes[lista_mil_total->cont_militares].oper = atoi(temp);
                    else lista_mil_total->total_tripulantes[lista_mil_total->cont_militares].oper=-1;
                    break;
            case 5:
                lista_mil_total->total_tripulantes[lista_mil_total->cont_militares].horas_voo = atoi(temp);
                break;
            case 6:
                lista_mil_total->total_tripulantes[lista_mil_total->cont_militares].missoes = atoi(temp);
                break;
            default:
                return;
        }
        temp = strtok(NULL,s);
        cont++;

    }
    lista_mil_total->cont_militares++;
}

void imprimir_funcoes(Total_funcoes_mil * lista_funcoes){

    for (int i = 0; i < lista_funcoes->cont_funcoes; i++) {
        printf("%d - %s\n",i,lista_funcoes->todas_funcoes[i].mil_funcao);
    }
}

//recebe lista de militares, o seu estado 0 = OP e 1 = INOP
void imprimir_lista_militares (Total_militares * lista_militares, int estado, int funcao){

    //testes---------------

    //-----------

    if (lista_militares->cont_militares==0){
        printf("nao ha militares na base de dados\n");
        return;
    }

    printf("\n----LISTA DE MILITARES----\n");
    printf("NIP\tNOME");

    for (int i = 0; i < lista_militares->cont_militares; i++) {

        if ((lista_militares->total_tripulantes[i].estado==estado || estado== -1)&&
        (lista_militares->total_tripulantes[i].funcao==funcao|| funcao==-1)){
            printf("\n%d\t%s", lista_militares->total_tripulantes[i].nip, lista_militares->total_tripulantes[i].nome);

        }
    }
    printf("\n----FIM DA LISTA----");
    printf("\n");
}

// Importa a lista dos militares e o nip escolhido
int imprimir_militar (Total_militares * lista_militares, int nip){

    char estado[20];
    int i;

    //Percorre a estrutura lista de militares
    //Encontra o militar com o nip escolhido

    i = verifica_militar(lista_militares,nip);

    // Se o estado estiver em 0, imprimir "Operacional", se diferente de 0, imprime "Inoperacional"
        if (lista_militares->total_tripulantes[i].estado == 0){
            strcpy(estado, "OPERACIONAL");
        }
        else {
            strcpy(estado, "INOPERACIONAL");
        }

        printf("\n%s \n\nnip: %d\n\testado: %s\n", lista_militares->total_tripulantes[i].nome,
               lista_militares->total_tripulantes[i].nip, estado);
        return i;

}

// Importa a lista dos militares e o nip escolhido
void imprimir_horas_militar (Total_militares * lista_militares, int nip){

    int controlo =0, i;

    //Percorre a estrutura lista de militares
    //Encontra o militar com o nip escolhido
    i = verifica_militar(lista_militares,nip);

    //Imprime o nome, horas de voo e o numero de missoes
    if (lista_militares->total_tripulantes[i].nip==nip){

       printf("%s \n\thoras de voo: %d\n\tnumero de missoes: %d\n", lista_militares->total_tripulantes[i].nome,
                   lista_militares->total_tripulantes[i].horas_voo, lista_militares->total_tripulantes[i].missoes);

    }

    // se apos percorrer a lista dos militares e nao encontrar nenhum o i esta a -1 e imprime o printf em baixo
    if (i == -1)printf("\nO NIP introduzido nao corresponde a nenhum militar");

}

//importa a lista de missões e o numero de voo indicado
int encontrar_indice_missao(Total_missoes * lista_missoes, int voo){
    int i;

    //percorre a lista de missões até encontrar o voo
    for (i = 0; i < lista_missoes->cont_missoes; i++) {
        if(lista_missoes->conj_missoes[i].n_voo == voo)return i;
    }

    //retoma o indice da missão desse voo

}

//importa a lista de missões e o voo indicado no menu
void eliminar_missao(Total_missoes * lista_missoes, int voo){

    int i;

    i = encontrar_indice_missao(lista_missoes,voo); //i= indice do voo ( vem da função anterior)
    for (int j = i; j < lista_missoes->cont_missoes-1; j++) {
        lista_missoes->conj_missoes[j]=lista_missoes->conj_missoes[j+1]; // Passa cada missão a seguir ao voo para o indice anterior do vetor
    }
    lista_missoes->cont_missoes--; // tira uma missão da contagem de missões
}

//Importa todas as listas com informações relativas ao voo e o numero do voo
void imprimir_dados_voo (Total_missoes * lista_missoes, int voo, Total_tipos_missao * lista_tipos, Total_funcoes_mil * funcoes_mil){


    int i, data;
    i = encontrar_indice_missao(lista_missoes,voo); //usa a função encontrar_indice_missao para usar nos indicadores do printf
    data = lista_missoes->conj_missoes[i].data;

    //imprime todos os dados do voo

    printf("\n--MISSAO--\n"
           "Numero de voo:\t%d\n"
           "Data:\t\t%d/%d/%d\n"
           "Tipo de missao:\t%s\n"
           "Numero de tripulantes\t%d\n", lista_missoes->conj_missoes[i].n_voo,
           data % 100, data % 10000 / 100,data/10000,
           lista_tipos->conj_tipos_missao[lista_missoes->conj_missoes[i].tipo_de_missao].nome,
           lista_missoes->conj_missoes[i].cont_tripulantes);

    printf("--TRIPULANTES--\n");

    //Percorre a lista de tripulantes e imprime o nome e função de cada tripulantes no voo

    for (int j = 0; j < lista_missoes->conj_missoes[i].cont_tripulantes; j++) {
        printf("%s\t%s\n", lista_missoes->conj_missoes[i].conj_trip[j].nome,
               funcoes_mil->todas_funcoes[lista_missoes->conj_missoes[i].conj_trip[j].funcao].mil_funcao);
    }
}


void ler_dados_binario(Total_militares * lista_militares, Total_missoes * lista_missoes){
    char filename_mil[] = "militares.bd";
    char filename_mis[] = "missoes.bd";

    FILE * fp, *fp2;
    fp = fopen(filename_mil, "rb");
    if(fp == NULL){
        printf("Abertura de ficheiro incorrecta.\n");
        return;
    }
    else {


        fread(&lista_militares->cont_militares, sizeof(int), 1, fp);
        fread(lista_militares->total_tripulantes, sizeof(lista_militares->total_tripulantes[0]), lista_militares->cont_militares, fp);
        fclose(fp);
    }

    fp = fopen(filename_mis, "wb");
    if(fp == NULL){
        printf("Abertura de ficheiro incorrecta.\n");
        return;
    }
    else {
        fread(&lista_missoes->cont_missoes, sizeof(int), 1, fp);
        fread(lista_missoes->conj_missoes, sizeof(lista_missoes->conj_missoes[0]), lista_missoes->cont_missoes, fp);
        fclose(fp);
    }


}
void guardar_dados_binario (Total_militares * lista_militares, Total_missoes * lista_missoes){

    char filename_mil[] = "militares.bd";
    char filename_mis[] = "missoes.bd";

    FILE * fp, *fp2;
    fp = fopen(filename_mil, "wb");
    if(fp == NULL){
        printf("Abertura de ficheiro incorrecta.\n");
        return;
    }
    else {
        fwrite(&lista_militares->cont_militares, sizeof(int), 1, fp);
        fwrite(lista_militares->total_tripulantes, sizeof(lista_militares->total_tripulantes[0]), lista_militares->cont_militares, fp);
        fclose(fp);
    }

    fp = fopen(filename_mis, "wb");
    if(fp == NULL){
        printf("Abertura de ficheiro incorrecta.\n");
        return;
    }
    else {

        fwrite(&lista_missoes->cont_missoes, sizeof(int), 1, fp);
        fwrite(lista_missoes->conj_missoes, sizeof(lista_missoes->conj_missoes[0]), lista_missoes->cont_missoes, fp);
        fclose(fp);
    }


}


void carregar_militares (Total_militares * lista_mil, Total_funcoes_mil * lista_func){
    char caminho [CAMINHO];
    char buffer [CAMINHO];
    int controlo=0, i, a=0;
    printf("\n--Carregar Militares--\n");
    FILE *fp;
    getchar();
    while(a==0){
        printf("Introduza caminho do ficheiro: ");
        fgets(caminho, CAMINHO, stdin);

        for (i = 0; caminho[i] != '\n'; i++);
        caminho[i]='\0';


        fp=fopen(caminho, "r");
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

    fgets(buffer, 100, fp);
    while (fgets(buffer, 100, fp)){
        if (a == 1){
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

#endif //FUNCOES_SECUNDARIAS_H
