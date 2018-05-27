#include "reta.h"
#define sgn(x) ((x<0)?-1:((x>0)?1:0))
/**
 * @brief Reta::Reta
 * @param _x1 - Coordenada X do ponto inicial
 * @param _y1 - Coordenada y do ponto inicial
 * @param _x2 - Coordenada X do ponto final
 * @param _y2 - Coordenada Y do ponto final
 */
Reta::Reta(int _x1, int _y1, int _x2, int _y2){
    x1=_x1;
    y1=_y1;
    x2=_x2;
    y2=_y2;
}

/**
 * @brief Reta::draw - Desenha a reta tendo como base o algoritmo de Bresenham
 * @param t - Seta na tela(matriz) o desenho da reta
 */

void Reta::draw(Screen &t){
    int dx, dy, dxabs, dyabs, sdx, sdy, px, py;
    float inclinacao;

    dx = x2-x1;
    dy = y2-y1;
    dxabs = abs(dx);
    dyabs = abs(dy);
    sdx = sgn(dx);
    sdy = sgn(dy);

    if (dxabs >= dyabs){
        inclinacao = (float)dy/(float)dx;
        for(int i=0;i!=dx;i+=sdx){
            px = x1 + i;
            py = inclinacao *i + y1;
            t.setPixel(px,py);
        }
    }
    else {
        inclinacao = (float)dx/(float)dy;
        for (int i=0;i!=dy;i+=sdy){
            px = inclinacao *i + x1;
            py = y1 + i;
            t.setPixel(px,py);
        }
    }
}


