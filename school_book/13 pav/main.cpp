#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const char duom[] = "duom.txt";
const char rez[] = "rez.txt";
const int CMax = 30;
//-----
void Skaityti(string A[], int &n);
void Spausdinti(string A[], int n, string komentaras);
void Rikiuoti(string A[], int n);
void RastiIlgiausia(string A[], int n);
//-----
int main()
{
    string A[CMax];
    int n;

    ofstream fr(rez);    //isvalomas rezultatau failas

    Skaityti(A, n);
    if (n == 0)         //jeigu duomenu nera
    {
        fr << "Duomenu nera";
        fr.close();
    }

    else
    {
    fr.close();
    Spausdinti(A, n, "Pries:");
    Rikiuoti(A, n);
    Spausdinti(A, n, "Po:");
    RastiIlgiausia(A, n);
    }
    return 0;
}

void Skaityti(string A[], int &n)
{
    ifstream fd(duom);
    fd >> n;
    fd.ignore(80, '\n');
    for (int i = 0; i < n; i++)
        getline(fd, A[i]);

    fd.close();
}

void Spausdinti(string A[], int n, string komentaras)
{
    ofstream fr(rez, ios::app);     //neistrinam to, kas jau parasyta
    fr << "--------" << endl;
    fr << komentaras << endl;
    fr << "--------" << endl;
    for (int i = 0; i < n; i++)
        fr << A[i] << endl;
    fr.close();
}

void Rikiuoti(string A[], int n)
{
    string eil;
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (A[j] < A[i])
            {
                eil = A[j];
                A[j] = A[i];
                A[i] = eil;
            }
}

void RastiIlgiausia(string A[], int n)
{
    int ilgis = 0;      //nuskaitomas ilgis
    int max_ilgis = 0;  //didziausias ilgis
    int max_ind = -1;
    for (int i = 0; i < n; i++)
    {
        ilgis = A[i].length();
        if (ilgis >= max_ilgis)
        {
            max_ilgis = ilgis;
            max_ind = i;
        }
    }
    ofstream fr(rez, ios::app);
    fr << "-----" << endl;
    fr << "Ilgiausias: " << A[max_ind] << endl;
    fr << "-----" << endl;
    fr.close();
}
