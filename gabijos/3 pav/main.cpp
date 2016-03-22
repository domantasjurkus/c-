#include <iostream>
using namespace std;

int main ()
{
    int h,min, t;
    cout << "Laikrodis" << endl;
    cout << "Valandu skaicius: ";
    cin >> h;
    cout << "Minuciu skaicius: ";
    cin >> min;
    t = h*60 + min;
    if (t >= 1440)
    {
        cout << t-1440;
    }
    h = t/60;
    min = t%60;
    cout << "laikas minutemis: " << t << endl;
    cout << h << ":" << min;
    return 0;
}
