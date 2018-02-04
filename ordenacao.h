/*
NOME :  LINKON JOSE SANTOS LOUVISON NÚMERO USP 7143698



*/



typedef char *Elem;


// PROPOTIPOS DAS FUNÇÕES UTILIZADAS NO PROGRAMA 

// FUNÇÃOES UTILIZADAS PARA REALIZAR O HEAPSORT
void rearranja(Elem *, int , int ,int *);
void constroi(Elem *, int , int *);
void heapsort(Elem *, int , int *);

// FUNÇÕES UTILIZADAS  PARA REALIZAR O QUICKSORT
//TYPEDEF UTILIZADO PARA DEIXAR A DECLARACAO MENOR 
typedef int (*EscolhePivo)(Elem*,int,int,int*);
int PivoMediana(Elem *,int ,int , int *);
int PivoRandon(Elem *,int ,int, int *);
int PivoMeio(Elem *,int ,int ,int *);
void particao(Elem *, int , int , int *, int *,int *,EscolhePivo);
void quick_ordena(Elem *v, int , int ,int *,EscolhePivo);
void QuickSort(Elem *, int , int *,EscolhePivo);

// ORDENAÇÃO POR COUTING SORT
void countingsort(Elem *, int , int *);


