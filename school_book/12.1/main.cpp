#include <iostream>
#include <fstream>
using namespace std;
const char duom[] = "duom.txt";
const char rez[] = "rez.txt";
const int Cmax = 100;
//-----
void Skaityti(int &n, int A[]);
void ArDuoti(ofstream &fr, int A[], int n);
//-----
int main()
{
    int n;                      //turimu zaislu skaicius
    int A[Cmax];                //indeksas - zaislo numeris, indekso verte - zaislo kiekis
    for (int i = 0; i <= Cmax; i++)
        A[i] = 0;               //isvalome masyva

    Skaityti(n, A);

    ofstream fr(rez);
    ArDuoti(fr, A, n);
    fr.close();

    return 0;
}

void Skaityti(int &n, int A[])
{
    int sk;
    ifstream fd(duom);
    fd >> n;
    for (int i = 0; i < n; i++)
    {
        fd >> sk;
        A[sk]++;
    }

}

void ArDuoti(ofstream &fr, int A[], int n)
{
    for (int i = 0; i <= n; i++)
    {
        while (A[i] > 1)
        {
            fr << i << " ";
            A[i]--;
        }
    }
}
