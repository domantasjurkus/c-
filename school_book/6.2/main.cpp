#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int main()
{
    int n,
        bern[100],
        merg[100],
        temp,
        bern_n = 0,
        merg_n = 0,
        bern_sum = 0,
        merg_sum = 0,
        sum = 0,
        bern_kom = 0,
        merg_kom = 0;
    ifstream fd("duom.txt");
    fd >> n;
    if (n>=30) return 0;
    for (int i = 0; i < n; i++){
        fd >> temp;
        if (temp<0){
            bern[i] = -1*temp;
            bern_n++;
            bern_sum += -1*temp;
            sum += -1*temp;
            if (temp <= (-175)) bern_kom++;
        } else{
            merg[i] = temp;
            merg_n++;
            merg_sum += temp;
            sum += temp;
            if (temp >= 175) merg_kom++;
        }
    }
    cout << "Visu mokiniu ugio vidurkis: " << setprecision(4) << (float)sum/n << endl;
    cout << "Merginu vidurkis: " << setprecision(5) << (float)merg_sum/merg_n << endl;
    cout << "Vaikinu viurkis: " << setprecision(5) << (float)bern_sum/bern_n << endl;
    if (bern_kom >= 7) cout << "Berniuku komanda bus, jai tinka " << bern_kom << " berniukai" << endl;
        else cout << "Berniuku komandos nebus, jai tinka tik " << bern_kom << " berniukai" << endl;
    if (merg_kom >= 7) cout << "Mergaiciu komanda bus, jai tinka " << bern_kom << " mergaites" << endl;
        else cout << "Mergaiciu komandos nebus, jai tinka tik " << bern_kom << " mergaites" << endl;
    return 0;
}
