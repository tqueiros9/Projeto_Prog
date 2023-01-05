#ifndef FUNCOES_PRINCIPAIS_H
#define FUNCOES_PRINCIPAIS_H

#include "estruturas.h"
#include "funcoes-secundarias.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
                   FUNÇÕES PRINCIPAIS
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void marcar_missao(Total_missoes *total_missoes,
                   Total_tipos_missao *tipos_missao) {

  int escolha, data[3], data_final = 0;
  printf("\n Escolha o tipo de missao: \n");
  printf("teste");

  // ciclo que imprime todos os tipos de missao carregados no SIGIT
  for (int i = 1; i <= tipos_missao->cont_tipos_missao; i++) {
    printf("%d - %s\n", i, tipos_missao->conj_tipos_missao[i].nome);
  }
  scanf("%d", &escolha);

  printf("Insira a data, no formato DD/MM/AAAA");

  // programa faz a leitura da data no formato comum e transforma no formato
  // esperado pelo programa AAAAMMDD
  scanf("%d//%d//%d", &data[0], &data[1], &data[2]);
  data_final = data[0] + data[1] * 100 + data[2] * 10000;

  // insere-se a data no vetor das missoes no formato do programa AAAAMMDD
  total_missoes->conj_missoes[total_missoes->cont_missoes].data = data_final;

  // criação da equipa
}

void listar_missoes(Total_missoes *lista_de_missoes) {
  Total_militares todos_mil;
  int cont;
  printf("%d %s %s %s", cont, todos_mil.total_tripulantes[1]->nip,
         todos_mil.total_tripulantes[1]->nome,
         todos_mil.total_tripulantes[1]->funcao);
}

void listar_tripulantes(Total_militares *lista_de_militares,
                        Total_funcoes_mil *lista_funcoes_mil) {

  int escolha, escolha2;
  printf("Selecione a opcao:\n1 - lista total de militares OP\n2 - lista total "
         "de militares INOP\n3 - lista por funcao OP\n4 - lista por funcao "
         "INOP\n6 - sair");
  scanf("%d", &escolha);

  switch (escolha) {

  case 1:
    imprimir_lista_militares(lista_de_militares, 0, -1);
    break;
  case 2:
    imprimir_lista_militares(lista_de_militares, 1, -1);
    break;
  case 3:
    imprimir_funcoes(lista_funcoes_mil);
    printf("escolha a funcao");
    scanf("&d", &escolha2);
    imprimir_lista_militares(lista_de_militares, 0, escolha2);
    break;
  case 4:
    imprimir_funcoes(lista_funcoes_mil);
    printf("escolha a funcao");
    scanf("&d", &escolha2);
    imprimir_lista_militares(lista_de_militares, 0, escolha2);
    break;

  case 5:
    imprimir_lista_militares(lista_de_militares, -1, -1);
  case 6:
    return;

  default:
    printf("numero introduzido não faz parte do menu");
  }
}

#endif // FUNCOES_PRINCIPAIS_H
