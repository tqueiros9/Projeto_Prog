#include <stdio.h>

#include "estruturas.h"
#include "funcoes_principais.h"
#include "funcoes-secundarias.h"


int main(){

    int escolha_menu;

    Total_tipos_missao todos_tipos_missoes;//vigilancia, instrucao, etc
    Total_missoes todasAsMissoes;
    Total_militares todos_os_militares;
    Total_funcoes_mil todas_func_mil;


    iniciar_valores(&todas_func_mil, &todos_os_militares, &todasAsMissoes, &todos_tipos_missoes); //ir à secundária l17
    ler_dados_binario(&todos_os_militares,&todasAsMissoes);

    carregar_funcoes(&todas_func_mil);
    carregar_tipos_missao(&todos_tipos_missoes);


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
                ler_ficheiro_mil(&todos_os_militares, &todas_func_mil);
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


