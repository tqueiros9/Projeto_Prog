#include <stdio.h>

#include "estruturas.h"
#include "funcoes_principais.h"
#include "funcoes-secundarias.h"


int main(){



    int escolha_menu;
    Total_tipos_missao todos_tipos_missoes;
    Total_missoes todasAsMissoes;
    Total_militares todos_os_militares;
    Total_funcoes_mil todas_func_mil;

    iniciar_valores(&todas_func_mil, &todos_os_militares, &todasAsMissoes, &todos_tipos_missoes); //ir à secundária l17
    ler_dados_binario(&todos_os_militares,&todasAsMissoes);

/*
    Tripulante gm_gm = {"guilherme", 141916, 0,1,20230120,2,1,20221112};
    Tripulante at_at = {"tiago", 141914,0,0,-1,2,2,20221112,20221211};
    todos_os_militares.total_tripulantes[0] = at_at;
    todos_os_militares.total_tripulantes[1] = gm_gm;
    todos_os_militares.cont_militares=2;


    Missao_unica viagem_ao_espaco = {1001, 20221112, 0, 2, todos_os_militares.total_tripulantes[0], gm_gm};

    todasAsMissoes.conj_missoes[0] = viagem_ao_espaco;
    todasAsMissoes.cont_missoes++;



    tipos_funcoes_mil ab_ab = {"padeiro"};
    todas_func_mil.todas_funcoes[0] = ab_ab;
    todas_func_mil.cont_funcoes=1;
*/
    imprimir_menu();
    scanf(" %d",&escolha_menu);

    while(escolha_menu!=10){

        switch (escolha_menu) {

            case 1:
                marcar_missao(&todasAsMissoes, &todos_tipos_missoes, &todos_os_militares, &todas_func_mil);
                break;
            case 2:
                listar_missoes(&todasAsMissoes, &todos_tipos_missoes, &todas_func_mil);
                break;
            case 3:
                listar_tripulantes(&todos_os_militares, &todas_func_mil);
                break;
            case 4:
                //atualizar estado militares
                atualizar_estado(&todos_os_militares);
                break;

                break;
            case 5:
                //adicionar ficheiro à BD
                ficheiro_mil(&todos_os_militares, &todas_func_mil);
                break;
            case 6:
                guardar_dados_binario(&todos_os_militares, &todasAsMissoes);
                return 0;

            default:
                printf("Escolha invalida, nao existe essa opcao no menu");
        }

        imprimir_menu();
        scanf(" %d",&escolha_menu);

    }








}


