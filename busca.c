/*
NOME :  LINKON JOSE SANTOS LOUVISON NÚMERO USP 7143698
NOME :  GUILHERME BALLONI           NÚMERO USP 7143510


*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "busca.h"



//CRIA A ARVORE BINARIA DE BUSCA
void iniciar_abb(ABB *A) {
     *A=NULL;
}

//LIBERA A MEMORIA DA ARVORE BINARIA DE BUSCA
void liberar_abb(ABB *p) {
     if (*p!=NULL) {
        liberar_abb(&(*p)->esq);
        liberar_abb(&(*p)->dir);
        free(*p);
     }
}

//BUSCA ELEMENTO NA ARVORE BINARIA DE BUSCA
int buscar_abb(ABB p, Elem x, int *complexidade) {
    (*complexidade)++;
    if (p==NULL)
       return 0;
    else if (strcmp(x,p->info) < 0)
         return(buscar_abb(p->esq,x,complexidade));
    else if (strcmp(x,p->info) > 0)
         return(buscar_abb(p->dir,x,complexidade));
    else return 1;
}

//BUSCA SEQUENCIAL
int busca_sequencial(Elem *v, int n, Elem procurado,int *complexidade){
    int  i;
    for(i = 0; i < n; i++){
        (*complexidade)++;
        if(strcmp(v[i],procurado) == 0)
            return i;
    }

    return -1;
}


//INSERI NA ARVORE BINARIA DE BUSCA
int inserir_abb(ABB *p, Elem x) {
     if (*p==NULL) {
        *p=(no*) malloc(sizeof(no));
       (*p)->info = x;
        (*p)->esq=NULL;
        (*p)->dir=NULL;
        return 1;
     }
     else if (strcmp(x,(*p)->info) <0)
          return(inserir_abb(&(*p)->esq,x));
     else if (strcmp(x,(*p)->info) > 0)
          return(inserir_abb(&(*p)->dir,x));
     else return 0;
}







//BUSCA BINARIA  INTERATIVA
int busca_binaria (Elem *v, int n,Elem x,int *complexidade) {
   int esq, meio, dir;
   esq = -1; dir = n;
   while (esq < dir-1) {
      meio = (esq + dir)/2;
      (*complexidade)++;
      if (strcmp(v[meio],x) < 0 ) esq = meio;
      else dir = meio;
   }
   return dir;
}

// PEGA A COLUNA DO ARQUIVO QUE ESTA SENDO SEPARADO POR UM PONTO E VIRGULA
const char* dados(char* linha, int coluna)
{
    const char* ponto_e_virgula;
    for (ponto_e_virgula = strtok(linha, ";");
            ponto_e_virgula && *ponto_e_virgula;
            ponto_e_virgula = strtok(NULL, ";\n"))
    {
        if (!--coluna)
            return ponto_e_virgula;
    }
    return NULL;
}


//BUSCA POR INTERPOLAÇÃO , SÓ FUNCIONA PARA NUMEROS INTEIROS
int busca_interpolacao (Elem *v, int n, Elem x, int *complexidade)
{
  int menor = 0;
  int maior = n - 1;
  int meio;
  while (strcmp(v[menor],x) <= 0 && strcmp(v[maior], x) >= 0)
  {
    (*complexidade)++;
    meio = menor + ((atoi(x) - atoi(v[menor])) * (maior - menor)) / (atoi(v[maior]) - atoi(v[menor]));
    if (strcmp(v[meio], x) < 0)
    {
      menor = meio + 1;
    }
    else if (strcmp(v[meio], x) < 0)
    {
      menor = meio - 1;
    }
    else
    {
      return meio;
    }
  }

  if (strcmp(v[menor], x) == 0)
  {
    return menor;
  }
  else
  {
    return -1;
  }
}

