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

    /*cout << '�' << (int) '�' << endl;
    cout << '�' << (int) '�' << endl;
    cout << '�' << (int) '�' << endl;
    cout << '�' << (int) '�' << endl;
    cout << '�' << (int) '�' << endl;
    cout << '�' << (int) '�' << endl;
    cout << '�' << (int) '�' << endl;
    cout << '�' << (int) '�' << endl;
    cout << '�' << (int) '�' << endl;*/

    //ivedami duomenys
    for (char sim = 'a'; sim <= 'z'; sim++)
    {
        S[n] = sim;
        A[n] = Kiek(sim);
        n++;
    }
    S[n] = '�'; A[n] = Kiek('�'); n++;
    S[n] = '�'; A[n] = Kiek('�'); n++;
    S[n] = '�'; A[n] = Kiek('�'); n++;
    S[n] = '�'; A[n] = Kiek('�'); n++;
    S[n] = '�'; A[n] = Kiek('�'); n++;
    S[n] = '�'; A[n] = Kiek('�'); n++;
    S[n] = '�'; A[n] = Kiek('�'); n++;
    S[n] = '�'; A[n] = Kiek('�'); n++;
    S[n] = '�'; A[n] = Kiek('�'); n++;

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
