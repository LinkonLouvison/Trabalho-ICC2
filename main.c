/*
NOME :  LINKON JOSE SANTOS LOUVISON NÚMERO USP 7143698
NOME: GUILHERME BALLONI             NÚMERO USP 7143510

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "busca.h"
#include "ordenacao.h"
#include <time.h>

#define  NumLinhas 1024



void menu1(void);
void menu2(void);

int main(void)
{
    //DECLARAÇÃO DAS VARIAVEIS UTILIZADAS NO PROGRAMA
    int i = 0, k = 0, n = 100000,operacoes = 0, coluna, encontrou=0,inserido=0, tipo_arquivo;
    char linha[NumLinhas];
    // ALOCAÇÃO DE MEMORIA PARA O VETOR UTILIZADO NO PROGRAMA 
    char **vet = (char **) malloc(n* sizeof(char*));  

    // VARIAVEL ARVORE DO TIBO ABB     
    ABB Arvore;

    // PRIMEIRO MENU DO PROGRAMA , AONDE O USUARIO DEVE IDENTIFICAR QUAL ARQUIVO QUER TRABALHAR
	menu1();
    scanf("%d",&tipo_arquivo);

    // LEITURA DOS ARQUIVOS QUE  SERÃO TRABALHOS NO PROGRAMA
    FILE* arquivo1 = fopen("paises-crescente.csv", "r");
    FILE* arquivo2 = fopen("paises-decrescente.csv", "r");
    FILE* arquivo3 = fopen("municipio-crescente.csv", "r");
    FILE* arquivo4 = fopen("municipio-decrescente.csv", "r");
    FILE* arquivo5 = fopen("paises-aleatorio.csv", "r");
    FILE* arquivo6 = fopen("municipio-aleatorio.csv", "r");

    // ARQUIVOS DE SAIDA DO PROGRAMA
    FILE* OrdenadoCounting = fopen("OrdenadoCounting.csv", "w");
    FILE* OrdenadoQuick = fopen("OrdenadoQuick.csv", "w");
    FILE* OrdenadoHeap = fopen("OrdenadoHeap.csv", "w");

    // TROCA O ARQUIVO DE TRABALHO DO PROGRAMA DE ACORDO COM A ESCOLHA DO USUARIO 
    switch( tipo_arquivo)
    {
    case 1:
        arquivo1 = arquivo1;
        break;
    case 2:
        arquivo1 = arquivo2;
        break;
    case 3:
        arquivo1 = arquivo3;
        break;
    case 4:
        arquivo1 = arquivo4;
        break;
     case 5:
        arquivo1 = arquivo5;
        break;
    case 6:
        arquivo1 = arquivo6;
        break;


    default:
        break;
    }



    // INICIALIZA A ARVORE BINARIA DE BUSCA
    iniciar_abb(&Arvore);

   for(i = 0; i < n; i++)
       vet[i] = malloc(1024 * sizeof(char) );

    i = 0;

   // CHAMAMOS O SEGUNDO MENU DO PROGRAMA, UTILIZADO PARA ESCOLHER QUAL COLUNA O USUARIO DESEJA TRABALHAR
    menu2();
    scanf("%d",&coluna);



        while (fgets(linha, 1024, arquivo1))
        {
            char* temp = strdup(linha);
            strcpy(vet[i],dados(temp, coluna));
             free(temp);
            i++;
            k++;
        }






        printf("\n### METODOS DE ORDENACAO ###\n");

    //COUNTING SORT 
    operacoes = 0;
    clock_t t = clock();
    countingsort(vet,k, &operacoes);
    t = clock() - t;
     for(i=0;i<k;i++)
        fprintf(OrdenadoCounting,"%s \n",vet[i]);
    printf("CountingSort  Numero de operacoes: %d\n",operacoes);
    printf("Tempo de ordenacao: %g ms\n", t * 1000.0 / CLOCKS_PER_SEC);

    //HEAPSORT
    operacoes = 0;
    t=clock();
    heapsort(vet,k, &operacoes);
    t=clock() -t;
    for(i=0;i<k;i++)
        fprintf(OrdenadoHeap,"%s \n",vet[i]);
    printf("Heapsort  Numero de operacoes: %d\n",operacoes);
    printf("Tempo de ordenacao: %g ms\n", t * 1000.0 / CLOCKS_PER_SEC);
    operacoes = 0;
    for(i = 0; i < k; i++) inserido = inserir_abb(&Arvore,vet[i]);

    //QUICKSORT
    operacoes = 0;
   t = clock();
     QuickSort(vet,k, &operacoes,PivoMediana);
    t = clock() - t;
     for(i=0;i<k;i++)
    fprintf(OrdenadoQuick,"%s \n",vet[i]);
    printf("Quick sort Pivo Mediana de 3  Numero de operacoes: %d\n",operacoes);
    printf("Tempo de ordenacao: %g ms\n", t * 1000.0 / CLOCKS_PER_SEC);
    t = clock();
     QuickSort(vet,k, &operacoes,PivoRandon);
    t = clock() - t;
     for(i=0;i<k;i++)
    fprintf(OrdenadoQuick,"%s \n",vet[i]);
    printf("Quick sort Pivo Randon Numero de operacoes: %d\n",operacoes);
    printf("Tempo de ordenacao: %g ms\n", t * 1000.0 / CLOCKS_PER_SEC);
     t = clock();
     QuickSort(vet,k, &operacoes,PivoMeio);
    t = clock() - t;
     for(i=0;i<k;i++)
    fprintf(OrdenadoQuick,"%s \n",vet[i]);
    printf("Quick sort Pivo Meio Numero de operacoes: %d\n",operacoes);
    printf("Tempo de ordenacao: %g ms\n", t * 1000.0 / CLOCKS_PER_SEC);

            printf("\n### METODOS DE BUSCA###\n");

    //BUSCA SEQUENCIAL
    operacoes = 0;
    t = clock();
    encontrou = busca_sequencial(vet,k,"France ",&operacoes);
    t = clock() - t;
    printf("Busca Sequencial Encontra na posicao: %d    Numero de operacoes: %d\n",encontrou,operacoes);
     printf("Tempo de Busca: %g ms\n", t * 1000.0 / CLOCKS_PER_SEC);


    //BUSCA BINARIA
    operacoes = 0;
    t = clock();
    encontrou = busca_binaria(vet,k,"France ",&operacoes);
    t = clock() - t;
    printf("Busca Binaria Encontra na posicao: %d  Numero de operacoes: %d\n",encontrou,operacoes);
    printf("Tempo de Busca: %g ms\n", t * 1000.0 / CLOCKS_PER_SEC);

    //BUSCA POR INTERPOLACAO - FUNCIONA APENAS PARA INTEIROS 
    operacoes = 0;
    t = clock();
    encontrou = busca_interpolacao(vet,k,"France ",&operacoes);
    t = clock() - t;
    printf("Busca Interpolacao Encontra na posicao: %d  Numero de operacoes: %d\n",encontrou,operacoes);
    printf("Tempo de Busca: %g ms\n", t * 1000.0 / CLOCKS_PER_SEC);

    //ARVORE BINARIA DE BUSCA 
    operacoes = 0;
    t = clock();
    encontrou = buscar_abb(Arvore,"France ", &operacoes);
    t = (clock() - t);
    printf("Busca Arvore Binaria Encontra: %d  e Numero de operacoes: %d\n",encontrou,operacoes);
    printf("Tempo de Busca: %g ms\n", t * 1000.0 / CLOCKS_PER_SEC);


    //LIBERA A MEMORIA ALOCADA PELA ARVORE DE BUSCA    
    liberar_abb(&Arvore);
    return 0;
}


//FUNÇÃO MENU  AONDE O USUARIO DEVE ESCOLHER QUAL ARQUIVO IRA REALIZAR A ORDENAÇÃO
void menu1(void)
{

    printf("         ###########################################################\n");
    printf("                Bem vindo ao trabalho de ordenacao e buscas  !!\n");
    printf("Escolha a qual arquivo voce deseja ordenar e buscar \n");
   	printf("digite 1 para realizar as verificacoes com o arquivo paises-crescente\n");
    printf("digite 2 para realizar as verificacoes com o arquivo paises-decrescente\n");
    printf("digite 3 para realizar as verificacoes com o arquivo municipio-crescente\n");
    printf("digite 4 para realizar as verificacoes com o arquivo municipio-decrescente\n");
    printf("digite 5 para realizar as verificacoes com o arquivo paises-aleatorio\n");
    printf("digite 6 para realizar as verificacoes com o arquivo municipio-aleatorio\n");
}


// FUNÇÃO EM QUE O USUARIO IRA ESCOLHER QUAL A COLUNA IRA REALIZAR A ORDENACAO
void menu2(void)
{

	printf("Escolha a coluna que voce deseja ordenar e buscar\n");
	printf("digite 1 para ordenar para a coluna 1 do arquivo\n");
	printf("digite 2 para ordenar para a coluna 2 do arquivo\n");
	printf("digite 3 para ordenar para a coluna 3 do arquivo\n");
    printf("digite 4 para ordenar para a coluna 4 do arquivo\n");


}
