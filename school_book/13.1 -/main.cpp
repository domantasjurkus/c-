#include <iostream>
#include <fstream>
using namespace std;
const char duom[] = "duom.txt";
const char rez[] = "rez.txt";
const int CMax = 50;
//-----
void Skaityti(string A[], int &n);
void Spausdinti(string A[], int n, string komentaras);
void Atrinkti(string A[], int n, string B[], int k);
//-----
int main()
{
    string A[CMax];     //visi miestai
    string B[CMax];     //atrinkti miestai
    int n;
    int k = 0;

    ofstream fr(rez);
    fr.close();

    Skaityti(A, n);
    Spausdinti(A, n, "Pradiniai duomenys");

    return 0;
}

void Skaityti(string A[], int &n)
{
    ifstream fd(duom);
    fd >> n;
    fd.ignore(80, '\n');
    for (int i = 0; i < n; i++)
    {
        getline(fd, A[i]);
    }
}

void Spausdinti(string A[], int n, string komentaras)
{
    ofstream fr(rez);
    fr << "--------" << endl;
    fr << komentaras << endl;
    fr << "--------" << endl;
    for (int i = 0; i < n; i++)
    {
        fr << A[i] << endl;
    }
}

void Atrinkti(string A[], int n, string B[], int k)
{
    char s;     //simbolis pavadinimo raidziu nuskaitymui
    for (int i = 0; i < n; i++)
    {

    }
}
