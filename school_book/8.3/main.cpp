#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;
const char duom[] = "duom.txt";
const char rez[] = "rez.txt";
const int Cmax = 100;
//----------
void Skaityti(const char name[], float A[][2], int &n, int &m);
float Atstumas(float x1, float y1, float x2, float y2);
void Rasyti(const char name[], float min_greitis, float vid, float max_greitis, float atstumas);
//----------
int main()
{
    int m,  //koordinaciu kiekis
        n;  //fiksavimo intervalas

    //pirmas indeksas - koordinaciu kiekis
    //antras indeksas: 0 - x koordinate, 1 - y koordinate
    float Ak[Cmax][2],
          atstumas,     //einamas atstumas
          greitis,      //einamas greitis
          max_greitis = 0,
          min_greitis = 99,
          suma = 0,     //visas nukeliautas atstumas
          vid;

    Skaityti(duom, Ak, n, m);

    for (int i = 1; i < m; i++)
    {
        atstumas = Atstumas(Ak[i-1][0], Ak[i-1][1], Ak[i][0], Ak[i][1]);
        suma += atstumas;

        greitis = atstumas/n;
        if (greitis > max_greitis)
            max_greitis = greitis;
        if (greitis < min_greitis)
            min_greitis = greitis;
    }

    //vid = visas kelias is viso laiko
    vid = suma / (n*(m-1));     //m-1, kanadngi dauginame is nueitu atstumu skaiciuas, ne daleles poziciju
                                //kitaip sakant, jeigu buvo 4 pozicijos, is viso dalele ejo 3 kartus po n sekundciu

    Rasyti(rez, min_greitis, vid, max_greitis, suma);

    return 0;
}

void Skaityti(const char name[], float A[][2], int &n, int &m)
{
    ifstream fd(name);
    fd >> m >> n;
    for (int i = 0; i < m; i++)
        fd >> A[i][0] >> A[i][1];
    fd.close();
}

float Atstumas(float x1, float y1, float x2, float y2)
{
    return sqrt( (fabs(x2-x1)*fabs(x2-x1)) + (fabs(y2-y1)*fabs(y2-y1)) );
}

void Rasyti(const char name[], float min_greitis, float vid, float max_greitis, float atstumas)
{
    ofstream fr(name);
    fr << "Maziausias greitis " << setprecision(2) << min_greitis << " mm/s" << endl;
    fr << "Vidutinis greitis " << setprecision(3) << vid << " mm/s" << endl;
    fr << "Didziausias greitis " << setprecision(3) << max_greitis << " mm/s" << endl;
    fr << "Is viso nukeliauta: " << setprecision(3) << atstumas << " mm" << endl;
    fr.close();
}
