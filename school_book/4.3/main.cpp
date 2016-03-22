#include <iostream>
#include <fstream>
using namespace std;
int BendriX(int x1min, int x1max, int x2min, int x2max, int &bxmin, int &bxmax)
{
    //x1min, x1max - atsisedimo ir nuejimo laikas
    //x2min, x2max - trikdzio pradzios ir pabaigos laikas
    if ((x1min<=x2min)&&(x2max<=x1max)){
        //|--------|    <- naudojo (a)
        //   |--|       <- trikdis (b)
        cout << "suveike 1" << endl;
        bxmin = x2min;
        bxmax = x2max;
        return (x2max-x2min);
    } else if ((x2min<x1min)&&(x2max<=x1max)&&(x1min<=x2max)){   //tikdis prasidejo, atsisedo, trikdis baigesi, nuejo
        //   |-----|    <- naudojo (a)
        //|-----|       <- trikdis (b)
        cout << "suveike 2" << endl;
        bxmin = x1min;
        bxmax = x2max;
        return (x2max-x1min);
    } else if ((x1min<x2min)&&(x1max<=x2max)&&(x2min<=x1max)){   //prisedo, trikdis atsirado, nuejo, trikdis praejo
        //|-----|       <- naudojo (a)
        //   |-----|    <- trikdis (b)
        cout << "suveike 3" << endl;
        bxmin = x2min;
        bxmax = x1max;
        return (x1max-x2min);
    } else if((x2min<x1min)&&(x1max<x2max)){
        //   |--|       <- naudojo (a)
        //|--------|    <- trikdis (b)
        cout << "suveike 4" << endl;
        bxmin = x1min;
        bxmax = x1max;
        return (x1max-x1min);
    }
    return 0;
}

int main()
{
    int x1min, x1max, y1min, y1max,  ///pirmo draugo koordinates
        x2min, x2max, y2min, y2max,  ///antro draugo koordinates
        x3min, x3max, y3min, y3max,  ///trecio draugo koordinates
        bxmin, bxmax,
        bymin, bymax,
        bendri_x, bendri_y;

    ifstream fd("duom.txt");
    fd >> x1min >> y1min >> x1max >> y1max
       >> x2min >> y2min >> x2max >> y2max
       >> x3min >> y3min >> x3max >> y3max;
    fd.close();

    bendri_x = BendriX(x1min, x1max, x2min, x2max, bxmin, bxmax);      ///randa bendrus x tarp pirmu dvieju draugu
    cout << bendri_x << endl;                                          ///bxmin ir bxmax sujungia 1-ojo ir 2-ojo draugo x ribas
    bendri_x = BendriX(bxmin, bxmax, x3min, x3max, bxmin, bxmax);      ///tada tas ribas laikome vienu draugu ir patikrinam su treciuoju
    cout << bendri_x << endl;                                          ///jau galutinia tryju draugu x'ai

    bendri_y = BendriX(y1min, y1max, y2min, y2max, bymin, bymax);      ///ta pati padarom su y koordinatem
    cout << bendri_y << endl;                                          ///taip, funkcijoje visur naudojau X...
    bendri_y = BendriX(bymin, bymax, y3min, y3max, bymin, bymax);      ///bet ar verta perrasinet, kai viskas veikia?
    cout << bendri_y << endl;

    cout << endl;
    cout << "Plotas: " << bendri_x << " * " << bendri_y << " = " << bendri_x*bendri_y;
    cout << endl;

    return 0;
}
