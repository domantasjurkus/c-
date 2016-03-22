#include <iostream>
#include <fstream>
using namespace std;
const char duom[] = "duom.txt";
const char rez[] = "rez.txt";

void Tikr(int &I, int &U, int &R){
    if (I==0) I = U/R;
    else if (U==0) U = I*R;
    else R = U/I;
    cout << I << " " << U << " " << R << endl;
}

int main()
{
    int n, I, U, R;
    ifstream fd(duom);
    fd >> n;
    ofstream fr(rez);
    for (int i = 0; i < n; i++){
        fd >> I >> U >> R;
        Tikr(I, U, R);
        fr << I << " " << U << " " << R << endl;
    }
    fd.close();
    fr.close();
    return 0;
}
