#include <iostream>
#include <fstream>
using namespace std;
const char duom[] = "U1.txt";
const char rez[] = "U1rez.txt";
//-----
void Skaityti(int A1[], int &n, int A2[]);
int KiekKomplektu(int A[6]);
void Spausdinti(int komp);
//-----
int main()
{
    int n = 0;                          //mokiniu skaièius
    int F1[6];                          //einamø figûrø masyvas
    int F2[6] = {0, 0, 0, 0, 0, 0};     //visø figurø bendras masyvas
    int komplektai  = 0;                //komplektø skaièius

    //kadangi turime naudoti vienmačius masyvus, iškart, nuskaitę vieno mokinio
    //atneštų figūrų skaičių, jį pridėsime prie bendros sumos, tad skaitymo
    //funkcijoje teks naudoti ir bendrą F2 masyvą
    Skaityti(F1, n, F2);

    //randame komplektø skaièiø
    komplektai = KiekKomplektu(F2);

    //áraðome rezultatà
    Spausdinti(komplektai);

    return 0;
}

void Skaityti(int A1[], int &n, int A2[])
{
    //skaitome ir skaièiuojame kiek figûrø atneðta ið viso
    ifstream fd(duom);
    fd >> n;                            //priskiriame n reikðmæ
    for (int i = 0; i < n; i++)         //einame per visus mokinius
    {
        for (int j = 0; j <= 5; j++)    //einame per visus figûrø tipus
        {
            fd >> A1[j];                //priskiriam vienos ið figûrø tipø skaièiø
            A2[j] += A1[j];             //ir iðkart já pridedam prie bendros sumos
        }
    }
    fd.close();
}

int KiekKomplektu(int A[6])
{
    int komp = 0;

    //sukti ciklà tol, kol dar yra pakankamai:
    //     pëstininkø    bokðtø        þirgø         rikiø         karaliø   ir  karalieniø
    while ((A[0]>=8) && (A[1]>=2) && (A[2]>=2) && (A[3]>=2) && (A[4]>=1) && (A[5]>=1))
        {
            A[0] -= 8;     //atimame visas reikiamas figûras
            A[1] -= 2;
            A[2] -= 2;
            A[3] -= 2;
            A[4] -= 1;
            A[5] -= 1;
            komp++;   //ir paþymime, kad turime pilnà komplektà
        }
    return komp;
}

void Spausdinti(int komp)
{
    ofstream fr(rez);
        fr << komp;
    fr.close();
}
