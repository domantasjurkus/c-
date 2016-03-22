#include <fstream>
#include <math.h>
using namespace std;
const char duom[] = "U1.txt";
const char rez[] = "U1rez.txt";
const int CMax = 50;
//-----
void Skaityti(int x[], int y[], int &n, int &m);
int Atstumas(int a, int b);
void Spausdinti(int neaptarnauta, int nuvaziuota);
//-----
int main()
{
    int n;              //uþsakovø skaièius
    int m;              //kilometru limitas
    int x[CMax];        //x koordinaèiø masyvas
    int y[CMax];        //y koordinaèiø masyvas

    Skaityti(x, y, n, m);

    int i = 0;          //aptarnautų skaičius
    int atstumas = 0;   //vienos kelionės atstumas
    int nukeliauta = 0; //kiek iš viso nukeliauta

    while (m >= 0)      //kol neviršytas kilometrų skaičiaus limitas
    {
        atstumas = Atstumas(x[i], y[i]);    //randame atstumą iki sekančios stotelės
        m -= atstumas;                      //atimame atstumą iš bendro kilometrų skaičiaus
        nukeliauta += atstumas;             //pridedame visą nukeliautą atstumą
        i++;                                //einame prie kito užsakovo
    }

    Spausdinti(n-i, nukeliauta);

    return 0;
}

void Skaityti(int x[], int y[], int &n, int &m)
{
    ifstream fd(duom);
    fd >> n >> m;
    for (int i = 0; i < n; i++)
    {
        fd >> x[i] >> y[i];
    }
    fd.close();
}

int Atstumas(int a, int b)
{
    return fabs(a*2) + fabs(b*2);
}

void Spausdinti(int neaptarnauta, int nuvaziuota)
{
    ofstream fr(rez);
    fr << neaptarnauta << " " << nuvaziuota;
    fr.close();
}
