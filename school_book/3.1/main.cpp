#include <iostream>
#include <fstream>
using namespace std;
const char duomenys[] = "duomenys.txt";
const char rezultatas[] = "rezultatas.txt";
int main()
{
    int x_min, x_max;
    ifstream fd(duomenys);
    fd >> x_min;
    fd >> x_max;
    fd.close();
    ofstream fr(rezultatas);
    for(int i = x_min; i <= x_max; i++) {
        for(int j = x_min; j < i; j++) {
            if ((i%j==0)&&((i-j)>0)){
                fr << i << " + "  << j << " = " << i+j << endl;
                fr << i << " - "  << j << " = " << i-j << endl;
                fr << i << " * "  << j << " = " << i*j << endl;
                fr << i << " / "  << j << " = " << i/j << endl;
                fr << "*********" << endl;
            }
        }
    }
    fr.close();
    return 0;
}
