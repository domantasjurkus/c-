#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int main()
{
    int n;
    ifstream fd("duom.txt");
    fd >> n;
    if ((n<1)||(n>=500)) return 0;

    int visu_suma = 0,
        k_suma = 0,
        d_suma = 0,
        nr,
        k;
    for (int i = 1; i <= n; i++){
        fd >> nr >> k;
        visu_suma += k;
        if (i%2==00) d_suma += k;
        else k_suma += k;
    }
    //o jeigu n nelyginis...
    int dal;
    if (n%2==0) dal = 0;
    else dal = 1;
    cout << "Is viso gyvena: " << visu_suma << endl;
    cout << "Kaireje: " << k_suma << endl;
    cout << "Desineje: " << d_suma << endl;
    cout << "Kaireje vidutiniskai: " << setprecision(2) << (float)k_suma/((n/2)+dal) << endl;
    cout << "Desineje vidutiniskai: " << setprecision(2) << (float)d_suma/(n/2) << endl;
    return 0;
}
