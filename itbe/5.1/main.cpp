#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const char duom[] = "duom.txt";
const char rez[] = "rez.txt";
const int cMax = 20;
const int cPav = 20;
//-----
struct kelione{
    string pav;
    int isv_val;
    int isv_min;
    int atv_val;
    int atv_min;
    int trukme_val;
    int trukme_min;
};
//-----
void skaityti(kelione K[], int &n);
void trukme(kelione K[], int n);
void rastitrukme(kelione K[], int &n, int &viso_val, int &viso_min);
void spausdinti(kelione K[], int &n, int &viso_val, int &viso_min);
//-----
int main()
{
    kelione K[cMax];
    int n = 0;
    int viso_val = 0;
    int viso_min = 0;

    skaityti(K, n);
    trukme(K, n);
    rastitrukme(K, n, viso_val, viso_min);
    spausdinti(K, n, viso_val, viso_min);

    return 0;
}

void skaityti(kelione K[], int &n)
{
    char eil[cPav+1];

    ifstream fd(duom);
    fd >> n;
    fd.ignore(80, '\n');
    for (int i = 0; i < n; i++){
        fd.get(eil, cPav);
        K[i].pav = eil;
        fd >> K[i].isv_val
           >> K[i].isv_min
           >> K[i].atv_val
           >> K[i].atv_min;
    fd.ignore(80, '\n');
    }
}

void trukme(kelione K[], int n)
{
    for (int i = 0; i < n; i++)
    {
        //pirma konvertuojame valandas i minutes
        K[i].isv_min = K[i].isv_val*60 + K[i].isv_min;
        K[i].atv_min = K[i].atv_val*60 + K[i].atv_min;
        K[i].trukme_min = K[i].atv_min - K[i].isv_min;

        //dabar skaiciuojam kiek valandu susidaro
        K[i].trukme_val = K[i].trukme_min/60;
        K[i].trukme_min = K[i].trukme_min%60;
    }

}

void spausdinti(kelione K[], int &n, int &viso_val, int &viso_min)
{
    ofstream fr(rez);
    for (int i = 0; i < n; i++)
        fr << K[i].pav << K[i].trukme_val << " " << K[i].trukme_min << endl;
    fr << viso_val << " " << viso_min;

    fr.close();
}

void rastitrukme(kelione K[], int &n, int &viso_val, int &viso_min)
{
    //kiek nukeliavo pirma diena + paskutine diena, o visas kitas dienas keliavo po 1440 minuciu
    viso_min = 1440 - K[0].isv_min + K[n-1].atv_min + 1440*(n-2);
    viso_val = viso_min/60;
    viso_min = viso_min%60;
}
