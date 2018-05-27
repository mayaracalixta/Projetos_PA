#ifndef CIRCULO_H
#define CIRCULO_H
#include <figurageometrica.h>

class Circulo:public FiguraGeometrica
{
private:
    int x,y;
    int raio;
    int preenchido;
public:

    Circulo(int x, int y, int r, int p);

    void draw(Screen &t);
};

#endif // CIRCULO_H
