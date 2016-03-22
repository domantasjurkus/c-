#include <iostream>
#include <fstream>
using namespace std;
const char duom[] = "duomenys.txt";
const char rez[] = "rezultatas.txt";
int main()
{
    int rankos, kojos, akys,
        gr, gk, ga,
        mr, mk, ma,
        fra, fk, fa;
    ifstream fd(duom);
    fd >> rankos >> kojos >> akys
       >> gr >> gk >> ga
       >> mr >> mk >> ma
       >> fra >> fk >> fa;

    for (int g = 1; g <= 500; g++){
        for (int m = 1; m <= 500; m++){
            for (int f = 1; f <= 500; f++){
                if ((g*gr+m*mr+f*fra==rankos)&&(g*gk+m*mk+f*fk==kojos)&&(g*ga+m*ma+f*fa==akys))
                    cout << g << " " << m << " " << f << endl;
            }
        }
    }
    fd.close();
    return 0;
}
