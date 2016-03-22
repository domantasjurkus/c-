#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
const char duom[] = "duom.txt";
const char rez[] = "rez.txt";
const int Cmax = 30;
//----------
struct Mokinys{
    string pav;
    int kiek;
};
//----------
void Skaityti(Mokinys A[], int &n);
void Spausdinti(Mokinys A[], int n);
void Atrinkti(Mokinys A[], int n, Mokinys B[], int &m);
int Suma(Mokinys A[], int n);
int RastiTaikliausia(Mokinys A[], int n);
//----------
int main()
{
    Mokinys A[Cmax];    //visi mokiniai
    Mokinys B[Cmax];    //surinke 15 ir daugiau tasku
    int n;              //visu mokiniu skaicius
    int m;              //surinkusiu 15 ir daugiau skaicius

    Skaityti(A, n);
    if (n == 0)
    {
        ofstream fr(rez);
        fr << "Failas tuscias. Wow." << endl;
        fr.close();
        return 0;
    }
    Atrinkti(A, n, B, m);
    Spausdinti(B, m);

    ofstream fr(rez, ios::app);
    fr << "-----" << endl;
    fr << "Mokinys vidutiniskai surinko " << Suma(A, n)/n << " tasku." << endl;
    if (m >= 1)
        fr << "Atrinktieji vidutiniskai surinko " << Suma(B, m)/m << " tasku." << endl;
    else
        fr << "Niekas nepataike 15 kartu." << endl;
    fr << "-----" << endl;

    fr << "Taikliausias: " << A[RastiTaikliausia(A, n)].pav << endl;
    if (A[RastiTaikliausia(A, n)].kiek < 15)
        fr << "...nors jis nesurinko ne 15 tasku." << endl;
    fr.close();

    return 0;
}

void Skaityti(Mokinys A[], int &n)
{
    ifstream fd(duom);
    fd >> n;
    for (int i = 0; i < n; i++)
    {
        fd >> A[i].pav >> A[i].kiek;
    }
}

void Spausdinti(Mokinys A[], int n)
{
    ofstream fr(rez);
    fr << "Daugiau negu 15 surinko:" << endl;
    fr << "-----" << endl;
    for (int i = 0; i < n; i++)
    {
        fr << setw(10) << left << A[i].pav << " "
           << setw(10) << A[i].kiek << endl;
    }
    fr.close();
    fr << "-----" << endl;
}

    //is A atrnekame mokinius, surinkusiu ne maziau kaip 15 tasku
void Atrinkti(Mokinys A[], int n, Mokinys B[], int &m)
{
    m = 0;
    for (int i = 0; i < n; i++)
        if (A[i].kiek >= 15)
        {
            B[m] = A[i];
            m++;
        }
}

int Suma(Mokinys A[], int n)
{
    int suma = 0;
    for (int i = 0; i < n; i++)
    {
        suma += A[i].kiek;
    }
    return suma;
}

int RastiTaikliausia(Mokinys A[], int n)
{
    int ind = -1;
    int taskai = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i].kiek >= taskai)
        {
            taskai = A[i].kiek;
            ind = i;
        }
    }
    return ind;
}
