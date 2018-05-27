#ifndef SCREEN_H
#define SCREEN_H
#include <vector>
#include <iostream>

using namespace std;

class Screen{
    int numlin, numcol;
    char brush;
    vector< vector<char> > mat;
public:
    Screen(int numlin, int numcol);
    void setPixel(int x, int y);
    void clear();
    void setBrush(char brush);
    friend ostream& operator<<(ostream &os, const Screen &t){
        for(int i=0;i<t.numlin;i++){
            for (int j=0;j<t.numcol;j++){
                os << t.mat[i][j] << ' ';
            }
            os << endl;
        }
        return os;
    }
};

#endif // SCREEN_H
