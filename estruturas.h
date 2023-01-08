#ifndef ESTRUTURAS_TODAS
#define ESTRUTURAS_TODAS

#define MAX_NOME_FUNCAO 50
#define MAX_MISSOES 200
#define MAX_MILITARES 1000
#define MAX_TIPOS 10
#define FUNCOES_TRIP 7

//*******************************************************estruturas*****************************************************

typedef struct mission_type {
  char nome[MAX_NOME_FUNCAO];
  int cont_tripulantes_missao;
  int tipo_tripulantes[10]; // MUDAR ISTO <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
} Mission_type;

typedef struct tripulante {
  char nome[MAX_NOME_FUNCAO];
  int nip;    // numero de identificacao unico no formato XXXXXX
  int funcao; // funcao de cada tripulante, 1 piloto cmdt, 2 piloto, 3 nav, 4
              // load master,
  // 5 recuperador, 6 piloto instrutor, 7 aluno
  int estado; // O = OP, 1 = INOP
  int oper;   // data em que estara operacional no formato AAAAMMDD
  int horas_voo;
  int missoes; // numero total de missoes
  int data_missoes[200];

} Tripulante;

typedef struct voo {
  int n_voo;
  int data; // formato AAAAMMDD
  int tipo_de_missao;
  int cont_tripulantes;
  Tripulante conj_trip[10]; // MUDAR ESTE VALOR
                            // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
} Missao_unica;

typedef struct funcoes_mil {
  char mil_funcao[MAX_NOME_FUNCAO];

} tipos_funcoes_mil;

//*************** estruturas que definem conjutos das estruturas anteriores com
//um vetor e um contador *****************

typedef struct total_tipos_missao {
  Mission_type conj_tipos_missao[MAX_TIPOS];
  int cont_tipos_missao;
} Total_tipos_missao;

typedef struct missoes {
  Missao_unica conj_missoes[MAX_MISSOES];
  int cont_missoes;
} Total_missoes;

typedef struct militares {
  Tripulante total_tripulantes[MAX_MILITARES];
  int cont_militares;
} Total_militares;

typedef struct total_funcoes_mil {
  tipos_funcoes_mil todas_funcoes[MAX_TIPOS];
  int cont_funcoes
} Total_funcoes_mil;

#endif