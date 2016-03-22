#include <iostream>
#include <fstream>
using namespace std;
const char duom[] = "U1.txt";
const char rez[] = "U1rez.txt";
const int Cmax = 100;
//----------
int n,                          //kiek ið viso pirðtiniø
    vyr_kai[Cmax], vki = 0,     //masyvai, talpinantys pagal lytá ir rankà
    vyr_des[Cmax], vdi = 0,     //bei indeksai, parodantys kiek nariø yra masyvuose
    mot_kai[Cmax], mki = 0,
    mot_des[Cmax], mdi = 0;
//----------
void Skaityti(const char name[], int &n);
int KiekPoru(int A[], int B[], int a_ind, int b_ind);
int KiekLaisvu(int kaires, int desines, int poros);
void Rasyti(const char name[], int mot_por, int vyr_por, int mot_lais, int vyr_lais);
//----------
int main()
{
    Skaityti(duom, n);                                      //skaitom duomenis

    int vyr_por = KiekPoru(vyr_kai, vyr_des, vki, vdi);     //ieðkome porø
    int mot_por = KiekPoru(mot_kai, mot_des, mki, mdi);
    int vyr_lais = KiekLaisvu(vki, vdi, vyr_por);           //ieðkome laisvø
    int mot_lais = KiekLaisvu(mki, mdi, mot_por);

    Rasyti(rez, mot_por, vyr_por, mot_lais, vyr_lais);      //áraðome rezultatus

    return 0;
}

void Skaityti(const char name[], int &n)
{
    int lytis = 0;                  //3 - vyriðka, 4 - moteriðka
    int ranka = 0;                  //1 - kairë, 2 - deðinë
    ifstream fd(name);
    fd >> n;
    for (int i = 0; i < n; i++)
    {
        fd >> lytis >> ranka;

        if (lytis == 3)             //jeigu vyriðka
            if (ranka == 1){        //jeigu kairë
                fd >> vyr_kai[vki];
                vki++;
            }
            else {                  //jeigu deðinë
                fd >> vyr_des[vdi];
                vdi++;
            }

        else                        //jeigu moteriðka
            if (ranka == 1){
                fd >> mot_kai[mki];
                mki++;
            }
            else {
                fd >> mot_des[mdi];
                mdi++;
            }
    }
    fd.close();
}

int KiekPoru(int A[], int B[], int a_ind, int b_ind)
{
    //a_ind ir b_ind parodo, kiek nariø yra masyvuose A ir B
    int poros = 0;
    for (int i = 0; i < a_ind; i++)         //einame per pirma masyva
    {
        for (int j = 0; j < b_ind; j++)     //einame per antra masyva
        {
            if (A[i] == B[j])               //jeigu randame pora
            {
                poros++;
                B[j] = -1;      //A masyvo nekeièiam, o B masyve iraðome -1 reikðmes ten,
                                //kur rasta pora - taip poros neatsikartos
            }
        }
    }
    return poros;
}

int KiekLaisvu(int kaires, int desines, int poros)
{
    int laisvos = (kaires + desines) - poros * 2;       //ið visø pirðtiniø atimame rastas poras
    return laisvos;
}

void Rasyti(const char name[], int mot_por, int vyr_por, int mot_lais, int vyr_lais)
{
    ofstream fr(name);
    fr << mot_por << endl;
    fr << vyr_por << endl;
    fr << mot_lais << endl;
    fr << vyr_lais << endl;
    fr.close();
}
