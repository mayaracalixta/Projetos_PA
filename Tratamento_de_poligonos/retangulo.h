#ifndef RETANGULO_H
#define RETANGULO_H
#include "poligono.h"

class Retangulo : public Poligono{

public:
    Retangulo(float x, float y, float largura, float altura); //construtor da classe
    ~Retangulo(); //destrutor da classe
};

#endif // RETANGULO_H
