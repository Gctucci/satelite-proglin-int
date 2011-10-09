#include "mochila.h"



/*Função que resolve o problema da mochila em O(nW),
 * usando programação dinamica e
 * retornando o valor da solucao encontrada
 *
 *
 * capacidade é a capacidade da mochila
 * orientacao é a faixa - se é horizontal ou vertical
 */
int mochila(int orientacao, int capacidade)
{
    int i,j,a,b;
    int t[capacidade+1][capacidade+1];
    for (i = 0; i <= capacidade; i++) {
        t[0][i] = 0;
        for (j = 1; j <= numfrag; j++) {
            a = t[j-1][i];
            if(orientacao ==1)
            {
                if(custos[j].memh > i)
                {
                    b=0;
                }
                else
                {
                    b = (t[j-1][i-(custos[j].memh)] + custos[j].ganho);
                }
                t[j][i] = max(a,b);
            }
            else
            {
                if(custos[j].memh > i)
                {
                    b=0;
                }
                else
                {
                   b = (t[j-1][i-(custos[j].memv)] + custos[j].ganho); 
                }
                t[j][i] = max(a,b);
            }
            
        }
    
    }
    j = capacidade;
    for (j = numfrag; j >= 1; j--)
    {
            if(t[j][i] == t[i-1][i])
            {
                variaveis[j] = 0;
            }
            else
            {
                variaveis[j] = 1;
            }
            i -= capacidade;
    }
    return t[capacidade][capacidade];
}
