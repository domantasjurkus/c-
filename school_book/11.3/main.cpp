#include <iostream>
#include <fstream>
using namespace std;
const char duom[] = "main.cpp";
int main()
{
    char a, b;              //blablabla
    int k = 0;              //blablabla
    ifstream fd(duom);
    fd >> a >> b;
    while(!fd.eof())
    {
        if ((a == '/') && (b == '/')) k++;
        a = b;
        fd >> b;
    }

    cout << k;

    return 0;
}
