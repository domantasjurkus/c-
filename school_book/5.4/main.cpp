#include <iostream>
#include <fstream>
using namespace std;
const char duom[] = "duom.txt";
const char rez[] = "rez.txt";

int Trup(int s1, int v1, int s2, int v2){
    ofstream fr(rez, ios::app);
    fr << s1 << "/" << v1 << "\t" << s2 << "/" << v2 << "\t";
    //bendras vardiklis
    int bendr_v;
    if (v1 != v2) bendr_v = v1*v2;
    else bendr_v = v1;
    //-----suma
    fr << s1*v2 + s2*v1 << "/" << bendr_v << "\t";
    //-----skirtumas
    fr << s1*v2 - s2*v1 << "/" << bendr_v << "\t";
    //-----sandauga
    int s_temp, v_temp;
    if ((v1%s2)==0){
        v_temp = v1/s2;
        s_temp = 1;
    fr << s1*s_temp << "/" << v2*v_temp << "\t";
    } else if ((v2%s1)==0){
        v_temp = (v2/s1);
        s_temp = 1;
        fr << s2*s_temp << "/" << v1*v_temp << "\t";
    } else fr << s1*s2 << "/" << v1*v2 << "\t";
    //-----dalmuo - tiesiog apverciam
    int temp;
    temp = s2;
    s2 = v2;
    v2 = temp;
    //-----o po to kaip sandauga
    if ((v1%s2)==0){
        v_temp = v1/s2;
        s_temp = 1;
    fr << s1*s_temp << "/" << v2*v_temp << endl;
    } else if ((v2%s1)==0){
        v_temp = (v2/s1);
        s_temp = 1;
        fr << s2*s_temp << "/" << v1*v_temp << endl;
    } else fr << s1*s2 << "/" << v1*v2 << endl;
    fr.close();
    return 0;
}

int main(){
    int n, s1, v1, s2, v2;
    ifstream fd(duom);
    fd >> n;
    ofstream fr(rez); fr.close();   //istrinti anksciau buvusius duomenis
    for (int i = 0; i < n; i++){
        fd >> s1 >> v1 >> s2 >> v2;
        Trup(s1, v1, s2, v2);
    }
    return 0;
}
