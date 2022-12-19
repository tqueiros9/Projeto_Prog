#ifndef ESTRUTURAS_TODAS
#define ESTRUTURAS_TODAS

#define MAX_NOME_FUNCAO 50
#define MAX_MISSOES 200
#define MAX_MILITARES 1000
#define MAX_TIPOS_MISSOES 10

//*******************************************************estruturas*****************************************************

typedef struct mission_type {
    char nome [MAX_NOME_FUNCAO];
    int cont_tripulantes_missao;
    int tipo_tripulantes;
}Mission_type;

typedef struct tripulante {
    int nip; // numero de identificacao unico no formato XXXXXX
    char nome [MAX_NOME_FUNCAO];
    char funcao [MAX_NOME_FUNCAO]; //funcao de cada tripulante, 1 piloto cmdt, 2 piloto, 3 nav, 4 load master, 5 recuperador, 6 piloto instrutor, 7 aluno
    int estado; //O = OP, 1 = INOP
    int oper[3]; //data em que estara operacional no formato [AAAA,MM,DD]
    int horas_voo;
    int missoes; //numero total de missoes

}Tripulante;

typedef struct voo {
    char nome_missao [MAX_NOME_FUNCAO];
    int n_voo;
    int data[3]; //formato AAAAMMDD
    Tripulante conj_trip [];
}Missao_unica;

//*************** estruturas que definem conjutos das estruturas anteriores com um vetor e um contador *****************

typedef struct total_tipos_missao {
    Mission_type conj_tipos_missao[MAX_TIPOS_MISSOES];
    int cont_tipos_missao;
}Total_tipos_missao;

typedef struct missoes{
    Missao_unica conj_missoes [MAX_MISSOES];
    int cont_missoes;
}Total_missoes;

typedef struct militares{
    Tripulante total_tripulantes [MAX_MILITARES];
    int cont_militares;
}Total_militares;




#endif