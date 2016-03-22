#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
const char duom[] = "duom.txt";
const char rez[] = "rez.txt";
const int Cmax = 128;
using namespace std;
//-----
struct Gyventojas{
    string vardas;
    double mokesciai[3];    //1 - sildymas, 2 - telefonas, 3 - vanduo
    double kiek_moketi;
};
//-----
void Skaityti(Gyventojas A[], int &n);
void BendriMokesciai(Gyventojas A[], int n, double bendri[]);
void KiekMoketi(Gyventojas A[], int n);
void Spausdinti(Gyventojas A[], int n, double bendri[]);
//-----
int main()
{
    Gyventojas G[Cmax];
    int n = 0;
    double bendri[3] = {0, 0, 0};       //bendri mokesciai

    Skaityti(G, n);
    BendriMokesciai(G, n, bendri);
    KiekMoketi(G, n);
    Spausdinti(G, n, bendri);

    return 0;
}

void Skaityti(Gyventojas A[], int &n)
{
    ifstream fd(duom);
    fd >> n;
    for(int i = 0; i < n; i++)
        fd >> A[i].vardas
           >> A[i].mokesciai[0]
           >> A[i].mokesciai[1]
           >> A[i].mokesciai[2];
    fd.close();
}

void KiekMoketi(Gyventojas A[], int n)
{
    for (int i = 0; i < n; i++)         //einame per visus gyventojus
        for (int j = 0; j <= 2; j++)    //einame per tris mokesciu tipus
            if(A[i].mokesciai[j] > 0)   //jeigu mokesciu yra, sudedam i gyventojo suma
                A[i].kiek_moketi += A[i].mokesciai[j];
}

void BendriMokesciai(Gyventojas A[], int n, double bendri[])
{
    for (int i = 0; i < n; i++)         //einame per visus gyventojus
        for (int j = 0; j <= 2; j++)    //einame per tris mokesciu tipus
            if(A[i].mokesciai[j] > 0)   //jeigu mokesciu yra, sudedam i bendra suma
                bendri[j] += A[i].mokesciai[j];
}

void Spausdinti(Gyventojas A[], int n, double bendri[])
{
    ofstream fr(rez);
    if((bendri[0]==0)&&(bendri[1]==0)&&(bendri[2]==0))
        fr << "Niekam nereikia moketi." << endl;
    else
    {
    fr << "Uz sildyma:  " << setw(8) << bendri[0] << endl;
    fr << "Uz telefona: " << setw(8) << bendri[1] << endl;
    fr << "Uz vandeni:  " << setw(8) << bendri[2] << endl;
    fr << "----------------------" << endl;
    fr << "Vardas          Moketi" << endl;
    fr << "----------------------" << endl;
    for (int i = 0; i < n; i++)
        if(A[i].kiek_moketi > 0)
            fr << setw(15) << left << A[i].vardas << " "
                 << fixed << setprecision(2) << A[i].kiek_moketi << endl;
    }

    fr.close();
}
