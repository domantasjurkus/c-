#include <iostream>
#include <fstream>
using namespace std;
const char duom[] = "duom.txt";
const char rez[] = "rez.txt";
//-----
void skaityti(const char name[], float A[], int &n);
void spausdinti(const char name[], float A[], int a, int b);
//-----
int main()
{
	float mas[50],  //pagrindinis masyvas
      	maxas = 0;  //didziausios poros mases suma
	int n,          //saulegrazu skaicius
    	max_ind1,   //didziausio nario indeksas masyve
    	max_ind2;   //didziausio nario indeksas masyve

	skaityti(duom, mas, n);     //duomenu skaitymas
	if((n<0)||(n>1000))         //patikrinimas
        cout << "blogi duomenys";
    else {

	for (int i = 0; i < n-1; i++){      //nuo 0 iki n-1, kadangi tikriname po du narius
    	if (mas[i]+mas[i+1] > maxas){   //jeigu dvieju gretimu mase didesne uz maxa...
        	maxas = mas[i]+mas[i+1];    //tai ir bus naujas maxas
        	max_ind1 = i;               //issaugom pirmo indeksa
        	max_ind2 = i+1;             //issaugom antro indeksa
    	}
	}
	spausdinti(rez, mas, max_ind1, max_ind2);

	} return 0;
}

void skaityti(const char name[], float A[], int &n){
	ifstream fd(name);
	fd >> n;
	for (int i = 0; i < n; i++){
    	fd >> A[i];
	}
	fd.close();
}

void spausdinti(const char name[], float A[], int a, int b){
    ofstream fr(name);
    fr << a+1 << " " << A[a] << endl;       //++, kadangi masyvas prasideda nuo 0
    fr << b+1 << " " << A[b] << endl;       //o naturalus skaiciai - nuo 1
    fr.close();
}
