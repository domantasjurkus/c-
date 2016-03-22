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
struct Turistas {
    string vardas;
    int litai;      //litai
    int l_centai;   //litu centai
    int bitai;      //bitai
    int b_centai;   //bitu centai
};
//kintamieji-----
Turistas T[Cmax];
int n = 0;                  //turistu skaicius
int surinkti_centai = 0;    //is visu turistu surinkti centai
int gauti_bitai = 0;        //gido gauti bitai
int gauti_centai = 0;       //gido gauti bitu sentai
int kursas = 0;             //kiek b_centu gaunama uz 100 centu
//funkcijos-----
void Skaityti(Turistas A[], int &n, int &kursas);
int KiekSurinkta(Turistas A[], int n);
void Keitimas(int kursas, int l_centai, int &bitai, int &b_centai);
void KiekGavoTuristai(Turistas A[], int n, int kursas);
void Spausdinti(Turistas A[], int n);
//pagrindine funkcija-----
int main()
{
    Skaityti(T, n, kursas);
    ofstream fr(rez);
    surinkti_centai = KiekSurinkta(T, n);
    fr << "Gidas surinko: " << surinkti_centai/100 << " " << surinkti_centai%100 << endl;

    Keitimas(kursas, surinkti_centai, gauti_bitai, gauti_centai);
    fr << "Gidas gavo: " << gauti_bitai << " " << gauti_centai << endl;
    fr.close();

    KiekGavoTuristai(T, n, kursas);
    Spausdinti(T, n);

    return 0;
}

void Skaityti(Turistas A[], int &n, int &kursas)
{
    int bitai = 0;      //naudojami skaitymui is failo
    int centai = 0;

    ifstream fd(duom);
    fd >> n;
    for (int i = 0; i < n; i++)
        fd >> A[i].vardas >> A[i].litai >> A[i].l_centai;
    fd >> bitai >> centai;
    kursas = bitai*100 + centai;    //bitus konvertuojam i centus
}

int KiekSurinkta(Turistas A[], int n)
{
    int surinkta = 0;
    for (int i = 0; i < n; i++)
        surinkta += A[i].litai*100 + A[i].l_centai;

    return surinkta;
}

void Keitimas(int kursas, int l_centai, int &bitai, int &b_centai)
{
    b_centai = (l_centai*kursas)/100;   //visus centus konvertuojam i bitu centus
                                        //kadangi kursas parodo kiek bitu centu gaunama uz 100 centu, reikia dar padalinti is 100
    bitai = b_centai/100;               //isgauname bitus
    b_centai = b_centai%100;            //isgauname bitu centus
}

void KiekGavoTuristai(Turistas A[], int n, int kursas)
{
    int litu_centai;
    for (int i = 0; i < n; i++)
    {
        litu_centai = A[i].litai*100 + A[i].l_centai;               //laikinai konvertuojam visus turisto litus  centus
        Keitimas(kursas, litu_centai, A[i].bitai, A[i].b_centai);   //taip patogiau naudoti funkcija
    }
}

void Spausdinti(Turistas A[], int n)
{
    ofstream fr(rez, ios::app);
    fr << "------------------------------------" << endl;
    fr << "Vardas           Turi       Gavo    " << endl;
    fr << "------------------------------------" << endl;
    for (int i = 0; i < n; i++)
    fr << setw(16) << left << T[i].vardas
         << setw(4) << right << T[i].litai
         << setw(4) << right << T[i].l_centai
         << setw(8) << right << T[i].bitai
         << setw(4) << right << T[i].b_centai << endl;
    fr.close();
}
