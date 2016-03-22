#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
const char duom[] = "U2.txt";
const char rez[] = "U2rez.txt";
const char CMax = 60;
const char CPav = 20;
//-----
struct sav{
    string pav;
    string apskritis;
    int kiek_mokyklu;
    int kiek_savivaldybiu;
};
//-----
void Skaityti(sav S[], int &k);
void Atrinkti(sav A[], int n, sav B[], int &m);
int Yra(sav B[], int m, string pav);
void RastiMaxMokyklu(sav A[], int k, sav B[], int m);
void Rikiuoti(sav B[], int m);
void Spausdinti(sav A[], int n, string pav);
//-----
int main()
{
    sav A[CMax];    //savivaldybiø masyvas
    int k;          //savivaldybiø skaièius
    sav B[10];     //apskriciu masyvas
    int m;          //apskriciu skaicius

    Skaityti(A, k);
    Atrinkti(A, k, B, m);
    RastiMaxMokyklu(A, k, B, m);
    Rikiuoti(B, m);
    Spausdinti(B, m, "Atrinktas sarasas:");

    return 0;
}

void Skaityti(sav S[], int &k)
{
    ifstream fd(duom);
    char sav_eil[CPav + 1];

    fd >> k;
    fd.ignore(80, '\n');

    for (int i = 0; i < k; i++)
    {
        fd.get(sav_eil, CPav);          //skaitome savivaldybės pavadinimą
        S[i].pav = sav_eil;

        fd >> S[i].kiek_mokyklu;        //skaitome mokyklų skaičių
        fd.ignore(80, '\n');

        getline(fd, S[i].apskritis);    //skaitome apskritį
        S[i].kiek_savivaldybiu = 1;     //priskiriame pradinį savivaldybių skaičių
    }
}

void Atrinkti(sav A[], int k, sav B[], int &m)
{
    m = 0;
    for (int i = 0; i < k; i++)
    {
        int k = Yra(B, m, A[i].apskritis);      //tikriname, ar jau atrinktame masyve yra apskritis
        if (k >= 0){                            //jeigu yra
            B[k].kiek_savivaldybiu++;           //padidiname apskrities savivaldybiu skaičiu
        }
        else {                                  //jeigu nėra
            B[m] = A[i];                        //kopijuojame narį iš duomenų masyvo
            B[m].kiek_mokyklu = 0;              //išvalome mokyklų skaičių
            m++;                                //padidiname atrinktu nariu indeksa
        }
    }
}

int Yra(sav B[], int m, string pav)
{
    for (int i = 0; i < m; i++)
        if (B[i].apskritis == pav)
            return i;
    return -1;
}

void RastiMaxMokyklu(sav A[], int k, sav B[], int m)
{
    for (int i = 0; i < m; i++)                                     //einame per apskričių masyvą
        for (int j = 0; j < k; j++)                                 //einam per duomenų masyvą
            //jeigu     randame tą pačią apskritį  ir   ji turi daugiau mokyklų negu iki šiol rasta
            if ((B[i].apskritis == A[j].apskritis) && (A[j].kiek_mokyklu > B[i].kiek_mokyklu))
                B[i].kiek_mokyklu = A[j].kiek_mokyklu;              //priskiriam naują maksimumą razultatų masyvui
}

void Rikiuoti(sav B[], int m)
{
    sav temp;
    for (int i = 0; i < m-1; i++)
    {
        for (int j = i+1; j < m; j++)
        {
            if (B[j].kiek_mokyklu > B[i].kiek_mokyklu)          //jeigu rasta daugiau mokyklų
            {
                temp = B[i];                                    //sukeičiam
                B[i] = B[j];
                B[j] = temp;
            }
            else if (B[j].kiek_mokyklu == B[i].kiek_mokyklu)    //jeigu mokyklų tiek pat
                if (B[j].apskritis < B[i].apskritis)            //tačiau jeigu vienos pavadinimas tolesnis abecelėje
            {
                temp = B[i];                                    //irgi sukeičiam
                B[i] = B[j];
                B[j] = temp;
            }
        }
    }

}

void Spausdinti(sav A[], int k, string pav)
{
    ofstream fr(rez);
    fr << k << endl;
    for (int i = 0; i < k; i++)
        fr << setw(13) << left << A[i].apskritis << A[i].kiek_savivaldybiu
             << " " << A[i].kiek_mokyklu << endl;
    fr.close();
}
