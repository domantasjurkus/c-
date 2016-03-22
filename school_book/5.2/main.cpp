#include <iostream>
#include <fstream>
using namespace std;
const char duom[] = "duom.txt";
const char rez[] = "rez.txt";

void Skaiciavimas(int &l, int &litr_5, int &litr_2){
    litr_5 = 0;
    litr_2 = 0;
    while(l >= 5) {
        l -= 5;
        litr_5++;
    }
    while(l >= 2) {
        l -= 2;
        litr_2++;
    }
    cout << "5-litriai: " << litr_5 << endl;
    cout << "2-litriai: " << litr_2 << endl;
    cout << "1-litriai: " << l << endl;
    cout << "-----" << endl;
}

int main()
{
    int n, l,
        litr_5 = 0,
        litr_2 = 0;
    ifstream fd(duom);
    fd >> n;
    ofstream fr(rez);
    for (int i = 0; i < n; i++){
        fd >> l;
        Skaiciavimas(l, litr_5, litr_2);
        fr << litr_5 << " ";
        fr << litr_2 << " ";
        fr << l << endl;
    }
    fd.close();
    fr.close();
    return 0;
}
