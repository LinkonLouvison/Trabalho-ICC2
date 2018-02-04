/*
NOME :  LINKON JOSE SANTOS LOUVISON NÚMERO USP 7143698



*/

// STRUTC DA ARVORE BINARIA DE BUSCA

typedef char *Elem;

typedef struct bloco {
        Elem info;
        struct bloco *esq, *dir;
} no;

typedef no *ABB;




// PROPOTIPOS DAS FUNÇÕES UTILIZADAS NO PROGRAMA 



// FUNÇÕES DA ARVORE BINARIA DE BUSCA 
void iniciar_abb(ABB *);
void liberar_abb(ABB *);
int buscar_abb(ABB , Elem , int *);
int inserir_abb(ABB *, Elem );



// BUSCA SEQUENCIA 
int busca_sequencial(Elem *, int , Elem ,int *);



// BUSCA SEQUENCIA 
int busca_sequencial_com_sentinela(Elem *, int , Elem ,int *);

// BUSCA BINARIA 

// BUSCA BINARIA 
int busca_binaria (Elem *, int ,Elem ,int *);

// BUSCA POR INTERPOLAÇÃO 
int busca_interpolacao (Elem *, int , Elem , int *);

const char* dados(char* , int );
