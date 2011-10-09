#include "leituradados.h"


/*Leitura do arquivo de entrada*/
FILE* leitura_entrada(const char *nomearq[])
{
    FILE *file = NULL;
    file = fopen(nomearq[1], "r");
   // printf("%s",nomearq[1]);

    return file;
}

/*Aloca o numero de faixas*/
void aloca_numfaixas(FILE * file)
{
    if(file !=NULL)
    {
        //Le o numero de faixas do arquivo
        fscanf(file,"%d",&numfaixas); 

    }
    else
    {
        printf("Houve um problema ao abrir o arquivo.\n");
        exit(-1);
    }
}

/*Função que aloca o vetor de custos
void aloca_custos(int horizontal, int vertical, int custo)
{
    if(custos!=NULL)
    {
        custos[horizontal][vertical] = custo;

    }
    else
    {
        printf("Houve um erro ao alocar os custos.\n");
        exit(-1);
    }
}
*/

/*Função que aloca o vetor b de coeficientes das restrições*/
void aloca_vetorb(FILE * file)
{
    int i;
    int j=0;
    char espaco;
    int valor;

      /*Alocação do vetor b, para linhas horizontais e verticais -
     * vetorb[0] - conjunto de faixas horizontais
     * vetorb[1] - conjunto de faixas verticais
     * O numero de valores é o numero de faixas (numfaixas)*/
    vetorb = (int **)malloc(2*sizeof(int*));
    for (i = 0; i < 2; i++) {
        vetorb[i] = (int *)malloc(numfaixas*sizeof(int));

    }

    /*Abaixo a função le os arquivos de entrada para o vetor b*/
    if(file !=NULL){
        do{
            fscanf(file, "%d", &valor);
            fscanf(file,"%c",&espaco);
            fscanf(file,"%d",&vetorb[0][valor-1]);
            fscanf(file,"%c",&espaco);
        }while (espaco != '\n');
        do{
            fscanf(file, "%d", &valor);
            fscanf(file,"%c",&espaco);
            fscanf(file,"%d",&vetorb[1][valor-1]);
            fscanf(file,"%c",&espaco);
        }while (espaco != '\n');
        /*fscanf(file, "%c", &c);    
        while (fscanf(file,"%c",&c) != '\n')
        {

            fscanf(file,"%c",&c);      
            fscanf(file,"%d", &vetorb[1][j]);
            j++;
        
        }
        j=0;
        fscanf(file, "%c", &c);
        while (fscanf(file,"%c",&c) != '\n')
        {
        
            fscanf(file, "%c", &c);        
            fscanf(file,"%d", &vetorb[2][j]);
            j++;
        
        }*/
    }
    else
    {
        printf("Houve um problema ao ler o arquivo.\n");
        exit(-1);
    }
}

/*Função que aloca a matriz de coeficientes das restrições
void aloca_matriza(int horizontal, int vertical, int coef)
{
    if(matriza !=NULL)
    {
        matriza [horizontal][vertical] = coef;
    }
    else
    {
        printf("Houve um erro ao acessar a matriz de coeficientes das restrições.\n");
        exit(-1);
    }

}*/

/*Função que aloca a matriz de variáveis*/
void aloca_variaveis();

void aloca_numfrag(FILE *file)
{
        if(file !=NULL)
        {
            fscanf(file, "%d", &numfrag);

        }
        else
        {
            printf("Houve um problema ao abrir o arquivo.\n");
            exit(-1);
        }
}

/*Função que aloca completamente o vetor de custos e o de coeficientes da
 * restrições
void aloca_estruturas(FILE *file)
{
    char c;
    int i,h,v;

    //Aloca a estrutura de custos
    custos=(rest **)malloc(numfaixas*sizeof(rest*));
    for (i = 0; i < numfaixas; i++) {
        custos[i]=(rest *)malloc(numfaixas*sizeof(rest));
        
    }

    if(file !=NULL)
    {
        for (i = 0; i < numfrag; i++) {
            fscanf(file,"%d",&h);
            fscanf(file,"%c",&c);
            fscanf(file,"%d",&v);
            fscanf(file,"%c",&c);
            fscanf(file,"%d",&(custos[h-1][v-1].ganho));
            fscanf(file,"%c",&c);
            fscanf(file,"%d", &(custos[h-1][v-1].memh));
            fscanf(file,"%c",&c);
            fscanf(file,"%d", &(custos[h-1][v-1].memv));
            fscanf(file,"%c",&c);
            
        }
    }
}
*/

/*Função que aloca completamente o vetor de custos e o de coeficientes da
 * restrições*/
void aloca_estruturas(FILE *file)
{
    char c;
    int i,h,v;

    //Aloca a estrutura de custos
    custos=(rest *)malloc(numfaixas*sizeof(rest));

    if(file !=NULL)
    {
        for (i = 0; i < numfrag; i++) {
            fscanf(file,"%d",&(custos[i].h));
            fscanf(file,"%c",&c);
            fscanf(file,"%d",&(custos[i].v));
            fscanf(file,"%c",&c);
            fscanf(file,"%d",&(custos[i].ganho));
            fscanf(file,"%c",&c);
            fscanf(file,"%d", &(custos[i].memh));
            fscanf(file,"%c",&c);
            fscanf(file,"%d", &(custos[i].memv));
            fscanf(file,"%c",&c);
            
        }
    }
}

/*Função que aloca os valores lidos do arquivo nas 
 * estruturas de dados correspondentes*/
void preenche_estruturas(FILE *file)
{
    if(file !=NULL)
    {
        aloca_numfaixas(file);
        aloca_vetorb(file);
        aloca_numfrag(file);
        aloca_estruturas(file);
        //Fecha o arquivo em questão
        fclose(file);
    }
    else
    {
        printf("Houve um problema ao abrir o arquivo.\n");
        exit(-1);
    }
}






