#ifndef ESTRUTURAS_TODAS
#define ESTRUTURAS_TODAS

#define MAX_NOME_FUNCAO 25
#define MAX_MISSOES 100
#define MAX_MILITARES 1000
#define MAX_TIPOS 10
#define FUNCOES_TRIP 7

//*******************************************************ESTRUTURAS*****************************************************

typedef struct mission_type {           //a estrutura mission_type tem 3 variáveis char, int, int
    char nome [MAX_NOME_FUNCAO];        //[] é o tamanho que está definido em cima
    int cont_tripulantes_missao;
    int tipo_tripulantes[MAX_TIPOS];
}Mission_type;

typedef struct tripulante {
    char nome [MAX_NOME_FUNCAO];
    int nip; //numero de identificacao unico no formato XXXXXX
    int funcao; //funcao de cada tripulante, por exemplo 1 piloto cmdt, 2 piloto, 3 nav, 4 load master,5 recuperador, 6 piloto instrutor, 7 aluno
    int estado; //O = OP, 1 = INOP
    int oper;  //data em que estara operacional no formato AAAAMMDD
    int horas_voo;
    int missoes; //numero total de missoes
    int data_missoes[MAX_MISSOES];
    int n_missoes;
}Tripulante;

typedef struct voo {
    int n_voo; //numero de voo, se quisermos ver um numero de voo em expecifico
    int data; //formato AAAAMMDD
    int tipo_de_missao;
    int cont_tripulantes;
    Tripulante conj_trip [MAX_TIPOS]; //vetor do tipo "tripulantes" com nome "conjunto detripulantes" [] tamanho
}Missao_unica;

typedef struct funcoes_mil{
    char mil_funcao[MAX_NOME_FUNCAO]; //tipo de funções que cada militar pode ter
}tipos_funcoes_mil;

//*************** estruturas que definem conjutos das estruturas anteriores com um vetor e um contador ***************//

typedef struct total_tipos_missao {
    Mission_type conj_tipos_missao[MAX_TIPOS]; //[mission_type1] [mission_type2] [mission_type3]....
    int cont_tipos_missao;                     //var: conj_tipos_missão é = [] [] []
}Total_tipos_missao;

typedef struct missoes{
    Missao_unica conj_missoes [MAX_MISSOES];
    int cont_missoes;
}Total_missoes;

typedef struct militares{
    Tripulante total_tripulantes [MAX_MILITARES];
    int cont_militares;
}Total_militares;

typedef struct total_funcoes_mil{
    tipos_funcoes_mil todas_funcoes [FUNCOES_TRIP];
    int cont_funcoes;
}Total_funcoes_mil;

#endif