#include <iostream>
#include <iomanip>
using namespace std;
struct Sostojki{
    string ime;
    int masa;
};
class Kozmetika{
    private:
        string ime;
        int cena;
        int brSos;
        Sostojki* sostojki;
    public:
        Kozmetika(string i = "", int c = 0, int brS = 0, Sostojki *s = {}){
            ime = i;
            cena = c;
            brSos = brS;
            sostojki = new Sostojki[brSos+1];
            for(int i = 0; i < brSos; i++){
                sostojki[i].ime = s[i].ime;
                sostojki[i].masa = s[i].masa;
            }
        }
        void pecati(){
            cout<<"Ime na proizvod > "<<ime<<endl;
            cout<<"Cena na proizvodot > "<<cena<<endl;
            cout<<"Broj na sostojki > "<<brSos<<endl;
            cout<<"Sostojki > "<<endl;
            cout<<"\tIme\tGramaza"<<endl;
            for(int i =0; i<brSos; i++){
                cout<<"\t"<<sostojki[i].ime<<"\t"<<sostojki[i].masa<<" grama."<<endl;
            }
        }
        Kozmetika& operator+=(Sostojki s){
            Sostojki* temp;
            temp = new Sostojki[brSos+1];
            for(int i = 0; i < brSos; i++){
                temp[i] = sostojki[i];
            }
            temp[brSos].ime = s.ime;
            temp[brSos].masa = s.masa;
            brSos++;
            delete[] sostojki;
            sostojki = temp;
            delete[] temp;
            return *this;
        }
        Kozmetika& operator-=(Sostojki s){
            Sostojki* temp;
            temp = new Sostojki[brSos+2];
            temp[0].ime = s.ime;
            temp[0].masa = s.masa;
            for(int i = 1; i < brSos+1; i++){
                temp[i] = sostojki[i-1];
            }
            brSos++;
            delete[] sostojki;
            sostojki = temp;
            delete[] temp;
            return *this;
        }
        Kozmetika& operator++(){
            Sostojki* temp = new Sostojki[brSos];
            for(int i = 0; i < brSos-1; i++){
                temp[i] = sostojki[i];
            }
            brSos--;
            delete[] sostojki;
            sostojki = temp;
            delete[] temp;
            return *this;
        }
        Kozmetika& operator--(){
            Sostojki* temp = new Sostojki[brSos];
            for(int i = 1; i < brSos; i++){
                temp[i-1] = sostojki[i];
            }
            brSos--;
            delete[] sostojki;
            sostojki = temp;
            delete[] temp;
            return *this;
        }
        friend ostream& operator<<(ostream& out, const Kozmetika& k){
            cout<<"Ime na proizvod > "<<k.ime<<endl;
            cout<<"Cena na proizvodot > "<<k.cena<<endl;
            cout<<"Broj na sostojki > "<<k.brSos<<endl;
            cout<<"Sostojki > "<<endl;
            cout<<"\tIme\tGramaza"<<endl;
            for(int i =0; i<k.brSos; i++){
                cout<<"\t"<<k.sostojki[i].ime<<"\t"<<k.sostojki[i].masa<<" grama."<<endl;
            }
            return out;
        }
        ~Kozmetika(){
            delete[] sostojki;
        }
};
int main(){
    string ime = "MaskaZaLice";
    int cena = 500;
    int sos = 2;
    Sostojki niza[] = {{"Krem", 50}, {"Zinc", 2}};
    Kozmetika k = Kozmetika(ime, cena, sos, niza);
  //  k.pecati();
  //  cout<<endl;
    Sostojki p = {"Hlor", 2};
    k+=p;
  //  k.pecati();
    Sostojki g = {"Red40", 1};
    k-=g;
   // k.pecati();
    ++k;
   // k.pecati();
    --k;
   // k.pecati();
   cout<<k<<endl;
    return 0;
}