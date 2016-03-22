#include <iostream>
#include <fstream>
#include <iomanip>
const char duom[] = "duom.txt";
const char rez[] = "rez.txt";
const int Cmax = 100;
using namespace std;
//----------
void Skaityti(const char name[], char A[], int B[], int &n);
void Spausdinti(const char name[], char A[], int B[], int n);
int IeskotiBatu(char A[], int B[], int n, char tp, int dd);
void SalintiBatus(char A[], int B[], int &n, int ind);
//----------
int main()
{
    char T[Cmax];   //batu tipai - m ir v
    int D[Cmax];    //batu dydziai
    int n;          //batu skaicius
    int ind_b;

    Skaityti(duom, T, D, n);

    ofstream fr(rez);   //isvalo buvusius duomenis
    fr.close();

    Spausdinti(rez, T, D, n);

    fr.open(rez, ios::app);

    //ieskoma batu Mykolui...
    ind_b = IeskotiBatu(T, D, n, 'v', 43); //rastu batu indeksas
    if (ind_b >= 0)     //jeigu indeksas nera -1
    {
        fr << "43 ismeros indeksas: " << ind_b << endl;
        SalintiBatus(T, D, n, ind_b);   //pasalina rasta bata is masyvo
    }
    else
        fr << "43 ismeros batu nera" << endl;

    //ieskoma batu Marytei...
    ind_b = IeskotiBatu(T, D, n, 'm', 38);
    if (ind_b >= 0)
    {
        fr << "38 ismeros indeksas: " << ind_b << endl;
        SalintiBatus(T, D, n, ind_b);   //pasalina rasta bata is masyvo
    }
    else
        fr << "38 ismeros batu nera" << endl;

    fr.close();

    Spausdinti(rez, T, D, n);

    return 0;
}

void Skaityti(const char name[], char A[], int B[], int &n)
{
    ifstream fd(name);
    fd >> n;
    for (int i = 0; i < n; i++)
        fd >> A[i] >> B[i];
    fd.close();
}

void Spausdinti(const char name[], char A[], int B[], int n)
{
    ofstream fr(name, ios::app);
    fr << " Tipas  Dydis " << endl;
    fr << "--------------" << endl;
    for (int i = 0; i < n; i++)
        fr << setw(4) << A[i] << setw(7) << B[i] << endl;
    fr << "--------------" << endl;
    fr.close();

}

int IeskotiBatu(char A[], int B[], int n, char tp, int dd)
{
    int ind = -1;
    for (int i = 0; i < n; i++)
        if ((A[i]==tp)&&(B[i]==dd))
        {
            ind = i;
            break;
        }

    return ind;
}

void SalintiBatus(char A[], int B[], int &n, int ind)
{
    for (int i = ind; i < n-1; i++)
    {
        A[i] = A[i+1];
        B[i] = B[i+1];
    }
    n--;
}
