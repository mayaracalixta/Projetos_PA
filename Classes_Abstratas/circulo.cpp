#include "circulo.h"
#include <cmath>

/**
 * @brief Circulo::Circulo Construtor da classe circulo
 * @param _x - Coordenada x do centro
 * @param _y - Coordenada y do centro
 * @param r - Raio do circulo
 * @param p -Variavel responsavel por verificar se o circulo sera preenchido ou nao
 */

Circulo::Circulo(int _x, int _y, int r, int p)
{
    x = _x;
    y=_y;
    raio = r;
    preenchido = p;
}

/**
 * @brief Circulo::draw - Desenha o circulo na tela
 * @param t - Responsavel por inserir o circulo no painel(matriz) alocada na classe Screen
 */
void Circulo::draw(Screen &t)
{
    /*A base de raciocinio para a criação do circulo é o algoritmo de Bresenham
*/
    int inicx = x-raio;
    int fimx = x+raio;
    int inicy = y-raio;
    int fimy = y+raio;
    int calc;

    for(int i=inicx; i<=fimx; i++)
    {
        for(int j=inicy;j<=fimy;j++)
        {
            calc=round(sqrt(pow(j-y,2)+pow(i-x, 2)));

            if(preenchido==1) //Verifica se o circulo sera preenchido
            {
                if(calc<=raio)
                {
                     t.setPixel(i, j);
                }
            }
            else
            {
                if(calc==raio)
                {
                    t.setPixel(i, j);
                }
            }
        }
    }
}




