#include <iostream>
#include <fstream>
using namespace std;
const char duom[] = "duom.txt";
const char rez[] = "rez.txt";
const int Cmax = 256;
int main()
{
    char a, b;
    int k = 0;

    ifstream fd(duom);
    fd >> a >> b;
    while (!fd.eof())
    {
        if ((a == 'a') && (b == 'u')) k++;
        a = b;
        fd >> b;
    }

    cout << k;

    return 0;
}
