#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int **custos; /*vetor de custos*/
int **vetorb;  /*vetor de restricoes de memoria, horizontais e verticais*/
int **matriza; /*matriz de coeficientes da primeira retriçao*/
int **variaveis; /*matriz de variáveis*/
int numfaixas; /*Numero de faixas horizontal ou vertical*/
int numfrag; /*Numero de fragmentos com ganho nao-nulo*/

/*Leitura do arquivo de entrada*/
FILE* leitura_entrada(const char *nomearq[]);

/*Função que aloca os valores lidos do arquivo nas 
 * estruturas de dados correspondentes*/
void preenche_estruturas(FILE *file);

/*Função que aloca o vetor de custos*/
void aloca_custos();

/*Função que aloca o vetor b de coeficientes das restrições*/
void aloca_vetorb(FILE * file);

/*Função que aloca a matriz de coeficientes das restrições*/
void aloca_matriza();

/*Função que aloca a matriz de variáveis*/
void aloca_variaveis();

/*Aloca o numero de faixas*/
void aloca_numfaixas(FILE * file);

/*aloca o numero de fragmentos*/
void aloca_numfrag(FILE * file);

