#include "retangulo.h"
#include "reta.h"

/**
 * @brief Retangulo::Retangulo - Construtor da classe retangulo
 * @param _x - Coordenada x onde o retangulo sera iniciado
 * @param _y - Coordenada y onde o retangulo sera iniciado
 * @param _larg - Largura do retangulo
 * @param _alt - Altura do retangulo
 * @param _aux - Variavel responsavel por verificar se o retangulo sera preenchido ou não
 */
Retangulo::Retangulo(int _x, int _y, int _larg, int _alt, int _aux){
    x = _x;
    y = _y;
    larg = _larg;
    alt = _alt;
    aux =_aux;
}

/**
 * @brief Retangulo::draw - Desenha o retangulo de acordo com o algoritmo implementado
 * @param t - Desenha o retangulo na tela(matriz)
 */
void Retangulo::draw(Screen &t){

    /*1) Utiliza a classe reta criada anteriormete para contruir o retangulo
     *2) Varifica se o retangulo sera preenchido ou nao
    */
    if (aux == 0){
    Reta aresta1 (x,y,x+larg,y);
    Reta aresta2 (x+larg,y,x+larg,y+alt);
    Reta aresta3 (x+larg,y+alt,x,y+alt);
    Reta aresta4 (x,y+alt,x,y);

    //Desenha cada aresta do retangulo usando a classe Reta e seu metodo draw
    aresta1.draw(t);
    aresta2.draw(t);
    aresta3.draw(t);
    aresta4.draw(t);
    }



    else if (aux == 1){
        for(int i=0; i<alt; i++){
            Reta aresta1 (x,i,x+larg,i);
            aresta1.draw(t);
        }
    }
}

