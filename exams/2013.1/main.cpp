#include <iostream>
#include <fstream>
#include <cmath>        //reikalingas moduliui rasti
using namespace std;
const char duom[] = "U1.txt";
const char rez[] = "U1rez.txt";
//----------
//kadangi duomenis reikes skaityti cikle, duomenu srauta naudosime kaip funkcijos Skaityti() parametra
void Skaityti(ifstream &fd, char pavadinimas[], int &x, int &y);
int Atstumas(int x, int y);
//Spausdinti viska galesime vienu metu, tad uztenka tik failo pavadinimo
void Spausdinti(const char rez[], int a, int b, char pav[]);
//----------
int main()
{
    int n,              //siuntu skaicius
        m,              //dienos kilometru limitas
        x, y;           //imones koordinates
    char pav[10];       //imones pavadinimas

    //ivedame suntu ir kilometru skaiciu
    ifstream fd(duom);
    fd >> n >> m;

    int aptarnauta = 0;
    int nuvaziuota = 0;

    for (int i = 0; i < n; i++)
    {
        Skaityti(fd, pav, x, y);    //skaito pavadinima ir koordinates
        int km = Atstumas(x, y);    //randa atstuma nuo tiklso iki centro
        //if (m >= km)              //jeigu likes kilometru skaicius dar leidzia nuvykti
        m -= km;                    //is likusiu kilometru atimame einama kelia
        aptarnauta++;               //klientas aptarnautas
        nuvaziuota += km;           //nuvaziuotas keliones kelias pridedamas prie sumos
        if (m < km) break;          //jeigu nebelieka kelio
    }
    fd.close();                     //tik dabar galime uzdaryti, nes funkcijai Skaityti() funkcijai reikejo duomenu srauto fd
    Spausdinti(rez, aptarnauta, nuvaziuota, pav);
    return 0;
}

void Skaityti(ifstream &fd, char pavadinimas[], int &x, int &y)
{
    fd >> pavadinimas;
    fd >> x;
    fd >> y;
}

int Atstumas(int x, int y)
{
    return 2*(abs(x) + abs(y));     //naudojam moduli (abs), nes koordinates gali buti ir neigiamos
}

void Spausdinti(const char rez[], int a, int b, char pav[])
{
    ofstream fr(rez);
    fr << a << " " << b << " " << pav;
    fr.close();
}
