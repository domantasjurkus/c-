#include <iostream>
#include <iomanip>
using namespace std;

void Vertimas(int m){
    float col = (float) (m * 39.37);
    cout << col << " ";
    float ped = col/12;
    cout << fixed << setprecision(2) << ped << " ";
    float jar = ped/3;
    cout << jar << endl;
}

int main()
{
    for (int i = 1; i <= 5; i++){
        cout << i << " ";
        Vertimas(i);
    }

    return 0;
}
