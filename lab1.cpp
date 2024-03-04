#include <iostream>
#include <string>
using namespace std;
typedef struct Apteka{
    string AptLokacija;
    int brVraboteni;
    int prosPromet;
    void init(string lokacija, int brV, int promet);
    void pechati();
}Apteka;
void Apteka::init(string lokacija, int brV, int promet){
    AptLokacija = lokacija;
    brVraboteni = brV;
    prosPromet = promet;     
}
void Apteka::pechati(){
    cout << "Apteka: " << AptLokacija << " Vraboteni: " << brVraboteni << " Promet: " << prosPromet <<endl;
}
typedef struct Lanec{
    string ImeLanec;
    int brApteki;
    Apteka infoApteka[3];
    void init(string ILanec, int brA, Apteka *initApteka);
    void pechati();
    void pechati(int x);
}Lanec;
void Lanec::init(string ILanec, int brA, Apteka *initApteka){
    ImeLanec = ILanec;
    brApteki = brA;
    for(int j =0; j < brApteki; j++){
        infoApteka[j] = initApteka[j];
    }
}
void Lanec::pechati(){
    cout << "Lanec: " << ImeLanec << " Broj Apteki: " << brApteki << endl;
    cout << "------------------------" << endl;
    for(int i =0; i<brApteki; i++){
        infoApteka[i].pechati();
    }
}
void Lanec::pechati(int x){
    cout << "Lanec: " << ImeLanec << " Broj Apteki: " << brApteki << endl;
    cout << "------------------------" << endl;
    for(int i = 0; i<brApteki; i++){
        if(infoApteka[i].prosPromet > x){
            infoApteka[i].pechati();
        }
    }
}
int main(){
    Apteka apteki[3];
    Lanec lanci[2];
    string lokacija,ImeLanec;
    int brojVraboteni, promet, brojApteki, brojLanci;
    int x;

    cout << "Kolku Lanci sakas da vneses?" << endl;
    cin >> brojLanci;
    if(brojLanci > 2){
        cout << "Previse lanci!" <<endl;
        exit(-1);
    }
    
    for(int i=0; i < brojLanci; i++){
        cout << "Pocni so vnesuvanje na " << i+1 << " lanec." <<endl;
        cout << "Ime na lanec: "; cin >> ImeLanec;
        cout << "Broj na apteki: "; cin >> brojApteki;
        for(int j =0; j < brojApteki; j++){
            cout << "Pocni so vnesuvanje na " << j+1 << " apteka." <<endl;
            cout << "Lokacija: "; cin >> lokacija;
            cout << "Broj na vravoteni: "; cin >> brojVraboteni;
            cout << "Promet na apteka: "; cin >> promet;
            apteki[j].init(lokacija, brojVraboteni, promet);
        }
        lanci[i].init(ImeLanec,brojApteki,apteki);
    }

    cout << "Vnesi vrednost x "; cin >> x;
    cout << "------------------------" << endl;
    cout << "Pecatenje na site lanci." << endl;
    for(int i = 0; i < brojLanci; i++){
        lanci[i].pechati();
    }

    cout << "------------------------" << endl << endl;
    cout << "Pecatenje na apteki koi imaat povekje od " << x << " promet" << endl;
    for(int i = 0; i < brojLanci; i++){
        lanci[i].pechati(x);
    }
    cout << "------------------------" << endl;
    return 0;
}