#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
const char duomenys[] = "duomenys.txt";
const char rezultatas[] = "rezultatas.txt";
int main()
{
    int n,              //dienu skaicius
        p_dien,         //vieno programuotojo dienu skaicius
        a,              //vienos dienos programu skaicius
        p_sum = 0,      //visos vieno programuotojo programos
        prog_sum = 0,   //visu programu skaicius
        dien_sum = 0;   //dienu skaicius
    double prog_vid;    //visu programu vidurkis

    ifstream fd(duomenys);
    fd >> n;
     ofstream fr(rezultatas);
    for (int i = 0; i < n; i++) {
        fd >> p_dien;
        for (int j = 0; j < p_dien; j++) {
            fd >> a;
            p_sum += a;
            prog_sum += a;
        }
        dien_sum += p_dien;
        fr << p_sum << endl;
        p_sum = 0;
    }
    prog_vid = (float) prog_sum/dien_sum;
    fr << prog_sum << endl;
    fr << fixed << setprecision(1) << prog_vid << endl;
    fd.close();
    fr.close();
    cout << prog_sum << endl;
    cout << dien_sum << endl;
    cout << fixed << setprecision(1) << prog_vid << endl;
    return 0;
}
