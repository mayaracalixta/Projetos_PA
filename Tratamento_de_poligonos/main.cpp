#include <iostream>
#include "point.h"
#include "poligono.h"
#include "retangulo.h"

using namespace std;

int main()
{
    Retangulo R(0,0,3,4);// Criando o retangulo

   R.imprimirPoli(); //Imprimie o retangulo usando o metodo implementado na classe poligono
   R.area_poligono(); // Calcula a area do retangulo usando o metodo implementado na classe poligono e mostra na tela

   R.transladaPoli(-3,4); //Translada o retangulo usando o metodo implementado na classe poligono

   R.imprimirPoli();
   R.area_poligono();

   R.rotacionar(30,-1.5,2); //Rotaciona o retangulo usando na classe poligono
   R.area_poligono();


}
