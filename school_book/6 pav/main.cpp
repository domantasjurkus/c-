#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int n, kr[100];
        //Skaityti
    ifstream fd("duom.txt");
    fd >> n;
    for (int i = 0; i < n; i++){
        fd >> kr[i];
    }
        //Spausdinti
    ofstream fr("rez.txt");
    for (int i = 0; i < n; i++){
        cout << i << "\t" << kr[i] << endl;
    }
        //Suma
    int suma = 0;
    for (int i = 0; i < n; i++){
        suma += kr[i];
    }
    cout << "krituliu suma: " << suma << endl;
        //Nelietingos dienos
    int nd = 0;
    for (int i = 0; i < n; i++){
        if (kr[i]==0) nd++;
    }
    cout << "nelietingos dienos: " << nd << endl;
        //Lietungu dienu krituliu vidurkis
    int ld = 0,
        l_suma = 0;
    for (int i = 0; i < n; i++){
        if (kr[i] > 0) {
            l_suma += kr[i];
            ld++;
        }
    }
    cout << "lietingu dienu vidurkis: " << (float) l_suma/ld << endl;
    return 0;
}
