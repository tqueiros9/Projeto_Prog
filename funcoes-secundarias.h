#ifndef FUNCOES_SECUNDARIAS_H
#define FUNCOES_SECUNDARIAS_H

#include <stdio.h>
#include <time.h>
#include "estruturas.h"



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
                   FUNÇÕES AUXILIARES
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void iniciar_valores(Total_funcoes_mil * a, Total_militares * b, Total_missoes * c, Total_tipos_missao * d) {
    a->cont_funcoes=0;
    b->cont_militares=0;
    c->cont_missoes=0;
    d->cont_tipos_missao=0;
}

void imprimir_menu() {
    printf("\n1-marcar missao\n2-listar missoes\n3-listar tripulantes\n4-atualizar estado de tripulantes\n5-sair\n");
}

void adicionar_horas_missoes (Total_militares * todos_militares, int nip) {

    for (int i = 0; i < todos_militares; i++) {
        if (todos_militares->total_tripulantes[i].nip == nip) {
            todos_militares->total_tripulantes[i].missoes++;
            todos_militares->total_tripulantes[i].horas_voo+=2;
        }
    }

}

void criar_equipa (Total_militares * todos_militares, Total_funcoes_mil * todas_funcoes, Mission_type * tipo_miss_escolhida, int data, Total_missoes * todas_missoes, int missao_escolhida) {

    int controlo=0, controlo_militar_guardado = 0;

    todas_missoes->conj_missoes[todas_missoes->cont_missoes].data = data;
    todas_missoes->conj_missoes[todas_missoes->cont_missoes].cont_tripulantes = tipo_miss_escolhida->cont_tripulantes_missao;
    todas_missoes->conj_missoes[todas_missoes->cont_missoes].n_voo = data+123;
    todas_missoes->conj_missoes[todas_missoes->cont_missoes].tipo_de_missao = missao_escolhida;


    for (int i = 0; i < tipo_miss_escolhida->cont_tripulantes_missao; i++) {

        for (int j = 0; j < todos_militares->cont_militares; j++) {

            if(todos_militares->total_tripulantes[j].funcao == tipo_miss_escolhida->tipo_tripulantes[i]) {

                for (int k = 0; k < todos_militares->total_tripulantes[j].missoes; k++) {
                    if(todos_militares->total_tripulantes[j].data_missoes[k] == data) {
                        controlo = 1;
                        break;
                    }
                }
                if (controlo == 0) {
                    todas_missoes->conj_missoes[todas_missoes->cont_missoes].conj_trip[i] = todos_militares->total_tripulantes[j];
                    controlo_militar_guardado = 1;
                }
                else {
                    controlo = 0;
                }

            }
            if (controlo_militar_guardado == 1) {
                break;
            }
        }
        if (controlo_militar_guardado == 0) {
            printf("nao ha militares disponiveis para executar a missao");
            return;
        }
    }
    for (int i = 0; i < tipo_miss_escolhida->cont_tripulantes_missao; i++) {
        adicionar_horas_missoes(todos_militares,todas_missoes->conj_missoes[todas_missoes->cont_missoes].conj_trip[i].nip);
    }
    todas_missoes->cont_missoes++;

}

int verifica_funcao(char * tipos_funcoes, Total_funcoes_mil * todas_funcoes) {

    for (int i = 0; i < todas_funcoes->cont_funcoes; ++i) {
        if (strcmp(tipos_funcoes,todas_funcoes->todas_funcoes[i].mil_funcao)==0) {
            return i;
        }
    }

}

void adicionar_dados_militares(char * linha, Total_militares * lista_mil_total, Total_funcoes_mil * lista_func) {

    char s[2]=";";
    char *temp;
    int cont=0, help;

    /* get the first token */
    temp = strtok(linha, s);

    /* walk through other tokens */
    while( temp != NULL ) {
        printf( " %s\n", temp );

        switch (cont) {
        case 0:
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

}

void imprimir_funcoes(Total_funcoes_mil * lista_funcoes) {

    for (int i = 0; i < lista_funcoes->cont_funcoes; i++) {
        printf("%s",lista_funcoes->todas_funcoes[i].mil_funcao);
    }
}

//recebe lista de militares, o seu estado 0 = OP e 1 = INOP
void imprimir_lista_militares (Total_militares * lista_militares, int estado, int funcao) {

    printf("NIP\tNOME\n");

    for (int i = 0; i < lista_militares->cont_militares; i++) {

        if ((lista_militares->total_tripulantes[i].estado==estado || lista_militares->total_tripulantes[i].estado== -1)&&
                (lista_militares->total_tripulantes[i].funcao==funcao|| lista_militares->total_tripulantes[i].funcao==-1)) {
            printf("\n%d\t%s", lista_militares->total_tripulantes[i].nip, lista_militares->total_tripulantes[i].nome);

        }
    }
}

int imprimir_militar (Total_militares * lista_militares, int nip) {

    char estado[20];

    for (int i = 0; i < lista_militares->cont_militares; i++) {

        if (lista_militares->total_tripulantes[i].nip==nip) {

            if (lista_militares->total_tripulantes[i].estado == 0) {
                strcpy(estado, "OPERACIONAL");
            }
            else {
                strcpy(estado, "INOPERACIONAL");
            }

            printf("%s \n\nnip: %d\n\testado: %s\n", lista_militares->total_tripulantes[i].nome,
                   lista_militares->total_tripulantes[i].nip, estado);
            return i;

        }
    }

}

void imprimir_horas_militar (Total_militares * lista_militares, int nip) {

    for (int i = 0; i < lista_militares->cont_militares; i++) {

        if (lista_militares->total_tripulantes[i].nip==nip) {

            printf("%s \n\thoras de voo: %d\n\tnumero de missoes: %d\n", lista_militares->total_tripulantes[i].nome,
                   lista_militares->total_tripulantes[i].horas_voo, lista_militares->total_tripulantes[i].missoes);
            break;

        }
    }

}

#endif //FUNCOES_SECUNDARIAS_H
