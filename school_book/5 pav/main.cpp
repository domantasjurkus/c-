#include <iostream>
#include <fstream>
using namespace std;
const char duom[] = "duom.txt";
const char rez[] = "rez.txt";

void Laikas(int h1, int m1, int h_truk, int m_truk, int &h2, int &m2){
    h2 = h1 + h_truk;
    m2 = m1 + m_truk;
    if (m1 + m_truk >= 60) {
        h2++;
        m2 = m1 + m_truk - 60;
    }
}

int main()
{
    int n,  //autobusu skaicius
        h1, m1,
        h_truk, m_truk,
        h2, m2;
    ifstream fd(duom);
    fd >> n;
    ofstream fr(rez);
    for (int i = 0; i < n; i++) {
        fd >> h1 >> m1 >> h_truk >> m_truk;
        Laikas(h1, m1, h_truk, m_truk, h2, m2);
        fr << h2 << " " << m2 << endl;
    }
    fd.close();
    fr.close();
    return 0;
}
