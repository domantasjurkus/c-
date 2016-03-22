#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;
const char duom[] = "U1.txt";
const char rez[] = "U1rez.txt";
const int CMax = 50;
//-----
struct Imone{
    string pav;
    int x;
    int y;
};
//-----
void Skaityti(Imone I[], int &n, int &m);
int Atstumas(int x, int y);
void Spausdinti(int aptarnauta, int nuvaziuota, Imone I[], int paskutine_ind);
//-----
int main()
{
    int n;      //imoniu skaicius
    int m;      //dienos kilometru skaicius
    Imone A[CMax];
    int aptarnauta = 0;
    int nuvaziuota = 0;
    int atstumas = 0;
    int paskutine_ind = -1;

    //nuskaitoma
    Skaityti(A, n, m);

    //skaiciuojama
    for (int i = 0; i < n; i++){
        atstumas = Atstumas(A[i].x, A[i].y);
        if (m >= atstumas){
            m -= atstumas;
            nuvaziuota += atstumas;
            aptarnauta++;
            paskutine_ind = i;
        }
    }

    //irasoma
    Spausdinti(aptarnauta, nuvaziuota, A, paskutine_ind);

    return 0;
}

void Skaityti(Imone I[], int &n, int &m)
{
    ifstream fd(duom);
    fd >> n >> m;
    //fd.ignore(80, '\n');
    for (int i = 0; i < n; i++)
    {
        fd >> I[i].pav;
        fd >> I[i].x >> I[i].y;
    }
    fd.close();
}

int Atstumas(int x, int y)
{
    return abs(2*x) + abs(2*y);
}

void Spausdinti(int aptarnauta, int nuvaziuota, Imone I[], int paskutine_ind)
{
    ofstream fr(rez);
    fr << aptarnauta << " " << nuvaziuota << " " << I[paskutine_ind].pav;
    fr.close();
}
