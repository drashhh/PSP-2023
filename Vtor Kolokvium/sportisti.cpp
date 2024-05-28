#include <iostream>
using namespace std;
class Sportist{
    private:
        string ime;
        int mesto;
    public:
        Sportist(string i = "", int m = 0){
            ime = i;
            mesto = m;
        }
        Sportist(const Sportist&S){
            ime = S.ime;
            mesto = S.mesto;
        }
        friend bool operator==(Sportist&S, int mes){
            if(S.mesto == mes){
                return true;
            }else   
                return false;
        }
        friend ostream& operator<<(ostream &out, Sportist&S){
            out<<"Sportist > "<<endl;
            out<<"Ime >\t"<<S.ime<<"\tMesto > "<<S.mesto<<endl;
            return out;
        }
        friend istream& operator>>(istream &in, Sportist &S){
            cin>>S.ime>>S.mesto;
            return in;
        }
        virtual int OsnovniPoeni(){
            if(mesto<=30){
                return 31-mesto;
            }else   
                return 0;
        }
        virtual void pecati(){
             cout<<"Sportist > "<<endl;
            cout<<"Ime >\t"<<ime<<"\tMesto > "<<mesto<<endl;
        };
        virtual ~Sportist(){}
};
class Bijatlonec : public Sportist{
    private:
      int vreme;
      int promaseniMeti;
    public:
        Bijatlonec(string i = "", int m = 0, int v = 0, int pM = 0) : Sportist(i,m){
           vreme = v;
           promaseniMeti = pM; 
        }
        int OsnovniPoeni(){
            int poeni = Sportist::OsnovniPoeni();
            if(vreme <= 60){
                poeni+=5;
            }
            if(promaseniMeti > 0){
                poeni-=promaseniMeti;
            }
            return poeni;
        }
        void pecati(){
            Sportist::pecati();
            cout<<"Tip > Bijatlonec"<<endl;
            cout<<"Vreme > "<<vreme<<"min\tPromaseni > "<<promaseniMeti<<endl;
            cout<<"Poeni >\t"<<OsnovniPoeni()<<endl;
        }
        ~Bijatlonec(){}
};
class SkiSkokac : public Sportist{
    private:
        int niza[2];
    public:
        SkiSkokac(string i = "", int m = 0, int n[] = {}) : Sportist(i, m){
            for(int i = 0; i < 2; i++){
                niza[i] = n[i];
            }
        }
        int OsnovniPoeni(){
            bool Skok = false;
            if(niza[0] > 120 && niza[1] > 120)
                Skok = true;
            if(Skok){
                return (Sportist::OsnovniPoeni()*1.2);
            }else
                return (Sportist::OsnovniPoeni()*0.9);
        }
        void pecati(){
            Sportist::pecati();
            cout<<"Tip > SkiSkokac"<<endl;
            cout<<"Skokovi > \t";
            for(int i = 0 ; i < 2; i++){
                cout<<niza[i]<<" ";
            }
            cout<<endl;
            cout<<"Poeni >\t"<<OsnovniPoeni()<<endl;
        }
        ~SkiSkokac(){}
};
void najUspeshen(Sportist *pok[], int n){
    Sportist *najUspeshen = pok[0];
    for(int i =0; i < n ; i ++){
        if(najUspeshen->OsnovniPoeni() < pok[i]->OsnovniPoeni()){
            najUspeshen = pok[i];
        }
    }
    cout<<"Najuspeshen e > "<<endl;
    najUspeshen->pecati();
}
int main(){
    Sportist *pok[3];
    int niza[3] = {123,134};
    Bijatlonec b = Bijatlonec("Drake", 5, 35, 3);
    Bijatlonec b2 = Bijatlonec("KDot", 1, 70, 5);
    SkiSkokac s = SkiSkokac("Metro", 1, niza);
    pok[0] = &b;
    pok[1] = &b2;
    pok[2] = &s;
    najUspeshen(pok, 3);
    cout<<*pok[2]<<endl;
    return 0;
}