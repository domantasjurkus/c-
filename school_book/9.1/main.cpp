#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
//----------
const char duom[] = "duom.txt";
const char rez[] = "rez.txt";
const int Cmax = 50;
//----------
void skaityti(const char name[], int A[], int B[], int &n);
void spausdinti(const char name[], int A[], int B[], int n);
//----------
int main()
{
	int p[Cmax],
        l[Cmax],
        n;
	ofstream fr;
	skaityti(duom, p,l, n);
	spausdinti(rez, p,l, n);
	fr.close();

	return 0;
}
void skaityti(const char name[], int A[], int B[], int &n)
{
	int p = 0;
	int k = 0;  //B masyvo nariø kiekis
	ifstream fd(name);
	fd >> p >> n;
	for (int i = 0; i < n; i++)
    {
        fd >> A[i];
        for (int j = 0; j < A[i]; j++)
        {
            fd >> B[k];
            k++;
        }
    }
	fd.close();
}

void spausdinti(const char name[], int A[], int B[], int n)
{
    int k = 0;
	ofstream fr(name);
	for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < A[i]; j++)
        {
            fr << B[k] << " ";
          	k++;
        }
        fr << endl;
    }
	fr.close();
}
