#include "Retangulo.h"
#include <iostream>
using namespace std;

/**
 * @brief Retangulo::Retangulo - Criação da estrutura do retangulo
 * @param x - Coordenada x do ponto inicial
 * @param y - Coordenada y do ponto inicial
 * @param largura - Largura do retangulo
 * @param altura - Altura do retangulo
 */
Retangulo::Retangulo(float x, float y, float largura, float altura){
    //Constroi o retangulo
    setVertice(x,y);
    setVertice(x,y-altura);
    setVertice(x+largura,y-altura);
    setVertice(x+largura,y);
}
/**
* @brief Retangulo::~Retangulo - Destrutor da classe
*/
Retangulo::~Retangulo()
{
    //dtor
}
