#include <fstream>
#include <string>
using namespace std;
const char duom[] = "U2.txt";
const char rez[] = "U2rez.txt";
const int cMax_m = 103;
const int cMax_a = 10;
const int cEil1 = 20;
const int cEil2 = 13;
//-----
struct Miestas{
    string pav;
    string aps;
    int gyventojai;
};
//-----
struct Apskritis{
    string pav;
    int gyventojai;
    int min_gyventojai;
};
//-----
void skaityti(Miestas M[], int &k);
void atrinkti(Miestas M[], int k, Apskritis A[], int &m);
int ar_yra(Apskritis A[], int m, string pav);
void rikiuoti(Apskritis A[], int m);
void spausdinti(Apskritis A[], int m);
//-----
int main()
{
    Miestas M[cMax_m];      //miestø masyvas
    int k = 0;              //miestø skaièius
    Apskritis A[cMax_a];    //apskrièiø masyvas
    int m = 0;              //apskrièiø skaièius

    skaityti(M, k);
    atrinkti(M, k, A, m);
    rikiuoti(A, m);
    spausdinti(A, m);

    return 0;
}

void skaityti(Miestas M[], int &k)
{
    char eil1[cEil1 + 1];
    char eil2[cEil2 + 1];
    ifstream fd(duom);

    fd >> k;
    fd.ignore(80, '\n');
    for (int i = 0; i < k; i++)
    {
        fd.get(eil1, cEil1);
        M[i].pav = eil1;
        fd.get(eil2, cEil2);
        M[i].aps = eil2;
        fd >> M[i].gyventojai;
        fd.ignore(80, '\n');
    }

    fd.close();
}

void atrinkti(Miestas M[], int k, Apskritis A[], int &m)
{
    m = 0;

    for (int i = 0; i < k; i++)
    {
        int ind = ar_yra(A, m, M[i].aps);
        if (ind == -1)                                      //jeigu apskritis nerasta
        {
            A[m].pav = M[i].aps;                            //priskiriame naujà apskrities pavadinimà
            A[m].gyventojai = M[i].gyventojai;              //priskriame gyvantojø skaièiø ið to miesto
            A[m].min_gyventojai = M[i].gyventojai;
            m++;
        }
        else                                                //jeigu miestas jau yra sàraðe
        {
            A[ind].gyventojai += M[i].gyventojai;           //pridedame gyventojø skaièiø
            if (A[ind].min_gyventojai > M[i].gyventojai)    //tikriname, ar mieste yra kol kas maþiausias gyventojø skaièius
                A[ind].min_gyventojai = M[i].gyventojai;
        }
    }
}

int ar_yra(Apskritis A[], int m, string pav)
{
    for (int i = 0; i < m; i++)
        if (A[i].pav == pav)
            return i;
    return -1;
}

void rikiuoti(Apskritis A[], int m)
{
    Apskritis temp;
    for (int i = 0; i < m-1; i++)
    {
        for (int j = i+1; j < m; j++)
        {
            if (A[j].min_gyventojai < A[i].min_gyventojai)
            {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
}

void spausdinti(Apskritis A[], int m)
{
    ofstream fr(rez);

    fr << m << endl;
    for (int i = 0; i < m; i++)
    {
        fr << A[i].pav << A[i].min_gyventojai << " " << A[i].gyventojai << endl;
    }
    fr.close();
}
