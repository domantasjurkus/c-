#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
const char duom[] = "duom.txt";
const char rez[] = "rez.txt";
const int Cmax = 256;
//----------
int Kiek(char sim);
void Rikiuoti(char S[], int A[], int n);
//----------
int main()
{
    char S[Cmax];   //raidziu masyvas
    int A[Cmax];    //raidziu pasikartojimo skaiciai
    int n = 0;      //raidziu kiekis

    /*cout << 'à' << (int) 'à' << endl;
    cout << 'è' << (int) 'è' << endl;
    cout << 'æ' << (int) 'æ' << endl;
    cout << 'ë' << (int) 'ë' << endl;
    cout << 'á' << (int) 'á' << endl;
    cout << 'ð' << (int) 'ð' << endl;
    cout << 'ø' << (int) 'ø' << endl;
    cout << 'û' << (int) 'û' << endl;
    cout << 'þ' << (int) 'þ' << endl;*/

    //ivedami duomenys
    for (char sim = 'a'; sim <= 'z'; sim++)
    {
        S[n] = sim;
        A[n] = Kiek(sim);
        n++;
    }
    S[n] = 'à'; A[n] = Kiek('à'); n++;
    S[n] = 'è'; A[n] = Kiek('è'); n++;
    S[n] = 'æ'; A[n] = Kiek('æ'); n++;
    S[n] = 'ë'; A[n] = Kiek('ë'); n++;
    S[n] = 'á'; A[n] = Kiek('á'); n++;
    S[n] = 'ð'; A[n] = Kiek('ð'); n++;
    S[n] = 'ø'; A[n] = Kiek('ø'); n++;
    S[n] = 'û'; A[n] = Kiek('û'); n++;
    S[n] = 'þ'; A[n] = Kiek('þ'); n++;

    Rikiuoti(S, A, n);

    //surasomi duomenys
    ofstream fr(rez);
    for (int i = 0; i < n; i++)
    {
        cout << S[i] << setw(4) << A[i] << endl;
    }
    fr.close();

    return 0;
}

//kiek kartu simbolis pasikartoja faile
int Kiek(char sim)
{
    char s;     //talpina simboli is failo
    int k = 0;  //pasikarotji skaicius
    ifstream fd(duom);
    while (!fd.eof())
    {
        fd.get(s);
        if(!fd.eof() && (tolower(s) == sim))
            k++;
    }
    fd.close();
    return k;
}

void Rikiuoti(char S[], int A[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(A[j] > A[i])
            {
                int sk = A[i];
                A[i] = A[j];
                A[j] = sk;
                char sim = S[i];
                S[i] = S[j];
                S[j] = sim;
            }
        }
    }
}
