#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
const char duom[] = "duom.txt";
const char rez[] = "rez.txt";
//----------
struct Mokinys {
    string vardas;  //vardas
    float ugis;     //ugis
    int taskai;     //surinkti taskai
};
//----------
void Skaityti(Mokinys A[], int &n, int &p, int &k);
int RastiAuksciausia(Mokinys A[], int n);
int RastiPelningiausia(Mokinys A[], int n);
void RastiKandidatus(Mokinys A[], Mokinys B[], int n, int &m, int ugis, int taskai);
void Spausdinti(Mokinys A[], int n);
//----------
int main()
{
    Mokinys A[69];  //visi mokiniai
    Mokinys B[69];  //kandidatai
    int n = 0,      //mokiniu skaicius
        m = 0,      //kandidatu skaicius
        p = 0,      //ugio procentai
        k = 0;      //tasku procentai

    Skaityti(A, n, p, k);
    //randame minimalu ugi
    float min_ugis = (float)(RastiAuksciausia(A, n) * (100-p)) / 100;
    //randame minimalu tasku skaiciu
    float min_taskai = (float)(RastiPelningiausia(A, n) * (100-k)) / 100;
    //ieskome kandidatu
    RastiKandidatus(A, B, n, m, min_ugis, min_taskai);
    //spausdiname
    Spausdinti(B, m);

    return 0;
}

void Skaityti(Mokinys A[], int &n, int &p, int &k)
{
    ifstream fd(duom);
    fd >> n;

    for (int i = 0; i < n; i++)
        fd >> A[i].vardas >> A[i].ugis >> A[i].taskai;

    fd >> p >> k;
    fd.close();
}

int RastiAuksciausia(Mokinys A[], int n)
{
    int ugis = 0;

    for (int i = 0; i < n; i++)
        if (A[i].ugis > ugis)
            ugis = A[i].ugis;

    return ugis;
}

int RastiPelningiausia(Mokinys A[], int n)
{
    int taskai = 0;

    for (int i = 0; i < n; i++)
        if (A[i].taskai > taskai)
            taskai = A[i].taskai;

    return taskai;
}

void RastiKandidatus(Mokinys A[], Mokinys B[], int n, int &m, int ugis, int taskai)
{
    for (int i = 0; i < n; i++)
        if ((A[i].ugis >= ugis) || (A[i].taskai >= taskai))
        {
            B[m] = A[i];
            m++;
        }
}

void Spausdinti(Mokinys A[], int n)
{
    ofstream fr(rez);
    if (n == 0)
        fr << "Kandidatu nera";
    else
    {
        fr << "Vardas          Ugis    Taskai" << endl;
        fr << "----------" << endl;
        for (int i = 0; i < n; i++)
            fr << setw(16) << left << A[i].vardas
               << setw(8) << A[i].ugis
               << setw(8) << A[i].taskai << endl;
    }

    fr.close();
}
