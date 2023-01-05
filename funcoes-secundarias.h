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
    printf("\n1-marcar missao\n2-listar missoes\n3-listar tripulantes\n4-atualizar estado de tripulantes\n5-sair");
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

        if ((lista_militares->total_tripulantes[i]->estado==estado || lista_militares->total_tripulantes[i]->estado== -1)&&
                (lista_militares->total_tripulantes[i]->funcao==funcao|| lista_militares->total_tripulantes[i]->funcao==-1)) {
            printf("\n%d\t%s", lista_militares->total_tripulantes[i]->nip, lista_militares->total_tripulantes[i]->nome);

        }
    }
}

void imprimir_militar (Total_militares * lista_militares, int nip) {

    for (int i = 0; i < lista_militares->cont_militares; i++) {

        if (lista_militares->total_tripulantes[i]->nip==nip) {

            printf("%s \n\thoras de voo: %d\n\tnumero de missoes: %d\n", lista_militares->total_tripulantes[i]->nome,
                   lista_militares->total_tripulantes[i]->horas_voo, lista_militares->total_tripulantes[i]->missoes);
            break;

        }
    }

}

#endif //FUNCOES_SECUNDARIAS_H
