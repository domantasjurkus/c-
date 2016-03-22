#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main()
{
    int n, a, suma = 0;
    float vid_metu, vid_men;
    ifstream fd("duom.txt");
    fd >> n;
    if (n>=30) cout << "Blogi duomenys"; else {

    for (int i = 0; i < n; i++) {
        fd >> a;
        suma += a;
        vid_metu = suma/n;
    }
    cout << "Suma: " << suma << endl;
    cout << "Per visus mokslo metus 1 mokinys vidutiniskai perskaite: " << round(vid_metu) << endl;
    cout << "Per 1 menesi 1 mokinys vidutiniskai perskaite: " << vid_metu/10 << endl;
    } return 0;
}
