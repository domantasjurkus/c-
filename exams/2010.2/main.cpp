#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const char duom[] = "U2.txt";
const char rez[] = "U2rez.txt";
const int Cmax_prod = 10;
const int Cmax_pat = 12;
//-----
struct Patiekalas {
    string pav;             //patiekalo pavadinimas
    int prod[Cmax_prod];    //masyvas, parodantis kiek ir kurio produkto prireiks
};
//-----
void Skaityti(Patiekalas P[], int &n, int &p, int Prod_k[]);
//-----
int main()
{
    int n;                          //produkt� skai�ius
    int p;                          //patiekal� skai�ius
    int Prod_kainos[Cmax_prod];     //produkt� kain� masyvas
    Patiekalas P[Cmax_pat];

    Skaityti(P, n, p, Prod_kainos);
    cout << P[3].pav;



    return 0;
}

void Skaityti(Patiekalas P[], int &n, int &p, int Prod_k[])
{
    ifstream fd(duom);
    fd >> n >> p;           //�ra�ome produktu ir patiekal� skai�i�

    for (int i = 0; i < n; i++)
        fd >> Prod_k[i];    //�ra�ome produkt� kainas

    for (int i = 0; i < p; i++)         //einame per visus patiekalus
    {
        fd >> P[i].pav;
        for (int j = 0; j < n; j++)     //einame per kiekvieno patiekalo produktus
        {
            fd >> P[i].prod[j];
        }
    }
}
