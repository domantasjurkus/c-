#include <iostream>
#include <fstream>
using namespace std;
const char duom[] = "duom.txt";

int main()
{
    int raidziu_k = 0;
    int skaiciu_k = 0;
    int tarpu_k = 0;
    int kitu_k = 0;
    int k = 0;      //visu simboliu kiekis
    char s;         //tikrinamas simbolis

    ifstream fd(duom);
    while (!fd.eof())
    {
        fd.get(s);
        s = tolower(s);
        if (((int)s >= 97) && ((int)s <= 122) && (!fd.eof()))
            raidziu_k++;

        //diakritiniai
        if ( ((int)s == -32) &&   ((int)s == -64) &&        //à
           ((int)s == -24)  &&   ((int)s == -56) &          //è
           ((int)s == -26)  &&   ((int)s == -58) &&         //æ
           ((int)s == -21)  &&   ((int)s == -53) &&         //ë
           ((int)s == -31)  &&   ((int)s == -63) &&         //á
           ((int)s == -16)  &&   ((int)s == -48) &&         //ð
           ((int)s == -8)   &&   ((int)s == -40) &&         //ø
           ((int)s == -5)   &&   ((int)s == -37) &&         //û
           ((int)s == -2)   &&   ((int)s == -34) &&         //þ
           (!fd.eof()) )
                raidziu_k++;

        if (((int)s >= 48) && ((int)s <= 57) && (!fd.eof()))
            skaiciu_k++;

        if (((int)s == 32) && (!fd.eof()))
            tarpu_k++;

        if (!fd.eof()) k++;
    }

    kitu_k = k - raidziu_k - skaiciu_k - tarpu_k;

    cout << raidziu_k << endl;
    cout << skaiciu_k << endl;
    cout << tarpu_k << endl;
    cout << kitu_k << endl;

    return 0;
}
