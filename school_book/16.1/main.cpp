#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
const char duom[] = "duom.txt";
const char rez[] = "rez.txt";
const int Cmax = 500;       //masyvo limitas
const int Cpav = 20;        //pavadinimo simboliø limitas
//-----
struct Albumas{
    string pav;
    int metai;
    int valan;
    int minut;
    int kartai;
};
//-----
void Skaityti(Albumas A[], int &n);
void Rikiuoti(Albumas A[], int n);
void BendrasLaikas(Albumas A[], int n, int &visos_h, int &visos_m);
double Vidurkis(Albumas A[], int n);
void Spausdinti(Albumas A[], int n, int visos_h, int visos_min, double vid);
//-----
int main()
{
    Albumas A[Cmax];
    int n = 0;          //visus skaitinius kintamuosius iðkart priskiriam 0
    int visos_h = 0;    //kad programa stabiliau veiktø
    int visos_m = 0;

    Skaityti(A, n);
    Rikiuoti(A, n);
    BendrasLaikas(A, n, visos_h, visos_m);

    double vid = Vidurkis(A, n);

    Spausdinti(A, n, visos_h, visos_m, vid);

    return 0;
}

void Skaityti(Albumas A[], int &n)
{
    char eil[Cpav+1];           //+1 dël '\0' simbolio
    ifstream fd(duom);
    fd >> n;
    fd.ignore(80, '\n');        //á kità eilutæ
    for (int i = 0; i < n; i++)
    {
        fd.get(eil, Cpav);      //pirma paimame pavadinimà ið failo á simboliø masyvà
        A[i].pav = eil;         //tada já priskiriame albumo masyvui
        fd >> A[i].metai
           >> A[i].valan
           >> A[i].minut
           >> A[i].kartai;
        fd.ignore(80, '\n');    //á kità eilutæ
    }
    fd.close();
}

void Rikiuoti(Albumas A[], int n)
{
    Albumas temp;               //laikinas albumas
    for (int i = 0; i < n-1; i++)
        for (int j = i; j < n; j++)
            if (A[j].kartai <= A[i].kartai)
            {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
}

void Spausdinti(Albumas A[], int n, int visos_h, int visos_min, double vid)
{
    ofstream fr(rez);
    fr << visos_h << " " << visos_min << endl;
    fr << setprecision(3) << vid << endl;
    for (int i = 0; i < n; i++)
    {
        fr << setw(20) << left << A[i].pav << A[i].metai << endl;
    }
    fr.close();
}

void BendrasLaikas(Albumas A[], int n, int &visos_h, int &visos_m)
{
    //naudojam 'void' kadangi reikia pakeisti du kintamuosius (visos_h ir visos_m)

    //skaitome laikà ið masyvo
    for (int i = 0; i < n; i++)
    {
        visos_h += A[i].valan;
        visos_m += A[i].minut;
    }

    //konvertuojame minutes
    while (visos_m >= 60)
    {
        visos_h++;
        visos_m -= 60;
    }
}

double Vidurkis(Albumas A[], int n)
{
    double visi = 0;
    double vid = 0;

    for (int i = 0; i < n; i++)
        visi += A[i].kartai;

    vid = visi/n;

    return vid;
}
