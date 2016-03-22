#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
const char duom[] = "duom.txt";
const char rez[] = "rez.txt";
const int Cmax = 256;
//----------
int Kiek(char sim);
//----------
int main()
{
    char S[Cmax];       //simboliu masyvas
    int A[Cmax];        //smboliu pasikartojimo skaiciai
    int n = 0;

    for (char i = '0'; i <= '9'; i++)
    {
        S[n] = i;
        A[n] = Kiek(i);
        cout << S[n] << " " << A[n] << endl;
        n++;
    }


    return 0;
}

int Kiek(char sim)
{
    char s;     //talpina simboli
    int k = 0;  //skaiciuoja pasikartojimus

    ifstream fd(duom);
    while (!fd.eof())
    {
        fd.get(s);
        if (!fd.eof() && (s == sim))
            k++;
    }
    fd.close();
    return k;
}
