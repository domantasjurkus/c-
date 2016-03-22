#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
const char duom[] = "duom.txt";
const char rez[] = "rez.txt";
const int Cmax = 100;
const int Cpav = 20;
//-----
struct Mokinys{
    string vardas;
    string pavarde;
    int kiek;
};
//-----
void Skaityti(Mokinys A[], int &n);
void Atrinkti(Mokinys A[], int n, Mokinys B[], int &k);
int ArYra(Mokinys B[], int k, string pav);
void Rikiuoti(Mokinys A[], int n);
void Spausdinti(Mokinys A[], int n);
//-----
int main()
{
    Mokinys M[Cmax];    //pradinis mokiniu sarasas
    int n = 0;
    Mokinys At[Cmax];   //surikiuotas mokiniu sarasas
    int k = 0;

    Skaityti(M, n);
    Atrinkti(M, n, At, k);
    Rikiuoti(At, k);
    Spausdinti(At, k);

    return 0;
}

void Skaityti(Mokinys A[], int &n)
{
    char eil[Cpav+1];

    ifstream fd(duom);
    fd >> n;
    fd.ignore(80, '\n');

    for (int i = 0; i < n; i++)
    {
        fd.get(eil, Cpav+1);            //skaitome pavarde
        A[i].pavarde = eil;             //priskiriame pavarde
        getline(fd, A[i].vardas);       //skaitome varda
        A[i].kiek = 1;                  //priskiriame pradini vardo pasikartojimo skaiciu
    }

    fd.close();
}

void Atrinkti(Mokinys A[], int n, Mokinys B[], int &k)
{
    k = 0;                  //is pradziu atrinktame masyve nera nariu
    for (int i = 0; i < n; i++)
    {
        int ind = ArYra(B, k, A[i].vardas);
        if (ind >= 0)
            B[ind].kiek++;
        else
        {
            B[k] = A[i];
            k++;
        }
    }
}

//patikriname, ar atrinktame sarase jau yra tikrinamas vardas,
//ir graziname masyvo indeksa jeigu vardas jau yra
int ArYra(Mokinys B[], int k, string pav)
{
    for (int i = 0; i < k; i++)
        if (B[i].vardas == pav)
            return i;
    return -1;
}

void Rikiuoti(Mokinys A[], int n)
{
    //pirma surikiuojame pagal kieki
    Mokinys temp;

    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (A[j].kiek < A[i].kiek)
            {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }

    //po to rikiuojame pagal abecele
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if ((A[j].vardas < A[i].vardas)&&(A[j].kiek == A[i].kiek))
            {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
}

void Spausdinti(Mokinys A[], int n)
{
    ofstream fr(rez);
    for (int i = 0; i < n; i++)
        fr << setw(20) << left << A[i].vardas << A[i].kiek << endl;
    fr.close();
}
