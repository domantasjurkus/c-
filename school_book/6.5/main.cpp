#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int n;
    ifstream fd("duom.txt");
    fd >> n;
    if ((n<3)||(n>10)) cout << "Blogi duomenys"; else {

    int mas[n];
    cout << "Buvo:" << endl;
    for (int i = 0; i < n; i++){
        fd >> mas[i];
        cout << mas[i] << endl;
    }
    cout << endl;
    int einamas,        //vaiko, kuris gaus akmenuka, ineksas masyve
        dideja;         //jeigu indeksas dideja - 1, jeigu mazeja - 0
    for (int i = 0; i < n-1; i++){
        einamas = i+1;  //nulinis vaikas tik duos, tad pirmas gaus pirmas
        dideja = 1;
        while (mas[i]>0){
            if (einamas == i) break;   //pasiekiamas tik kuomet buvo isdalinta ir i prieki, ir atgal
            --mas[i];                  //atimam is vieno...
            ++mas[einamas];            //duodam kitam - tvarka bus
            if (einamas == (n-1)) {    //jeigu vaikas kuriam norim duot pasieke masyvo gala
                --mas[i];              //dar kart atimam...
                ++mas[einamas];        //ir duodam galiniui
                dideja = 0;            //parodo, kad dabar bus einama nuo galo i prieki
            }
            if (dideja == 1)           //jeigu duodama su akmeniu i prieki
                einamas++;
            else einamas--;            //kitaip - duodam akemniu atgal
        }
    }

    cout << "Yra:" << endl;
    for (int i = 0; i < n; i++){
        cout << mas[i] << endl;
    }
    } return 0;
}
