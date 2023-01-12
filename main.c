#include <stdio.h>

#include "estruturas.h"
#include "funcoes-secundarias.h"
#include "funcoes_principais.h"

int main() {

  int escolha_menu;
  Total_tipos_missao todos_tipos_missoes;
  Total_missoes todasAsMissoes;
  Total_militares todos_os_militares;
  Total_funcoes_mil todas_func_mil;

  iniciar_valores(&todas_func_mil, &todos_os_militares, &todasAsMissoes,
                  &todos_tipos_missoes); // ir à secundária l17
  ler_dados_binario(&todos_os_militares, &todasAsMissoes);

  if (todos_tipos_missoes.cont_tipos_missao == 0) {
    Mission_type ser_padeiro = {"bater charuto", 2, 0, 0};
    todos_tipos_missoes.conj_tipos_missao[0] = ser_padeiro;
    todos_tipos_missoes.cont_tipos_missao = 1;
  }
  Missao_unica viagem_ao_espaco = {1001,
                                   20221112,
                                   0,
                                   2,
                                   todos_os_militares.total_tripulantes[0],
                                   todos_os_militares.total_tripulantes[1]};
  todasAsMissoes.conj_missoes[0] = viagem_ao_espaco;
  todasAsMissoes.cont_missoes++;

  tipos_funcoes_mil ab_ab = {"padeiro"};
  todas_func_mil.todas_funcoes[0] = ab_ab;
  todas_func_mil.cont_funcoes++;

  imprimir_menu();
  scanf(" %d", &escolha_menu);

  while (escolha_menu != 6) {

    switch (escolha_menu) {

    case 1:
      marcar_missao(&todasAsMissoes, &todos_tipos_missoes, &todos_os_militares,
                    &todas_func_mil);
      break;
    case 2:
      listar_missoes(&todasAsMissoes, &todos_tipos_missoes, &todas_func_mil);
      break;
    case 3:
      listar_tripulantes(&todos_os_militares, &todas_func_mil);
      break;
    case 4:
      // atualizar estado militares
      atualizar_estado(&todos_os_militares);
      break;

      break;
    case 5:
      // adicionar ficheiro à BD
      carregar_militares(&todos_os_militares, &todas_func_mil);
      break;
    case 6:
      guardar_dados_binario(&todos_os_militares, &todasAsMissoes);
      return 0;

    default:
      printf("Escolha invalida, nao existe essa opcao no menu");
    }

    imprimir_menu();
    scanf(" %d", &escolha_menu);
  }
}
