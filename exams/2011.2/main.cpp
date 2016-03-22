#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
const char duom[] = "U2.txt";
const char rez[] = "U2rez.txt";
const int Cmax = 100;
//-----
struct Pora {
    string vardas1;
    string vardas2;
    string vardai;
    int tech_taskai[10];    //kiekvieno teisëjo skirtas ávertinimas
    int arts_taskai[10];    //10, nes maksimalus teisëjø skaièius  yra 10
    int tech_vertinimas;
    int arts_vertinimas;
    int taskai;             //galutinis tasku skaicius

};
//-----
void Skaityti(Pora A[], int &n, int &k);
int Vertinimas(int A[], int k);
void Rikiuoti(Pora A[], int n);
void Spausdinti(Pora A[], int n);
//-----
int main()
{
    Pora P[Cmax];
    int n;          //poru skaicius
    int k;          //teiseju skaicius

    Skaityti(P, n, k);

    for (int i = 0; i < n; i++)
    {
        P[i].tech_vertinimas = Vertinimas(P[i].tech_taskai, k);
        P[i].arts_vertinimas = Vertinimas(P[i].arts_taskai, k);
        P[i].taskai = P[i].tech_vertinimas + P[i].arts_vertinimas;
    }

    Rikiuoti(P, n);

    Spausdinti(P, n);

    return 0;
}

void Skaityti(Pora A[], int &n, int &k)
{
    ifstream fd(duom);
    fd >> n >> k;
    for (int i = 0; i < n; i++)
    {
        fd >> A[i].vardas1 >> A[i].vardas2;

        A[i].vardai = A[i].vardas1 + " " + A[i].vardas2;

        for (int j = 0; j < k; j++)     //árağomi ávertinimai uş technikà
            fd >> A[i].tech_taskai[j];

        for (int j = 0; j < k; j++)     //árağomi ávertinimai uş artistiğkumà
            fd >> A[i].arts_taskai[j];
    }
}

int Vertinimas(int A[], int k)
{
    int maximumas = A[0];
    int minimumas = 11;
    int suma = 0;

    for (int i = 0; i < k; i++)     //randame maksimumà ir minimumà
    {
        if (A[i] > maximumas)
            maximumas = A[i];
        if (A[i] < minimumas)
            minimumas = A[i];
        suma += A[i];
    }

    suma -= maximumas + minimumas;

    return suma;
}

void Spausdinti(Pora A[], int n)
{
    ofstream fr(rez);
    for (int i = 0; i < n; i++)
    {
        fr << setw(20) << left << A[i].vardai
           << A[i].taskai << endl;
    }
    fr.close();
}

void Rikiuoti(Pora A[], int n)
{
    Pora laikina;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (A[i].taskai < A[j].taskai)
            {
                laikina = A[j];
                A[j] = A[i];
                A[i] = laikina;
            }
        }
    }
}
