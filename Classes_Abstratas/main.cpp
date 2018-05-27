#include <iostream>
#include "screen.h"
#include "figurageometrica.h"
#include "reta.h"
#include "retangulo.h"
#include "circulo.h"
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>

using namespace std;

int main()
{
    ifstream fin;
    string s;
    stringstream ss;
    ofstream fout;

    vector <FiguraGeometrica*>  Figuras;

    int nlin, ncol;
    int x0, y0, x1, y1;
    int xini,yini,alt,larg,fill2;
    int xcent, ycent, raio,fill;
    char brsh;


   fin.open("C:/Users/Mayara/Desktop/Tratamento-de-classes-abstratas-master/in.txt");
    if(!fin.is_open()){
       exit(0);
    }

    while(fin.good()){
       getline(fin, s);
       if(fin.good()){
           ss.clear();
           ss.str(s);
           while(ss.good()){
               ss >> s;
                   if(s.compare(string("dim"))==0){
                        ss >> nlin >> ncol;
                    }
                    if(s.compare(string("reta"))==0){
                        ss >> x0 >> y0 >> x1 >> y1;
                        Figuras.push_back(new Reta(x0,y0,x1,y1));
                   }
                    if(s.compare(string("retangulo"))==0){
                       ss >> xini >> yini >> larg >> alt>>fill2;
                        Figuras.push_back(new Retangulo(xini,yini,larg,alt,fill2));
                    }
                  if(s.compare(string("circulo"))==0){
                       ss >> xcent >> ycent >> raio >> fill;
                      Figuras.push_back(new Circulo(xcent,ycent,raio,fill));
                    }
                    if(s.compare(string("brush"))==0){
                        ss >> brsh;
                    }
                }
                cout << endl;
              }
      }


    Screen Tela(nlin,ncol);
    for(int i=0; i<Figuras.size(); i++){
        Tela.setBrush(brsh);
        Figuras[i]->draw(Tela);
    }
    cout << Tela;
    fout.open(   "C:/Users/Mayara/Desktop/Tratamento-de-classes-abstratas-master/out.txt"   );
    if(!fout.is_open()){
        cout << "erro\n";
    }
    if(fout.is_open()){
        fout << Tela;
      }
    fout.close();

}
