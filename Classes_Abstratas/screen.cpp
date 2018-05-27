#include "screen.h"
#include <iostream>

using namespace std;

/**
 * @brief Screen::Screen - Contrutor da classe Screen
 * @param numlin - Numero de linhas da matriz
 * @param numcol - Numero de colunas
 */
Screen::Screen(int _numlin, int _numcol){
    if(_numlin >0 && _numcol >0){
        numlin = _numlin;
        numcol = _numcol;

        mat = vector< vector<char> > (numlin, vector<char> (numcol, ' ')); //Cria a matriz usando o template vector
    }
    if(numlin <= 0 && numcol <= 0){ // verifica se o numero de linhas e colunas não são negativos
        cout << "Matriz inválida";
  }
}

/**
 * @brief Screen::setPixel - Inseri um valor a cada elemento da matriz
 * @param x - Coordebada x do elemento
 * @param y - Coordenada y do elemento
 */
void Screen::setPixel(int x, int y){
    mat[y][x] = brush;
}

/**
 * @brief Screen::clear - Limpa toda a matriz colocando em cada elemento um espaço
 */

void Screen::clear(){
    for(int i=0;i<numlin;i++){
        for(int j=0;j<numcol;j++){
            if(mat[i][j] != ' '){
                mat[i][j] = ' ';
            }
        }
    }
}
/**
 * @brief Screen::setBrush - Seta um valor que vai ser inserido posteriormente a cada elemento da matriz
 * @param _brush - Recebe o valor que ira ser setado
 */
void Screen::setBrush(char _brush){
    brush = _brush;
}
