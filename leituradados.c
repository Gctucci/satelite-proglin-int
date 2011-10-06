#include "leituradados.h"




/*Leitura do arquivo de entrada*/
FILE* leitura_entrada(const char *nomearq[])
{
    FILE *file = NULL;
    file = fopen(nomearq[1], "r");
    printf("%s",nomearq[1]);

    return file;
}

/*Aloca o numero de faixas*/
void aloca_numfaixas(FILE * file)
{
   //Le o numero de faixas do arquivo
        fscanf(file,"%d",&numfaixas); 
}

/*Função que aloca o vetor de custos*/
void aloca_custos()
{
}

/*Função que aloca o vetor b de coeficientes das restrições*/
void aloca_vetorb(FILE * file)
{
    int i;
    int j=0;
    char espaco;
    int valor;

      /*Alocação do vetor b, para linhas horizontais e verticais -
     * vetorb[1] sao as linhas horizontais
     * vetorb[2] sao as linhas verticais
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
        printf("Houve um erro ao ler o arquivo.\n");
    }
}

/*Função que aloca a matriz de coeficientes das restrições*/
void aloca_matriza();

/*Função que aloca a matriz de variáveis*/
void aloca_variaveis();

void aloca_numfrag(FILE *file)
{
        fscanf(file, "%d", &numfrag);
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

        //Fecha o arquivo em questão
        fclose(file);
    }
    else
    {
        printf("Houve um problema ao abrir o arquivo.\n");
        
    }
}






