#include <iostream>
#include <fstream>
using namespace std;
const char duomenys[] = "duomenys.txt";
const char rezultatas[] = "rezultatas.txt";

///randa skatmenu skaiciu
int Skait(float a) {
	int sk = 1;
	while (a>=10) {
        a = a/10;
        sk++;
	}
	return sk;
}

int main()
{
	int n, s = 0;
	ifstream fd(duomenys);
	fd >> n;
	for (int i = 1; i <= n; i++) {
    	s += Skait(i);
	}
	fd.close();
	ofstream fr(rezultatas);
	fr << s;
	fr.close();
	return 0;
}
