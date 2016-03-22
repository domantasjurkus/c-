#include <iostream>
#include <fstream>
using namespace std;
const char duom[] = "duom.txt";
const char rez[] = "rez.txt";
const int cMax = 100;
//----------
void skaityti(const char name[], int m[], int d[], float mase[], int bar[], int rau[], int &n);
int RastiMaxIndFloat(float A[], int n);
int RastiMaxIndInt(int A[], int n);
void spausdinti(const char name[], int m[], int d[], float mase[], int bar[], int rau[], int mas_ind, int bar_ind, int rau_ind);
//----------
int main()
{
    int n;
    int menuo[cMax];    //visi reikalingi masyvai
    int diena[cMax];
    float mase[cMax];
    int bar[cMax];
    int rau[cMax];

    skaityti(duom, menuo, diena, mase, bar, rau, n);

    int mas_ind = RastiMaxIndFloat(mase, n);    //randame indeksus su didziausiomis reiksmemis
    int bar_ind = RastiMaxIndInt(bar, n);       //svoris - su kableliu, o grybu skaicius - sveikieji skaiciai
    int rau_ind = RastiMaxIndInt(rau, n);       //todel tenka naudoti atskiras radimo funkcijas

    spausdinti(rez, menuo, diena, mase, bar, rau, mas_ind, bar_ind, rau_ind);

    return 0;
}

void skaityti(const char name[], int m[], int d[], float mase[], int bar[], int rau[], int &n)
{
    ifstream fd(name);
    fd >> n;
    for (int i = 0; i < n; i++){
        fd >> m[i] >> d[i] >> mase[i] >> bar[i] >> rau[i];
    }
    fd.close();
}

int RastiMaxIndFloat(float A[], int n)
{
    int max_ind = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > A[max_ind])
            max_ind = i;
    }
    return max_ind;
}

int RastiMaxIndInt(int A[], int n)
{
    int max_ind = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > A[max_ind])
            max_ind = i;
    }
    return max_ind;
}

void spausdinti(const char name[], int m[], int d[], float mase[], int bar[], int rau[], int mas_ind, int bar_ind, int rau_ind)
{
    ofstream fr(name);

    fr << "Derlingiausia diena: ";
    if (mase[mas_ind] == 0)             //jeigu is viso nebuvo surinkta grybu
        cout << "Nera" << endl;
    else
        cout << m[mas_ind] << " " << d[mas_ind] << endl;        //paraso menesi ir diena, kada buvo didziausias kiekis

    fr << "Daugiausia baravyku: ";      //o po to kartojam su kitais
    if (bar[bar_ind] == 0)
        cout << "Nera" << endl;
    else
        cout << m[bar_ind] << " " << d[bar_ind] << endl;

    fr << "Daugiausia raudonvirsiu: ";
    if (rau[rau_ind] == 0)
        cout << "Nera" << endl;
    else
        cout << m[rau_ind] << " " << d[rau_ind] << endl;
    fr.close();
}
