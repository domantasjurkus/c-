#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int n,  //gamintoju skaicius
        g;  //konteinerio talpa
    ifstream fd("duom.txt");
    fd >> n >> g;

    int prekes[n];  //kiekvieno gamintojo prekiu skaicius
    int kon[g];     //kiekvieno konteinerio skaicius
    //kon[g] - didziausios talpos konteineris
    //kon[0] - maziausios talpos konteineris
    if ((n<0)||(n>1000)||(g<0)||(g>100)) cout << "blogi duomenys" << endl; else {   //duomenu tikrinimas

    for (int i = 0; i < n; i++){
        fd >> prekes[i];
    }
    fd.close();
    for (int i = 0; i < g; i++) {kon[i] = 0;}   //isvalo masyva

    for (int i = 0; i < n; i++){        //pereina per visus gamintojus
        for (int j = g; j > 0; j--){    //pereina per visus konteinerius

            while (prekes[i] >= j) {    //kol prekiu daugiau negu einamo konteinerio talpa
                prekes[i] -= j;         //idedam kiek telpa
                kon[j-1]++;             //ir pazymim, kad viena pilna (puspilni) jau turim
            };
        }
    }

    int suma = 0;
    for (int i = 0; i < g; i++) suma += kon[i];
    cout << suma << endl;
    for (int i = g-1; i >= 0; i--) cout << kon[i] << endl;

    } return 0;     // } - duomeny tikrinimo "else" skliaustas
}
