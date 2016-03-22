#include <iostream>
#include <fstream>
const char duom[] = "duom.txt";
const char rez[] = "rez.txt";
const int Cmax = 26;
using namespace std;
//----------
int n;              //korteliu skaicius
int rau[Cmax],      //korteliu numeriu masyvai
    gel[Cmax],
    mel[Cmax],
    juo[Cmax],
    rau_ind = 0,    //indeksai, parodantys kiek korteliu yra kiekviename masyve
    gel_ind = 0,
    mel_ind = 0,
    juo_ind = 0;
//----------
void Skaityti(const char name[], int &n);
void Rikiuoti(int A[], int m);
void RastiSeka(int A[], int m);
//----------
int main()
{
    Skaityti(duom, n);
    Rikiuoti(rau, rau_ind);
    Rikiuoti(gel, gel_ind);
    Rikiuoti(mel, mel_ind);
    Rikiuoti(juo, juo_ind);

    for(int i = 0; i < mel_ind; i++)
        cout << mel[i] << endl;

    return 0;
}

void Skaityti(const char name[], int &n)
{
    ifstream fd(name);
    char a;     //einama raide
    fd >> n;
    for (int i = 0; i < n; i++)
    {
        fd >> a;

        if (a=='R'){
            fd >> rau[rau_ind];
            rau_ind++;
        }

        else if (a=='G'){
            fd >> gel[gel_ind];
            gel_ind++;
        }

        else if (a=='M'){
            fd >> mel[mel_ind];
            mel_ind++;
        }

        else {
            fd >> juo[juo_ind];
            juo_ind++;
        }
    }
    fd.close();
}

void Rikiuoti(int A[], int m)
{
    int temp;   //laikina reiksme
    for (int i = 0; i < m-1; i++)
        for (int j = i+1; j < m; j++)
        {
            if (A[i] > A[j])
            {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
}

void RastiSeka(int A[], int m)
{
    for (int i = 2; i < m; i++)     //sekoje turi buti maziausiai 3 nariai, tad pradedam nuo 2 indekso
    {
        for (int j = i; j >= 0; j--)
        {

        }
    }
}
