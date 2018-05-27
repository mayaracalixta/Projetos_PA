#ifndef RETANGULO_H
#define RETANGULO_H
#include <figurageometrica.h>

class Retangulo : public FiguraGeometrica{
    int x, y, larg, alt,aux;
public:
    Retangulo(int x, int y, int larg, int alt,int aux);
    virtual void draw(Screen &t);
};

#endif // RETANGULO_H

