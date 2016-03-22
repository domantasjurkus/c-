#include <iostream>
#include <fstream>
using namespace std;
const char duom[] = "duom.txt";
const char rez[] = "rez.txt";
int main()
{
    int h_isv = 0,
        m_isv = 0,
        h_truk = 0,
        m_truk = 0,
        h_atv = 0,
        m_atv = 0;

    ifstream fd(duom);
    fd >> h_isv >> m_isv >> h_truk >> m_truk;
    fd.close();

    h_atv += h_isv + h_truk;
    m_atv += m_isv + m_truk;

    if (m_atv >= 60){
        m_atv -= 60;
        h_atv++;
    }
    while (h_atv >= 24)
        h_atv -= 24;

    ofstream fr(rez);
    cout << h_atv << " " << m_atv;
    fr.close();

    return 0;
}
