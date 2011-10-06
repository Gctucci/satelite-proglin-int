#include "leituradados.h"

int main(int argc, const char *argv[])
{
    FILE * teste = NULL;
        printf("%s", argv[1]);
        teste = fopen(argv[1],"r");
    if(teste != NULL){
    aloca_vetorb(teste);
    int i,j;
    numfaixas = 8;
    
        for (j = 0; j < 8; j++) {

    printf("%d\n",vetorb[0][j]);        }
        
    }
    else{
        printf("Fudeu\n");
    }
    fclose(teste);
    return 0;
}
