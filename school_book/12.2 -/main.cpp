#include <iostream>
#include <fstream>
using namespace std;
const char duom[] = "duom.txt";
int main()
{
	char sk[80];	//galutinis skaicius
	char s[80]; 	//skaitomas skaicius
	int n = 0;
	int k = 0;  	//skaitomo skaiciaus skaitmenu suma
	char blah;

	for (int i = 0; i < 80; i++)
    	sk[i] = '-';

	for (int i = 0; i < 80; i++)
    	cout << sk[i];

	ifstream fd(duom);
	fd >> n;

	for (int i = 0; i < n; i++)
	{
    	fd >> k;
    	fd.get(blah);
    	fd.get(s, k+1);
    	for (int j = k-1; j >= 0; j--)
    	{
        	int n = 0;
        	sk[80-n] += s[j];
        	n++;
    	}

	}


	return 0;
}
