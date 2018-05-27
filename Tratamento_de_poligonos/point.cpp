#include "point.h"
#include <cmath>
#include <iostream>

using namespace std;

/**
 * @brief Point::Point - Contrutor da classe
 */
Point::Point(){ //construtor da classe ponto

    //ctor
}

// Seta o valor da coordenada x dada pelo usuario
/**
 * @brief Point::setX - Seta o valor da coordenada x do ponto
 * @param _x - valor da coordenda x fornecida pelo usuario
 */
void Point::setX(float _x){
    x = _x;
}

// Seta o valor da coordenada y dada pelo usuario
/**
 * @brief Point::setY - Seta o valor da coordenada y do ponto
 * @param _y - valor da coordenda y fornecida pelo usuario
 */
void Point::setY(float _y){
    y = _y;
}

// Recupera o valor da coordenada x dada pelo usuario
/**
 * @brief Point::getX - Recupera o valor da coordenada x do ponto
 * @return - Retorna o valor da coordenada
 */
float Point::getX(){
    return x;
}

// Recupera o valor da coordenada y dada pelo usuario
/**
 * @brief Point::getY - Recupera o valor da coordenada y do ponto
 * @return - Retorna o valor da coordenada
 */
float Point::getY(){
    return y;
}

//Seta o valor das coordenadas do ponto
/**
 * @brief Point::setXY - Seta o valor das coordenadas x e y
 * @param _x - valor da coordenda x fornecida pelo usuario
 * @param _y - valor da coordenda y fornecida pelo usuario
 */
void Point::setXY(float _x, float _y){
    x = _x;
    y = _y;
}

//Soma cada coordenada do ponto com o ponto dado
/**
 * @brief Point::add - Soma de pontos
 * @param p1 - Ponto submetido para a soma
 */
void Point::add(Point p1){
   x = x + p1.x;
   y = y + p1.y;
}
//Sobtrai cada coordenada do ponto com o ponto dado
/**
 * @brief Point::sub - Subtração de pontos
 * @param p1 - Ponto submetido para a operaçao
 */
void Point::sub(Point p1){
   x = x - p1.x;
   y = y - p1.y;
}


//Tira a norma do ponto dado
/**
 * @brief Point::norma - Recebe um ponto e calcula sua norma
 */
void Point::norma() {

    cout << "Norma : " << sqrt( pow(x,2) + pow(y,2)  ) << endl;
}

//Tranlada o ponto de x+a e y+b unidades
/**
 * @brief Point::translada - Recebe um ponto e o tranlada em x + a e y + b unidades
 * @param a - Unidade para tranladar a coordenada x
 * @param b - Unidade para tranladar a coordenada y
 */
void Point::translada(float a, float b){
    x = x + a;
    y = y + b;
}

//Imprime as coordendas do ponto
/**
 * @brief Point::imprime - Imprime as coordenadas dos pontos
 */
void Point::imprime(){

    cout<<"( "<<getX()<<","<<getY()<<" )";
}

/**
 * @brief Point::~Point - Destrutor da classe
 */
Point::~Point() {//destrutor da classe ponto
    //dtor
}
