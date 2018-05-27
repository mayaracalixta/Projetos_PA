#ifndef POLIGONO_H
#define POLIGONO_H
#include "point.h"


class Poligono
{
public:
    Poligono();

public:

    Point vertices[100]; //Vetor com 100 pontos que forma o poligono
    int n_vertices =0 ; //Identificador de cada posição do ponto dentro do vetor
public:

    void setVertice(float x,float y); //Seta as coordenadas de cada ponto do poligono
    void quantidade(void);  //Conta a quantidade de vertices
    void imprimirPoli(void); //Imprime os pontos da estrutura do poligono
    void area_poligono(void);  //Calcula a area do poligono
    void transladaPoli(float _a, float _b); //Translada todos os ponto do poligono
    void rotacionar(float theta, float x, float y);  //Rotaciona o poligono em theta graus em relação ao ponto dado

};

#endif // POLIGONO_H
