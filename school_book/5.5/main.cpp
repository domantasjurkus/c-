#include <iostream>
#include <fstream>
using namespace std;

void BendrosMinutes(int a1, int a2, int b1, int b2, int &b_m){
    //a1, a2 - atsisedimo ir nuejimo laikas
    //b1, b2 - trikdzio pradzios ir pabaigos laikas
    cout << "a1: " << a1 << endl;
    cout << "a2: " << a2 << endl;
    cout << "b1: " << b1 << endl;
    cout << "b2: " << b2 << endl;
    cout << "----------" << endl;
    if ((a1<=b1)&&(b2<=a2)){
        //|--------|    <- naudojo (a)
        //   |--|       <- trikdis (b)
        b_m += b2-b1;
        cout << "suveike 1" << endl;
    } else if ((b1<a1)&&(b2<=a2)&&(a1<=b2)){   //tikdis prasidejo, atsisedo, trikdis baigesi, nuejo
        //   |-----|    <- naudojo (a)
        //|-----|       <- trikdis (b)
        b_m += b2-a1;
        cout << "suveike 2" << endl;
    } else if ((a1<b1)&&(a2<=b2)&&(b1<=a2)){   //prisedo, trikdis atsirado, nuejo, trikdis praejo
        //|-----|       <- naudojo (a)
        //   |-----|    <- trikdis (b)
        cout << "suveike 3" << endl;
        b_m += a2-b1;
    } else if((b1<a1)&&(a2<b2)){
        //   |--|       <- naudojo (a)
        //|--------|    <- trikdis (b)
        b_m += a2-a1;
        cout << "suveike 4" << endl;
    }
}

int main()
{
    int ah, am, bh, bm, k,
        truk_ah, truk_am, truk_bh, truk_bm,
        bendros_minutes = 0;
    ifstream fd("duom.txt");
    fd >> ah >> am >> bh >> bm >> k;
    if ((ah<0)||(bh>=24)||(am<0)||(bm>=60)||(k<0)||(k>1440)){
        cout << "blogi duomenys";
    } else {
    //Laiko konvertavimas i minutes (24h = 1440 min)
    am += ah*60;
    bm += bh*60;
    for (int i = 0; i < k; i++){
        fd >> truk_ah >> truk_am >> truk_bh >> truk_bm;
        truk_am += truk_ah*60;
        truk_bm += truk_bh*60;
        BendrosMinutes(am, bm, truk_am, truk_bm, bendros_minutes);
    }
    cout << endl << "trikdziai suede " << bendros_minutes << " minutes" << endl;
    cout << "liko " << (bm-am) - bendros_minutes << " minutes" << endl;
    fd.close();
    }
    return 0;
}
