/*
NOME :  LINKON JOSE SANTOS LOUVISON NÚMERO USP 7143698
NOME :  GUILHERME BALLONI           NÚMERO USP 7143510


*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordenacao.h"
#include "busca.h"


 int PivoMediana(Elem *vet,int InitVet,int FimVet, int *c){
    Elem middle=vet[(InitVet+FimVet)/2]; //não exatamente o meio se o vetor for impar...
    Elem first  = vet[InitVet];
    Elem last  = vet[FimVet];

 if (strcmp(first, middle)==-1&&strcmp(first, middle)==0){

      (*c)++;
      return first;
 }

    if (strcmp(first, last)==-1&&strcmp(first, last)==0)  {
        // middle - first - last
          (*c)++;
        return first;
    } else if  (strcmp(middle, last)==-1&&strcmp(middle, last)==0) {
        // middle - last - first
        (*c)++;
        return last;
    }
    // last - middle - first
    (*c)++;
    return vet[(InitVet+FimVet)/2];
}


int PivoRandon(Elem vet[],int InitVet,int FimVet, int *c){

    (*c)++;
    return vet[InitVet + rand()%(FimVet-InitVet)];

}

int PivoMeio(Elem vet[],int InitVet,int FimVet,int *c){
    (*c)++;
    return vet[(InitVet+FimVet)/2];
}
//FUNÇÃO DO QUICKSORT QUE FAZ O PARTICIONAMENTO POR ELEMENTO DO MEIO COMO PIVO
void particao(Elem *v, int esq, int dir, int *i, int *j,int *c,EscolhePivo P) {
    Elem pivo, aux;

    *i = esq; *j = dir;
    pivo = P(v,esq,dir,c);
    do {
        while (strcmp(pivo,v[*i]) > 0){
            (*i)++;
            (*c)++;
        }
        while (strcmp(pivo,v[*j]) < 0){
            (*j)--;
            (*c)++;
        }
        if (*i <= *j) {
            (*c)++;
            aux = v[*i];
            v[*i] = v[*j];
            v[*j] = aux;
            (*i)++; (*j)--;
        }
    } while (*i <= *j);
}

//FAZ O PARTICIONAMENTO E A ORDENAÇÃO DO QUICKSORT
void quick_ordena(Elem *v, int esq, int dir,int *c,EscolhePivo P) {
    int i, j;
    particao(v, esq, dir, &i, &j,c,P);
    if (esq < j) quick_ordena(v, esq, j,c,P);
    if (i < dir) quick_ordena(v, i, dir,c,P);
}

//CHAMA A FUNÇÃO QUICK-ORDENA
void QuickSort(Elem *v, int n, int *c,EscolhePivo P) {
    quick_ordena(v, 0, n-1,c,P);
}




//REARRANJA PARA O HEAPSORT
void rearranja(Elem *v, int k, int N,int *c) {
    Elem aux;
     int i,j;
     while(2*k <= N) {
     j = 2*k;
    (*c)++;

     if(j < N && strcmp(v[j],v[j+1]) < 0) {
          j++;
     }
     if(strcmp(v[k],v[j]) >= 0 ) {
            break;
     }
        aux = v[k];
        v[k] = v[j];
        v[j] = aux;
        k = j;
     }
}

//CONSTROI O HEAPSORT
void constroi(Elem *v, int n, int *c) {
     int k = n/2;
     while(k >= 1) {
     rearranja(v, k, n, c);
     k--;
     }
}

//HEAPSORT
void heapsort(Elem *v, int n, int *c) {
    Elem aux;
    constroi(v, n,c);
     int k = n;
     while(k >= 0) {
         (*c)++;
         aux = v[0];
        v[0] = v[k];
        v[k] = aux;
     k--;
     rearranja(v, 0, k,c);
     }
}

//COUTING SORT
void countingsort(Elem *v, int n, int *c){
    int x[n], i, j;
    Elem b[n];

    for(i=0; i<n; i++){
        x[i]=0;
    }

    for(i=1; i<n; i++){
        for(j=i-1; j>=0; j--){
            (*c)++;
            if(strcmp(v[i],v[j]) < 0)
                x[j]++;
            else x[i]++;
        }
    }

    for(i=0;i<n;i++){
        b[x[i]]=v[i];
    }

    for(i=0;i<n;i++){
        v[i]=b[i];
    }
}
