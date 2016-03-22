#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const char duom[] = "Z1.txt";
const char rez[] = "Z1rez.txt";
const int cMax = 100;
const int cPav = 20;
//-----
struct pirkejas{
    string vardas;
    int perkama;
    int nupirkta_1kg;
    int nupirkta_2kg;
};
//-----
struct ukininkas{
    string vardas;
    int pak_1kg;
    int pak_2kg;
};
//-----
void skaityti(pirkejas P[], int &np, ukininkas U[], int &nu);
int kiek_reikia(pirkejas P[], int np, int kg);
int kiek_atvezta(ukininkas U[], int nu, int kg);
bool ar_uzteks(int atvezta_1kg, int atvezta_2kg, int reikia_1kg, int reikia_2kg);
//-----
int main()
{
    pirkejas P[cMax];       //pirkëjø masyvas
    ukininkas U[cMax];      //ûkininkø masyvas
    int np = 0;             //pirkëjø skaièius
    int nu = 0;             //ûkininkø skaièius

    skaityti(P, np, U, nu);

    int reikia_2kg = kiek_reikia(P, np, 2);
    int reikia_1kg = kiek_reikia(P, np, 1);
    int atvezta_2kg = kiek_atvezta(U, nu, 2);
    int atvezta_1kg = kiek_atvezta(U, nu, 1);
    bool ar_usteks = ar_uzteks(atvezta_1kg, atvezta_2kg, reikia_1kg, reikia_2kg);

    return 0;
}
void skaityti(pirkejas P[], int &np, ukininkas U[], int &nu)
{
    char eil[cPav+1];
    ifstream fd(duom);

    //skaitome pirkëjø duomenis
    fd >> np;
    fd.ignore(80, '\n');
    for (int i = 0; i < np; i++)
    {
        fd.get(eil, cPav);
        P[i].vardas = eil;
        fd >> P[i].perkama;
        fd.ignore(80, '\n');
    }

    //skaitome ûkininkø duomenis
    fd >> nu;
    fd.ignore(80, '\n');
    for (int i = 0; i < nu; i++)
    {
        fd.get(eil, cPav);
        U[i].vardas = eil;
        fd >> U[i].pak_1kg
           >> U[i].pak_2kg;
        fd.ignore(80, '\n');
    }
}

int kiek_reikia(pirkejas P[], int np, int kg)
{
    int sk = 0;

    if (kg == 2)                        //jeigu ieškomas 2kg pakuočių skaičius
        for (int i = 0; i < np; i++)
            sk += P[i].perkama / 2;
    else                                //jeigu ne, telieka 1kg pakuotės
        for (int i = 0; i < np; i++)
            sk += P[i].perkama % 2;

    return sk;
}

int kiek_atvezta(ukininkas U[], int nu, int kg)
{
    int sk = 0;

    if (kg == 2)
        for (int i = 0; i < nu; i++)
            sk += U[i].pak_2kg;
    else
        for (int i = 0; i < nu; i++)
            sk += U[i].pak_1kg;
    return sk;
}

bool ar_uzteks(int atvezta_1kg, int atvezta_2kg, int reikia_1kg, int reikia_2kg)
{
    int atvezta = atvezta_1kg + 2*atvezta_2kg;
    int reikia = reikia_1kg + 2*reikia_2kg;
    if (atvezta >= reikia)
        return true;
    else
        return false;
}
