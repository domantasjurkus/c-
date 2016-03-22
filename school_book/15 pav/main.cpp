#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
const char duom[] = "duom.txt";
const char rez[] = "rez.txt";
const int Cmax = 300;           //maksimalus miestu skaiius
const int Cpav = 20;            //maksimalus pavadinimo simboliu skaicius
//-----
struct Miestas{
    string pav;                 //miesto pavadinimas
    string valst;               //valstyve
    int kiek;                   //kiek miestu yra valstybeje
};
//-----
void Skaityti(Miestas M[], int &n);
void Spausdinti(Miestas M[], int n, string pav);
void Atrinkti(Miestas A[], int n, Miestas B[], int &m);
int Yra(Miestas A[], int n, string pav);
//-----
int main()
{
    Miestas M[Cmax];      //miestu masyvas
    int n;                //miestu skaicius
    Miestas S[Cmax];      //valstybiu masyvas
    int m;

    Skaityti(M, n);
    Atrinkti(M, n, S, m);
    Spausdinti(S, m, "Valstybiu sarasas: ");

    return 0;
}

void Skaityti(Miestas M[], int &n)
{
    char eil[Cpav + 1];     //papildoma vieta simboliui \0
    ifstream fd(duom);
    fd >> n;
    fd.ignore(80, '\n');

    for (int i = 0; i < n; i++)
    {
        fd.get(eil, Cpav);
        M[i].pav = eil;
        getline(fd, M[i].valst);
        M[i].kiek = 1;
    }
    fd.close();
}

void Spausdinti(Miestas M[], int n, string pav)
{
    ofstream fr(rez);
    fr << pav << endl;
    for (int i = 0; i < n; i++)
    {
        fr << setw(19) << M[i].pav
           << setw(15) << M[i].valst
           << setw(5) << M[i].kiek << endl;
    }
    fr.close();
}

void Atrinkti(Miestas A[], int n, Miestas B[], int &m)
{
    m = 0;                              //is pradziu nera nei vienos salies
    for (int i = 0; i < n; i++)         //einame per visus miestus
    {
        int k = Yra(B, m, A[i].valst);  //bandome rasti salies indeksa
        if (k >= 0)                     //jeigu salis jau pamineta
            B[k].kiek++;                //padidiname paminejimu skaiciu vienu
        else {                          //jeigu salis dar nepamineta
            B[m] = A[i];                //kopijuojam miestu masyva i saliu
            m++;                        //pasakom, kad dabar yra dar viena papildoma salis
        }
    }
}

int Yra(Miestas B[], int m, string pav){
    for (int i = 0; i < m; i++)
        if (B[i].valst == pav)          //jeigu atrinktame sarase jau yra pamineta salis
            return i;                   //graziname tos salies indeksa masyve
    return -1;                          //jeigu salis dar nepamineta, graziname -1
}
