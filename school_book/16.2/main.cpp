#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const char duom[] = "duom.txt";
const char rez[] = "rez.txt";
const int Cmax = 30;
const int Cpav = 15;
//-----
struct Mokinys{
    string pav;
    int balai[10];
    int ivertinimas;
};
//-----
void Skaityti(Mokinys M[], int &n, double uzd_svoris[], int &k);
void Ivertinimas(Mokinys M[], int &n, double uzd_svoris[], int &k);
//-----
int main()
{
    Mokinys M[Cmax];
    int n;              //mokiniø skaièius
    double uzd_svoris[10]; //kiek kiekviena uþduotis verta
    int k;              //uþduoèiø skaièius

    Skaityti(M, n, uzd_svoris, k);
    Ivertinimas(M, n, uzd_svoris, k);

    for (int i = 0; i < n; i++)
        cout << M[i].ivertinimas << endl;

    return 0;
}

void Skaityti(Mokinys M[], int &n, double uzd_svoris[], int &k)
{
    ifstream fd(duom);
    char eil[Cpav+1];       //+1, kad gale talpintø '\0' simbolá
    fd >> n >> k;
    fd.ignore(80, '\n');

    for (int i = 0; i < k; i++)
        fd >> uzd_svoris[i];
    fd.ignore(80, '\n');

    for (int i = 0; i < n; i++)
    {
        fd.get(eil, Cpav);              //skaitome vardà
        M[i].pav = eil;
        for (int j = 0; j < k; j++)     //skaitome kiekvienà ávertinimà
            fd >> M[i].balai[j];
        fd.ignore(80, '\n');
    }
    fd.close();
}

void Ivertinimas(Mokinys M[], int &n, double uzd_svoris[], int &k)
{
    int balu_suma;
    for (int i = 0; i < n; i++)
    {
        balu_suma = 0;
        for (int j = 0; j < k; j++)
        {
            balu_suma += M[i].balai[j];
        }
        M[i].ivertinimas = balu_suma/k;         //Reikia suapvalinti...
    }
}
