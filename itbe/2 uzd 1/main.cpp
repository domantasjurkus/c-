#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const char duom[] = "U1.txt";
const char rez[] = "U1rez.txt";
//-----
struct Vardai{
    string pav;
    int kiek;
};
//-----
string Bvar[100];       //berniuku vardu masyvas
string Bpav[100];       //berniuku pavardziu masyvas
int Bn = 0;             //berniukø skaièius
Vardai Batr[100];       //atrinku vardø sàraðas
int Batr_ind = 0;       //atrinktø vardø kiekis
//-----
string Mvar[100];       //analogiskai
string Mpav[100];
int Mn = 0;
Vardai Matr[100];
int Matr_ind = 0;
//-----
int n;                  //gimimø skaièius
int m_duom[100];        //kiekvieno naujagimio menuo
int m_atr[11];          //kiekvieno menesio naujagimiu skaicius
//-----
void Skaityti();
void Atrinkti(string Var[], int n, Vardai V[], int &Vind);
int RastiInd(Vardai V[], int n, string pav);
void Rikiuoti(Vardai V[], int n);
void SkaiciuotiMenesus(int m_duom[], int n, int m_atr[]);
void Spausdinti(string eil, int num, string var);
void SpausdintiMenesius(int m_atr[]);
//-----
int main()
{
    Skaityti();
    Atrinkti(Bvar, Bn, Batr, Batr_ind);
    Atrinkti(Mvar, Mn, Matr, Matr_ind);
    Rikiuoti(Batr, Batr_ind);
    Rikiuoti(Matr, Matr_ind);

    ofstream fr(rez); fr.close();
    Spausdinti("Berniukai:", Bn, Batr[0].pav);
    Spausdinti("Mergaites:", Mn, Matr[0].pav);

    SkaiciuotiMenesus(m_duom, n, m_atr);
    SpausdintiMenesius(m_atr);

    return(0);
}

void Skaityti()
{
    char var[13];           //laikini kintamieji
    char pav[13];
    char lytis;
    int metai;
    int menuo;
    int diena;

    ifstream fd(duom);
    fd >> n;
    fd.ignore(80, '\n');

    for (int i = 0; i < n; i++)
    {
        fd.get(pav, 13);
        fd.get(var, 13);
        fd >> lytis;
        fd >> metai >> menuo >> diena;
        fd.ignore(80, '\n');

        if (lytis == 'v')           //jeigu iðtraukëme berniukà
        {
            Bvar[Bn] = var;
            Bpav[Bn] = pav;
            Bn++;
        }
        else                        //jeigu iðtraukëme mergaitæ
        {
            Mvar[Mn] = var;
            Mpav[Mn] = pav;
            Mn++;
        }
        m_duom[i] = menuo;
    }
    fd.close();
}

void Atrinkti(string Var[], int n, Vardai V[], int &Vind)
{
    Vind = 0;                       //atrinktame sàraðe ið pradþiø nëra nariø

    for (int i = 0; i < n; i++)     //einame per visus berniukø vardus
    {
        //ar Bv sàraðe yra einamo þmogaus vardas?
        int ind = RastiInd(V, Vind, Var[i]);

        if (ind == -1)              //jeigu vardo dar nëra
        {
            V[Vind].pav = Var[i];
            V[Vind].kiek = 1;
            Vind++;
        }
        else                        //jeigu vardas jau yra
        {
            V[ind].kiek++;
        }
    }
}

int RastiInd(Vardai V[], int n, string pav)
{
    for (int i = 0; i < n; i++)
        if (V[i].pav == pav)
            return i;
    return -1;
}

void Rikiuoti(Vardai V[], int n)
{
    //bandome į 0 indeksą nukelti daugiausiai pasikartojantį vardą, kuris bus pirmasis pagal acėbėlę.
    Vardai temp;

    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
        {
            //jeigu rastas vardas su daugiau pasikartojimų
            if (V[j].kiek > V[i].kiek)
            {
                temp = V[i];
                V[i] = V[j];
                V[j] = temp;
            }
             //jeigu rastas toks pats kiekis, bet vardas pirmesnins pagal abėcėlę
            else if ((V[j].kiek == V[i].kiek)&&(V[j].pav < V[i].pav))
            {
                temp = V[i];
                V[i] = V[j];
                V[j] = temp;
            }
        }
}

void Spausdinti(string eil, int num, string var)
{
    ofstream fr(rez, ios::app);

    fr << eil << " " << num << endl;

    if (num == 0)
        fr << "Vardo nėra" << endl;
    else
        fr << var << endl;

    fr.close();
}

void SkaiciuotiMenesus(int m_duom[], int n, int m_atr[])
{
    for (int i = 0; i < 12; i++)
        m_atr[i] = 0;                       //iš pradžių išvalome pradinį mėnesių kiekį

    for (int i = 0; i < 12; i++)            //einame per sausį, vasarį, kovą,...
        for (int j = 0; j < n; j++)         //einame per duomenų masyvą
            if (i+1 == m_duom[j])
                m_atr[i]++;
}

void SpausdintiMenesius(int m_atr[])
{
    ofstream fr(rez, ios::app);

    for (int i = 0; i < 12; i++)
        fr << m_atr[i] << " ";

    fr.close();
}
