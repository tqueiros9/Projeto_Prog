#include <stdio.h>

#define MAX_TRIP 100




/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
               DEMO BINARIOS
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
typedef struct {
    char nome[50];
    int nip;
} Tripulante;

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
}
