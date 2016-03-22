#include <iostream>
#include <fstream>
using namespace std;

int IlgiausiaiZydi(int A[], int n)
{
    int Max = A[0];
    for (int i = 1; i < n; i++)
        if (A[i] > Max) Max = A[i];
    return Max;
}

void SIZ(const char fv[], int A[], int n, int sk)
{
    ofstream fr(fv, ios::app);
    fr << "Ilgiausiai zydi nr.:" << endl;
    for (int i = 0; i < n; i++)
        if (A[i] == sk) fr << " " << i+1;
    fr << endl;
    fr.close();
}

int main()
{
    int P[50] = {}, n;
    ifstream fd("duom.txt");
    ofstream fr("rez.txt");
    fd >> n;
    fr << "Gele\tLaikas" << endl;
    for (int i = 0; i < n; i++) {
        fd >> P[i];
        fr << i+1 << "\t" << P[i] << endl;
    }
    fd.close();

    int Max;
    Max = IlgiausiaiZydi(P, n);
    fr << "Visos geles nuvys po " << Max << " dienu." << endl;

    SIZ("rez.txt", P, n, Max);

    return 0;
}
