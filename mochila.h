#include "leituradados.h"


int max(int a, int b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
/*Função que resolve o problema da mochila em O(nW),
 * usando programação dinamica e
 * retornando o valor da solucao encontrada
 *
 *
 * capacidade é a capacidade da mochila
 * orientacao é a faixa - se é horizontal ou vertical
 */
int mochila(int orientacao, int capacidade);
