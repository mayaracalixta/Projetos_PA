#ifndef POINT_H
#define POINT_H

class Point
{
public:
    float x,y;

public:

    Point(); //construtor da classe ponto
   ~Point(); //destrutor da classe ponto

    void setX(float _x);  //Seta um valor para a varivel x
    void setY(float _y);  //Seta um valor para a varivel y
    float getX(void);  //Recupera o valor da varivel x
    float getY(void); //Recupera o valor da varivel x
    void setXY(float _x, float _y); //Seta o valor de x e y
    void add(Point p1); //Soma de pontos
    void sub(Point p1);  //Subtração de pontos
    void imprime(void); //Imprime as coordendas do ponto
    void norma(); //
    void translada(float a, float b); //Translada o ponto x+a e y+b
    //friend class Poligono;

};

#endif // POINT_H
