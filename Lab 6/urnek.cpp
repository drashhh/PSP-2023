#include <iostream>
using namespace std;
class Kosarkar{
    private:
        int plata;
        string ime;
    public:
        Kosarkar(int p = 0, string i = ""){
            plata = p;
            ime = i;
        }
        Kosarkar(const Kosarkar &K){
            plata = K.plata;
            ime = K.ime;
        }
        ~Kosarkar(){
            cout<<"Kosakar "<<ime<<" e unishten."<<endl;
        }
        int getPlata(){
            return plata;
        }
        string getIme(){
            return ime;
        }
        int presmetajPlata(int brKosovi){
            int pokacuvanje = brKosovi * 50;
            plata = plata + pokacuvanje;
            return plata;
        }
};
class Ekipa{
    private:
        string ekipaIme;
        int brKosarkari;
        float prosek;
        Kosarkar kosarkari[8];
    public:

};