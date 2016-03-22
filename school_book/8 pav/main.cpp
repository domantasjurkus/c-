#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
const char duom[] = "duom.txt";
const char rez[] = "rez.txt";
const int cmax = 24;
//-----
void skaityti(const char name[], int A[], float B[], int &n, float &suma);
void spausdinti(const char name[], int A[], float B[], int n);
int maxTemp(float B[], int n);
void printNearHigh(const char name[], int A[], float B[], int n, double Max);
//-----
int main()
{
    int V[cmax];            //valanda
    float T[cmax];          //temperatura
    int n;                  //matavimu skaicius
    int max_ind;            //didziausios temperaturos indeksas
    float suma = 0;         //temperaturu suma

    skaityti(duom, V, T, n, suma);
    spausdinti(rez, V, T, n);

    ofstream fr(rez, ios::app);
    max_ind = maxTemp(T, n);
    fr << V[max_ind] << " valanda buvo " << T[max_ind] << " temperatura." << endl << endl;
    fr << "Vidutine temperatura: " << suma/n << endl;
    fr.close();
    printNearHigh(rez, V, T, n, T[max_ind]);
    return 0;
}

void skaityti(const char name[], int A[], float B[], int &n, float &suma)
{
    ifstream fd(name);
    fd >> n;
    for (int i = 0; i < n; i++){
        fd >> A[i] >> B[i];
        suma += B[i];
    }
    fd.close();
}

void spausdinti(const char name[], int A[], float B[], int n)
{
    ofstream fr(name);
    fr << "Valanda\tTemperatura" << endl;
    fr << "-------------------" << endl;
    for (int i = 0; i < n; i++){
        fr << setw(4) << A[i] << "\t" << setw(7) << B[i] << endl;
    }
    fr << "-------------------" << endl;
    fr.close();
}

int maxTemp(float B[], int n)
{
    float max_verte = B[0];
    int max_ind = 0;
    for (int i = 0; i < n; i++){
        if (B[i] > max_verte){
            max_verte = B[i];
            max_ind = i;
        }
    }
    return max_ind;
}

void printNearHigh(const char name[], int A[], float B[], int n, double Max)
{
    ofstream fr(name, ios::app);
    int nearMaxCout = 0;    //kiek kartu temperatura buvo artima aukstai
    fr << "Taip pat auksta temperatura buvo:" << endl;
    for (int i = 0; i < n; i++){
        if (Max - B[i] <= 0.5){
            fr << A[i] << " val. " << B[i] << endl;
            nearMaxCout++;
        }
    }
    fr << "Is viso artima aukstai buvo " << nearMaxCout << " kartu." << endl;
    fr.close();
}
