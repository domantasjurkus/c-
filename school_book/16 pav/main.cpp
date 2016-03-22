#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
const char duom1[] = "duom1.txt";
const char duom2[] = "duom2.txt";
const char rez[] = "rez.txt";
const int CMax = 30;
const int CPav = 20;
//-----
struct Sportininkas{
    string pav;
    int laikas;
};
//-----
void Skaityti(const char duom_pav[], Sportininkas A[], int &n);
void Spausdinti(Sportininkas A[], int n);
void Rikiuoti(Sportininkas A[], int n);
void Atrinkti(Sportininkas A[], int n, Sportininkas B[], int &m);
//-----
int main()
{
    Sportininkas A[CMax];
    int n = 0;
    Sportininkas B[CMax];
    int m = 0;
    ofstream fr(rez); fr.close();

    Skaityti(duom1, A, n);  //pirmas
    Rikiuoti(A, n);
    Atrinkti(A, n, B, m);

    Spausdinti(A, n);

    Skaityti(duom2, A, n);  //antras
    Rikiuoti(A, n);
    Atrinkti(A, n, B, m);

    Spausdinti(A, n);

    Spausdinti(B, m);

    return 0;
}

void Skaityti(const char duom_pav[], Sportininkas A[], int &n)
{
    ifstream fd(duom_pav);
    char eil[CPav+1];
    int minut;
    int sekun;

    fd >> n;
    fd.ignore(80, '\n');

    for (int i = 0; i < n; i++)
    {
        fd.get(eil, CPav);
        A[i].pav = eil;
        fd >> minut >> sekun;
        fd.ignore(80, '\n');
        A[i].laikas = minut * 60 + sekun;
    }
    fd.close();
}

void Spausdinti(Sportininkas A[], int n)
{
    ofstream fr(rez, ios::app);
    fr << "-------------------------" << endl;
    fr << "Vardas Pavardë     Laikas" << endl;
    fr << "-------------------------" << endl;
    for (int i = 0; i < n; i++)
    {
        fr << setw(CPav) << left << A[i].pav
                                 << A[i].laikas / 60 << ":"
                                 << A[i].laikas % 60 << endl;
    }
    fr.close();
}

void Rikiuoti(Sportininkas A[], int n)
{
    Sportininkas temp;
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (A[j].laikas < A[i].laikas)
            {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
}

void Atrinkti(Sportininkas A[], int n, Sportininkas B[], int &m)
{
    for (int i = 0; i < n/2; i++)
    {
        B[m] = A[i];
        m++;
    }

}
