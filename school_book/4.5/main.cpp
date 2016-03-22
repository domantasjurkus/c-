#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
const char duom[] = "duom.txt";

double Ilgis(int x1, int y1, int x2, int y2){
    double d = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    return d;
}

double Plotas(double a, double b, double c){
    double p = (a+b+c)/2;                     //pusperimetris
    double S = sqrt(p*(p-a)*(p-b)*(p-c));     //Herono formule
    return S;
}

int main()
{
    int ax, ay, bx, by, cx, cy, dx, dy;
    ifstream fd(duom);
    fd >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
    fd.close();
    double Sabc = Plotas(Ilgis(ax, ay, bx, by), Ilgis(bx, by, cx, cy), Ilgis(ax, ay, cx, cy));
    double Sabd = Plotas(Ilgis(ax, ay, bx, by), Ilgis(bx, by, dx, dy), Ilgis(ax, ay, dx, dy));
    double Sacd = Plotas(Ilgis(ax, ay, cx, cy), Ilgis(cx, cy, dx, dy), Ilgis(ax, ay, dx, dy));
    double Sbcd = Plotas(Ilgis(bx, by, cx, cy), Ilgis(cx, cy, dx, dy), Ilgis(bx, by, dx, dy));
    if (Sabc == (Sabd+Sacd+Sbcd)) {cout << "Viduje" << endl;}
    else {cout << "Isoreje" << endl;}
    return 0;
}
