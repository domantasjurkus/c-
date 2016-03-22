#include <iostream>
#include <fstream>
using namespace std;
const char duom[] = "U1.txt";
const char rez[] = "U1rez.txt";
//-----
const int cMax = 12;            //maksimalus žaidėjų skaičius
const int cNr = 99;             //maksimalus žaidėjo numeris
const int cT = 40;              //maksimalus laikas
//-----
int knr[cMax];      //krepšininkų numeriai
int zaista[cNr];    //kiek laiko žaista
int sedeta[cNr];    //kiek laiko sėdėta
int laikai[cT];     //LAIKINAS MASYVAS
int startinis5[4];  //startinio 5-to numeriai
int sind = 0;

int n;              //krapšininų skaičius
int k;              //rkrapšininkų numeris
int t;              //laiko tarpų kiekis
//-----
void skaityti();
void AtrinktiLaikus(int laikas, int i, int Z[], int S[]);
void Startinis5(int laikas, int ind, int startinis5[], int &sind);
//-----
int main()
{
    skaityti();

    cout << "-----" << endl;
    for (int i = 0; i < 5; i++)
        cout << startinis5[i] << endl;



    return 0;
}
//-----
void skaityti()
{
    ifstream fd(duom);
    fd >> n;                            //nuskaitome krapšininkų skaičių
    for (int i = 0; i < n; i++)         //einame per visus žaidėjus
    {
        fd >> k >> t;                   //nuskaitome krepšininko nr ir laiko tarpų skaičių
        knr[i] = k;                     //priskiriame krepšininko numerį masyvui
        for (int j = 0; j < t; j++)     //einame per laiko tarpus
        {
            fd >> laikai[j];            //tikriname vieną laiką
            cout << laikai[j] << endl;
            //priskiriame nuskaitytą laiką žaidimui arba sėdėjimui
            AtrinktiLaikus(laikai[j], i, zaista, sedeta);

            //jeigu skaitomas pirmas žaidėjo laikas ir jis yra teigiamas, priskiriame jį startiniam penketui
            if ((j == 0)&&(laikai[j]>0)){
                cout << "testing..." << endl;
                cout << "sind: " << sind << endl;
                startinis5[sind] = knr[i];
                sind++;
            }
        }
    }

    fd.close();
}

void AtrinktiLaikus(int laikas, int i, int Z[], int S[])
{
    if (laikas > 0)         //jeigu laikas teigiamas
        Z[i] += laikas;     //jis pridedamas prie žaidėjo žaidimo laiko
    else                    //kitu atveju
        S[i] -= laikas;     //jis pridedamas prie žaidėjo sėdėjimo laiko

}

void Startinis5(int laikas, int ind, int startinis5[], int &sind)
{
    if (laikas > 0)                 //jeigu laikas teigiamas
        startinis5[sind] = ind;     //startinio 5-to žaidėjas yra einamo žaidėjo indeksas
}
