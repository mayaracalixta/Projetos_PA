#include "poligono.h"
#include "point.h"
#include <cmath>
#include <iostream>

using namespace std;

/**
 * @brief Poligono::Poligono - Construtor da classe
 */
Poligono::Poligono(){ //Construtor da classe
}

//Seta pontos do poligono
/**
 * @brief Poligono::setVertice - Seta cada vertice(ponto)
 * @param x - Valor da coordenada x fornecida pelo usuario
 * @param y - Valor da coordenada y fornecida pelo usuario
 */
void Poligono::setVertice(float x, float y){

    vertices[n_vertices].setXY(x,y);
    n_vertices++;
}

//Conta a quantidade de vertices(pontos) que foram inseridos
/**
 * @brief Poligono::quantidade - Retorna a quantidade de vertices ja inseridos
 */
void Poligono::quantidade(){
    cout<<"Quantidade de vertices:"<<n_vertices<<endl;
}

//Imprime toda a sua estrutura
/**
 * @brief Poligono::imprimirPoli - Imprime a estrutura do poligono
 * usando para isso o metodo imprime() ja criado na classe Point
 */
void Poligono::imprimirPoli(){
    for(int i=0; i<n_vertices; i++){
      vertices[i].imprime(); //usando o imprime(); ja criado na classe Point
              cout<<" -> ";
    }
    vertices[0].imprime();
    cout << " ";
}

//Translada o cada vertice do poligono em x+a e y+b unidades
/**
 * @brief Poligono::transladaPoli - Translada toda a estrutura do poligono usando para isso
 * o metodo translada(_a,_b) ja implimentado na classe Point
 * @param _a - Unidade de translação da coordenada x
 * @param _b - Unidade de translação da coordenada y
 */
void Poligono::transladaPoli(float _a, float _b){

    for(int i=0; i<n_vertices; i++){
      vertices[i].translada(_a,_b); //Translada cada ponto usando o metodo translada(_a,_b) criado na classe Point
    }
}

//Calculo da area do poligono usando para isso a tecnica shoelace
/**
 * @brief Poligono::area_poligono - Calculo da area do poligono usando para isso a tecnica shoelace
 */
void Poligono::area_poligono() {

    float area=0.0;

    int j = n_vertices - 1;
    for (int i = 0; i < n_vertices; i++)
    {
        area += (vertices[j].x + vertices[i].x) * (vertices[j].y - vertices[i].y);
        j = i;
    }
    area = abs(area/2);

    cout << "Area = " << area << endl;
}

//Rotacina em theta graus em relação as coordenadas do ponto dado
/**
 * @brief Poligono::rotacionar - Rotaciona toda a estrutua do poligono
 * @param theta - Angulo para a rotação
 * @param x - Coordenda x do ponto central de rotação
 * @param y - Coordenda y do ponto central de rotação
 */
void Poligono::rotacionar(float theta, float x, float y){

    float aux_x,aux_y;

    theta = theta*(M_PI)/180; //conversao para radianos

    transladaPoli(-1*x,-1*y); //desloca o poligono para a origem

    for(int i=0 ; i<n_vertices ; i++) {

       aux_x = vertices[i].x;
       aux_y = vertices[i].y;
       vertices[i].x = (aux_x*cos(theta)) + (aux_y*-1*sin(theta)); //rotaciona em relação a origem
       vertices[i].y = (aux_x*sin(theta)) + (aux_y*cos(theta));
    }

    transladaPoli(x,y); //desloca o poligono para a posição original
}
