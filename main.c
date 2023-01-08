#include <stdio.h>

#include "estruturas.h"
#include "funcoes_principais.h"
#include "funcoes-secundarias.h"


#define MAX_TRIP 100
/*void print_trip_file(FILE * fp){
    int n, trip_counter;
    Tripulante t;
    // fp é um apontador de FILE já aberto em modo que suporta leitura binária


    //rewind inicio do ficheiro
    rewind(fp);
    // o primeiro dado do ficheiro é um número inteiro com o número de tripulantes
    fread(&n, sizeof(int), 1, fp);


    // posteriormente, seguem-se todos os tripulantes
    // verificar que o número de tripulantes lidos é efetivamente o indicado
    //     no número inteiro inicial
    // rewind do ficheiro, para voltar ao inicio
    // ler um inteiro do ficheiro
    // ler todos os tripulantes, um a um
    for (trip_counter = 0; fread(&t, sizeof (Tripulante), 1, fp) != 0 ; trip_counter++) {
        print_trip(&t);

    }
    if (n != trip_counter){
        printf("ERRO");
    }

    // parar de ler tripulantes quando fread devolver 0
    // comparar se o número de tripulantes total lido é igual ao inteiro lido do inicio do ficheiro
}*/


/*int print_trip_idx(FILE *fp, int idx){
    Tripulante t;
    rewind(fp);
    // fp é um apontador de FILE já aberto em modo que suporta leitura binária
    // idx é o índice do Tripulante que queremos ler
    fseek(fp, sizeof (int) + sizeof (Tripulante) * idx, SEEK_SET);

    fread(&t, sizeof (Tripulante), 1, fp);
    print_trip(&t);
}*/


/*void trip_file_swap(FILE * fp, int idx1, int idx2){
    // fp é um apontador de FILE já aberto em modo que suporta leitura e escrita binária
    // idx1 e idx2 são índices de Tripulantes no ficheiro
    // esta função troca os dois tripulantes
}*/


/*int main_demo_bin(){
    Tripulante t1 = {"Saramago", 136787};
    Tripulante t2 = {"Asimov", 136786};
    Tripulante t3 = {"Hofstader", 136788};
    char filename[] = "tripulantes.bd";
    Tripulante tripulacao[MAX_TRIP];
    tripulacao[0] = t1;
    tripulacao[1] = t2;
    tripulacao[2] = t3;
    FILE * fp, *fp2;
    // vamos escrever um tripulante no ficheiro binário
    fp = fopen("tripulantes.db", "wb");
    if(fp == NULL){
        printf("Abertura de ficheiro incorrecta.\n");
        return 1;
    }
    else {
        int n=3;
        printf("Ficheiro aberto.");
        fwrite(&n, sizeof(int), 1, fp);
        fwrite(tripulacao, sizeof(Tripulante), n, fp);
        fclose(fp);
    }
    // vamos ler esse tripulante do ficheiro binário
    fp = fopen("tripulantes.db", "rb");
    if(fp == NULL){
        printf("Abertura de ficheiro incorrecta.\n");
        return 1;
    }
    else {
        printf("Ficheiro aberto.");
        print_trip_idx(fp, 2);
        print_trip_file(fp);
        fclose(fp);
    }
}*/



int main(){



    int escolha_menu;
    Total_tipos_missao todos_tipos_missoes;
    //Total_missoes todas_as_missoes;
    Total_militares todos_os_militares;
    Total_funcoes_mil todas_func_mil;

    //iniciar_valores(&todas_func_mil, &todos_os_militares, &todas_as_missoes, &todos_tipos_missoes);

    //char linha[] ="129888;Ivo Alves;Piloto comandante;OP;-1;100;20";
    //adicionar_dados_militares(linha, &todos_os_militares, &todas_func_mil);


    //--------------zona teste de dados

    char filename_mil[] = "militares.bin";
    char filename_mis[] = "missoes.bin";

    FILE * fp, *fp2;
    fp = fopen(filename_mil, "rb");
    if(fp == NULL){
        printf("Abertura de ficheiro incorrecta.\n");
        //return;
    }
    else {

        printf("Ficheiro aberto.");
        fread(&todos_os_militares.cont_militares, sizeof(int), 1, fp);
        fread(todos_os_militares.total_tripulantes, sizeof(todos_os_militares.total_tripulantes[0]), todos_os_militares.cont_militares, fp);
        fclose(fp);
    }

    //printf("%s", todos_os_militares.total_tripulantes[0].nome);





   /* todos_os_militares.cont_militares=0;
    todas_func_mil.cont_funcoes=0;
    todos_tipos_missoes.cont_tipos_missao=0;*/

    Tripulante at_at = {"tiago", 141914,0,0,-1,2,2,20221112,20221211};
    Tripulante gm_gm = {"guilherme", 141916, 0,1,20230120,2,1,20221112};
    todos_os_militares.total_tripulantes[0] = at_at;
    todos_os_militares.total_tripulantes[1] = gm_gm;
    todos_os_militares.cont_militares=2;

    Mission_type ser_padeiro = {"bater charuto", 2, 0,0};
    todos_tipos_missoes.conj_tipos_missao[0] = ser_padeiro;
    todos_tipos_missoes.cont_tipos_missao = 1;

  //  Missao_unica viagem_ao_espaco = {1001, 20221112, 0, 2, at_at, gm_gm};




    tipos_funcoes_mil ab_ab = {"padeiro"};
    todas_func_mil.todas_funcoes[0] = ab_ab;
    todas_func_mil.cont_funcoes=1;




    //------------------





    imprimir_menu();
    scanf("%d",&escolha_menu);
    while(escolha_menu!=5){

        switch (escolha_menu) {

            case 1:
     //          marcar_missao(&todas_as_missoes, &todos_tipos_missoes, &todos_os_militares, &todas_func_mil);
                break;
            case 2:
            //   listar_missoes(&todas_as_missoes, &todos_tipos_missoes, &todas_func_mil);
                break;
            case 3:
                listar_tripulantes(&todos_os_militares, &todas_func_mil);

                break;
            case 4:
                //atualizar estado militares
                atualizar_estado(&todos_os_militares);

                break;
            case 5:
                //adicionar ficheiro à BD
                break;
            case 6:
                //guardar_dados_binario(&todos_os_militares, &todas_as_missoes);

                fp = fopen(filename_mil, "wb");
                if(fp == NULL){
                    printf("Abertura de ficheiro incorrecta.\n");
                    // return;
                }
                else {

                    printf("Ficheiro aberto.");
                    fwrite(&todos_os_militares.cont_militares, sizeof(int), 1, fp);
                    fwrite(todos_os_militares.total_tripulantes, sizeof(todos_os_militares.total_tripulantes[0]), todos_os_militares.cont_militares, fp);
                    fclose(fp);
                }

                fp = fopen(filename_mis, "wb");
                if(fp == NULL){
                    printf("Abertura de ficheiro incorrecta.\n");
                    //return;
                }



                return 0;
            default:
                printf("escolha invalida, nao existe essa opcao no menu");
        }

        imprimir_menu();
        scanf("%d",&escolha_menu);
    }








}
