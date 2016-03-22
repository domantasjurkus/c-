#include <iostream>
#include <fstream>
using namespace std;
const char duom[] = "duom.txt";
//-----
void skaityti(ifstream fd, int kodas[]);
//-----
int main()
{
    int n,
        maxv[11],
        maxm[11],
        kodas[11];
    ifstream fd(duom);
    fd >> n;

    //func, skaityti
    long long kodo_skaicius;
    long long skaitmuo;
    fd >> kodo_skaicius;
    cout << kodo_skaicius << endl;

    for (int i = 0; i <= 10; i++)
    {
        skaitmuo = kodo_skaicius%(10^i);
        cout << skaitmuo;
    }

    return 0;
}

void skaityti(ifstream fd, int kodas[])
{

}
