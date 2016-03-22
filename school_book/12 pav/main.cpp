#include <iostream>
#include <fstream>
using namespace std;
const char duom[] = "duom.txt";
const char rez[] = "rez.txt";
//-----
int Kiek(char sim);
void Irasyti(char S[], int F[]);
void Spausdinti(ofstream &fr, char S[], int F[]);
int Komplektai(int R[], int F[]);
void Liko(int k, int R[], int F[]);
//-----
int main()
{
    char S[6] = {'p', 'b', 'z', 'r', 'v', 'k'};     //figuru tipai
    int R[6] = {16, 4, 4, 4, 2, 2};                 //vienam komplektui  reikalingos figuros
    int F[6];                                       //turimu figuru masyvas

    Irasyti(S, F);      //duomenu irasymas i F[]

    ofstream fr(rez);
        Spausdinti(fr, S, F);
        int k = Komplektai(R, F);
        fr << k << endl;
        Liko(k, R, F);
        Spausdinti(fr, S, F);
    fr.close();

    return 0;
}

int Kiek(char sim)
{
    char s;
    int k = 0;
    ifstream fd(duom);
    while (!fd.eof())
    {
        fd >> s;
        if ((s == sim) && (!fd.eof())) k++;
    }
    return k;
}

void Irasyti(char S[], int F[])
{
    for (int i = 0; i <= 5; i++)
        F[i] = Kiek(S[i]);
}

void Spausdinti(ofstream &fr, char S[], int F[])
{
    for (int i = 0; i <= 5; i++)
        fr << S[i] << " " << F[i] << endl;
}

int Komplektai(int R[], int F[])
{
    int L = 9999;
    for (int i = 0; i <= 5; i++)    //einame per kiekviena figura
        if (F[i] / R[i] < L)        //taip gauname kiek komplektu uztektu einamai figurai
            L = F[i] / R[i];
    return L;
}

void Liko(int k, int R[], int F[])
{
    for (int i = 0; i <= 5; i++)
        F[i] -= R[i] * k;
}
