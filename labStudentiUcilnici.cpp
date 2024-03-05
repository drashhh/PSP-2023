#include <iostream>
#include <string>
using namespace std;
struct Student{
    string Ime;
    string Prezime;
    int indeks;
    string Predmet;
    void init(string ImeStudent, string PrezimeStudent, int IndeksStudent, string PredmetStudent);
    void pechati();
};
void Student::init(string ImeStudent, string PrezimeStudent, int IndeksStudent, string PredmetStudent){
    Ime = ImeStudent;
    Prezime = PrezimeStudent;
    indeks = IndeksStudent;
    Predmet = PredmetStudent;
}
void Student::pechati(){
    cout<<"Student > "<<Ime<<" "<<Prezime<<" Indeks > "<<indeks<<" Predmet > "<<Predmet<<endl;
}
struct Prostorija{
    string Ime;
    int RabotniMesta;
    Student studenti[10];
    void init(string ImeProstorija, int RabMesta, Student *primer);
    void pechati();
    void pechati(char Bukva);
};
void Prostorija::pechati(){
    cout<<"Prostorija > "<<Ime<<" Ucenici > "<<RabotniMesta<<endl;
    for(int i =0; i < RabotniMesta; i++){
        studenti[i].pechati();
    }
}
void Prostorija::pechati(char Bukva){
    int brojac=0;
    for(int i=0; i < RabotniMesta; i++){
        if(studenti[i].Ime[0] == Bukva){
            brojac++;
        }
    }
    cout<<"Prostorija > "<<Ime<<" Ucenici > "<<brojac<<endl;
    for(int i =0; i < RabotniMesta; i++){
        if(studenti[i].Ime[0] == Bukva){
            studenti[i].pechati();
        }
    }
}
void Prostorija::init(string ImeProstorija, int RabMesta, Student *primer){
    Ime = ImeProstorija;
    RabotniMesta = RabMesta;
    for(int i =0; i < RabotniMesta; i++){
        studenti[i] = primer[i];
    }
}
int main(){
    Prostorija prostorii[5];
    Student studenti[10];
    bool pechatiSostojba;
    char bukva;
    string ImeS, PrezimeS, PredmetS, ImeP;
    int indeksS, RabMestaP, BrP, BrS;

    cout<<"Kolku prostorii ti se potrebni > ";
    cin >> BrP;

    for(int i =0; i < BrP; i++){
        cout <<"Pocni so vnesuvanje na "<<i+1<<" prostorija."<<endl;
        cout <<"Ime > "; cin >> ImeP;
        cout <<"Broj na studenti > "; cin >> RabMestaP;
        cout << " --------------------- " << endl;
        for(int j =0; j < RabMestaP; j++){
            cout<<"Pocni so vnesuvanje na "<< j+1 << " student."<<endl;
            cout<<"Ime Student > "; cin >> ImeS;
            cout<<"Prezime Student > "; cin >> PrezimeS;
            cout<<"Indeks Student > "; cin >> indeksS;
            cout<<"Predmet > "; cin >> PredmetS;
            cout<<"---------------"<<endl;
            studenti[j].init(ImeS, PrezimeS, indeksS, PredmetS);
        }
        prostorii[i].init(ImeP, RabMestaP, studenti);
    }
    cout<<"-----------------"<<endl;
    cout<<"Kakvo pecatenje sakas obicno (1) ili so bukva (2)"<<endl;
    cin >> bukva;
    switch (bukva)
    {
    case '1':
        pechatiSostojba = 0;
        break;
    case '2':
        pechatiSostojba = 1;
        break;
    default:
        cout<<"Si vnesol pogreshna informacija!"<<endl;
        exit(-1);
        break;
    }
    if(pechatiSostojba){
        cout<<"Koja bukva sakas da ja pechatme?"<<endl;
        cin >> bukva;
        for(int i=0; i < BrP; i++){
            prostorii[i].pechati(bukva);
        }
    }else{
        for(int i=0; i<BrP; i++){
            prostorii[i].pechati();
        }
    }
    return 0;
}