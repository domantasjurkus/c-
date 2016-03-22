#include <iostream>
#include <fstream>
const char duom[] = "duom.txt";
const char rez[] = "rez.txt";
const int Cmax = 100;
using namespace std;
//----------
void Skaityti(const char name[], int A[], int &n, int &k);
void KeistiMasyva(int senas[], int naujas[], int n);
int RastiKieki(int A[], int n);
void Spausdinti(const char name[], int A[], int max_naktis, int min_naktis, int n);
//----------
int main()
{
    //0 < n < 101   -   apriboja Cmax
    //0 < k < 101   -   kaip apriboti?

    int n,              //zibintu skaicius
        k,              //naktu skaicius
        Aprad[Cmax],    //naktis, is kurios skaitoma
        Anau[Cmax],     //naktis, i kuria rasoma
        max_kiekis,
        min_kiekis,
        max_naktis = 1,  //naktis, kai zibejo daugiausia
        min_naktis = 1;  //naktis, kai zibejo maziausia

    Skaityti(duom, Aprad, n, k);    //nuskaitom, parasom pirmos nakties
    cout << "1 naktis: ";
    for (int i = 0; i < n; i++)
        cout << Aprad[i];
    cout << endl;
    max_kiekis = RastiKieki(Aprad, n);
    min_kiekis = RastiKieki(Aprad, n);

    //norint rasti paskutines nakties nakties kombinacija, reikia pereiti per visas naktis po viena
    for (int j = 2; j <= k; j++)        //eina per visas naktis, pradedam skaiciuoti tik nuo antros
    {
        for (int i = 0; i < n; i++)     //eina per visus zibintus
        {
            //<> - einamas zibintas
            //jeigu            1 <> 1                ir zibintas nera krastinis
            if (((Aprad[i-1]==1) && (Aprad[i+1]==1)) && (i!=0) && (i!=n-1)) //n-1, nes masyvo nariai prasideda nuo 0
                Anau[i] = 0;

            //jeigu                  0 <> 1               ARBA               1 <> 0                 ir zibintas nera krastinis
            else if ((((Aprad[i-1]==0) && (Aprad[i+1]==1)) || ((Aprad[i-1]==1) && (Aprad[i+1]==0))) && (i!=0) && (i!=n-1))
                Anau[i] = 1;

            //kitu atveju, jeigu naktis lygine
            else if (j%2==0)
                Anau[i] = 1;
            else
                Anau[i] = 0;
        }

        cout << j << " naktis: ";       //parasom einamos nakties kombinacija
        for (int c = 0; c < n; c++)     //galit istrinti, bet palikau del aiskumo
            cout << Anau[c];
        cout << endl;

        //ziurime, ar einama naktis turi maksimalu/minimalu sviecianciu zibintu kieki
        if (RastiKieki(Anau, n) > max_kiekis)   //jeigu einama naktis turi daugiau zibintu
        {
            max_kiekis = (RastiKieki(Anau, n));
            max_naktis = j;
        }
        if (RastiKieki(Anau, n) < min_kiekis)   //jeigu einama naktis turi daugiau zibintu
        {
            min_kiekis = (RastiKieki(Anau, n));
            min_naktis = j;
        }

        KeistiMasyva(Aprad, Anau, n);   //Katik rastas Anau reiksmas priskiriam Aprad
    }

    Spausdinti(rez, Anau, max_naktis, min_naktis, n);

    return 0;
}

void Skaityti(const char name[], int A[], int &n, int &k)
{
    ifstream fd(name);
    fd >> n >> k;
    for (int i = 0; i < n; i++)
        fd >> A[i];

}

void KeistiMasyva(int senas[], int naujas[], int n)
{
    for (int i = 0; i < n; i++)
        senas[i] = naujas[i];
}

int RastiKieki(int A[], int n)
{
    int kiekis = 0;
    for (int i = 0; i < n; i++)
        if(A[i]==1) kiekis++;
    return kiekis;
}

void Spausdinti(const char name[], int A[], int max_naktis, int min_naktis, int n)
{
    ofstream fr(name);
    for (int i = 0; i < n; i++)
        fr << A[i] << " ";
    fr << endl;
    fr << "Daugiausia sviete " << max_naktis << " nakti." << endl;
    fr << "Maziausia sviete " << min_naktis << " nakti." << endl;
    fr.close();
}
