#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int n,      //eiluciu kiekis
        k;      //stulpeliu kiekis
    ifstream fd("duom.txt");
    fd >> n >> k;
    if ((n<0)||(n>=50)||(k<1)||(k>=50)) cout << "Blogi duomenys";
    else {
    int mas[n][k];



    }return 0;
}
