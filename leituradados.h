#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct restricoes
{
    int ganho; /*Custo da faixa*/
    int memh; /*Quantidade de memoria da faixa vertical*/
    int memv; /*Quantidade de memoria da faixa vertical*/
} rest;

rest **custos;/*Estrutura de dados contendo as quantidades de memoria que cada segmento ocupa, bem como o custo nao-negativo associado*/
int **vetorb;  /*vetor de restricoes de memoria, horizontais e verticais*/
int **variaveis; /*matriz de variáveis*/
int numfaixas; /*Numero de faixas horizontal ou vertical*/
int numfrag; /*Numero de fragmentos com ganho nao-nulo*/

/*Leitura do arquivo de entrada*/
FILE* leitura_entrada(const char *nomearq[]);

/*Função que aloca os valores lidos do arquivo nas 
 * estruturas de dados correspondentes*/
void preenche_estruturas(FILE *file);

/*Função que aloca o vetor de custos*/
//void aloca_custos(int horizontal, int vertical, int custo);

/*Função que aloca o vetor b de coeficientes das restrições*/
void aloca_vetorb(FILE * file);

/*Função que aloca a matriz de coeficientes das restrições*/
//void aloca_matriza(int horizontal, int vertical, int coef);

/*Função que aloca a matriz de variáveis*/
void aloca_variaveis();

/*Aloca o numero de faixas*/
void aloca_numfaixas(FILE * file);

/*aloca o numero de fragmentos*/
void aloca_numfrag(FILE * file);

/*Função que aloca completamente a estrutura de custos e de coeficientes das restrições*/
void aloca_estruturas(FILE * file);
