#include <stdio.h>

#define MAX_TRIP 100
#define MAX_NOME_FUNCAO 100
#define MAX_MISSOES 200

//estruturas******************************************

typedef struct tripulante {
    int nip; // numero de identificacao unico no formato XXXXXX
    char nome [MAX_NOME_FUNCAO];
    char funcao [MAX_NOME_FUNCAO]; //funcao de cada tripulante, 1 piloto cmdt, 2 piloto, 3 nav, 4 load master, 5 recuperador, 6 piloto instrutor, 7 aluno
    int estado; //O = OP, 1 = INOP
    int oper; //data em que estara operacional no formato AAAAMMDD
    int horas_voo;
    int missoes; //numero total de missoes

}Tripulante;

typedef struct voo {
    char nome_missao [MAX_NOME_FUNCAO];
    int n_voo;
    int data; //formato AAAAMMDD
    Tripulante conj_trip [];


}Missao_unica;

typedef struct missoes{
    int cont_missoes;
    Missao_unica conj_missoes [MAX_MISSOES];
}Missoes;

struct tm{
    int tm_sec;         /* seconds,  range 0 to 59          */
    int tm_min;         /* minutes, range 0 to 59           */
    int tm_hour;        /* hours, range 0 to 23             */
    int tm_mday;        /* day of the month, range 1 to 31  */
    int tm_mon;         /* month, range 0 to 11             */
    int tm_year;        /* The number of years since 1900   */
    int tm_wday;        /* day of the week, range 0 to 6    */
    int tm_yday;        /* day in the year, range 0 to 365  */
    int tm_isdst;       /* daylight saving time             */
};

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
               DEMO BINARIOS
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void marcar_missao(Missoes * total_missoes){

    printf("\n Escolha o tipo de missao:\n 1- \n 2- \n 3- \n");

}

void print_trip(Tripulante * t){
    printf("\n--Trip--\n");
    printf("nome: %s\n", t->nome);
    printf("nip:%d\n", t->nip);
    printf("--------------\n");
}

void print_trip_file(FILE * fp){
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
}


int print_trip_idx(FILE *fp, int idx){
    Tripulante t;
    rewind(fp);
    // fp é um apontador de FILE já aberto em modo que suporta leitura binária
    // idx é o índice do Tripulante que queremos ler
    fseek(fp, sizeof (int) + sizeof (Tripulante) * idx, SEEK_SET);

    fread(&t, sizeof (Tripulante), 1, fp);
    print_trip(&t);
}


void trip_file_swap(FILE * fp, int idx1, int idx2){
    // fp é um apontador de FILE já aberto em modo que suporta leitura e escrita binária
    // idx1 e idx2 são índices de Tripulantes no ficheiro
    // esta função troca os dois tripulantes
}


int main_demo_bin(){
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
        fwrite(tripulacao, sizeof(Tripulante), 3, fp);
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
}


int main(){
    //main_demo_txt();
    main_demo_bin();
    printf("git test");
}
