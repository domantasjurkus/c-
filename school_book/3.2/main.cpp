#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
const char duomenys[] = "duomenys.txt";
const char rezultatas[] = "rezultatas.txt";
int main()
{
    int n, m;
    float a,
          sum1 = 0,
          sum = 0;
    ifstream fd(duomenys);
    fd >> n;
    fd >> m;
    ofstream fr(rezultatas);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            fd >> a;
            sum1 += a;
            sum += a;
        }
        fr << i << " " << fixed << setprecision(2) << sum1 << endl;
        sum1 = 0;
    }
    fr << sum;
    fd.close();
    fr.close();
    return 0;
}
