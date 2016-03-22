#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
const char duomenys[] = "duomenys.txt";
const char rezultatas[] = "rezultatas.txt";
int main()
{
    int n, t;
    float t_sum = 0, t_vid;
    ifstream fd(duomenys);
    fd >> n;
    if ((n<1)||(n>50)) return 0;
    ofstream fr(rezultatas);
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < 7; j++){
            fd >> t;
            t_sum += t;
        }
        t_vid = t_sum/7;
        fr << i << " " << fixed << setprecision(3) << t_vid << endl;
        t_sum = 0;
    }
    fd.close();
    fr.close();
    return 0;
}
