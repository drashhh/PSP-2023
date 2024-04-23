#include <iostream>
#include <cstring>
using namespace std;
class Ucenik{
    private:
        float prosek;
        int godina;
        char *ime;
    public:
        Ucenik(){
            prosek = 0.0;
            godina = 0;
            ime = new char[1];
            strcpy(ime, "");
        }
        Ucenik(char *i, float p, int g){
            ime = new char[strlen(i) + 1];
            strcpy(ime, i);
            prosek = p;
            godina = g;
        }
        Ucenik(const Ucenik& u){
            ime = new char[strlen(u.ime) + 1];
            strcpy(ime , u.ime);
            prosek = u.prosek;
            godina = u.godina;
        }
        ~Ucenik(){
            delete[] ime;
        }
        char* getIme(){
            return ime;
        }
        float getProsek(){
            return prosek;
        }
        int getGodina(){
            return godina;
        }
        void setIme(char *i){
            delete[] ime;
            ime = new char[strlen(i) + 1];
            strcpy(ime, i);
        }
        void setProsek(float p){
            prosek = p;
        }
        void setGodina(int g){
            godina = g;
        }
        Ucenik &operator++(){
            godina++;
            return *this;
        }
        Ucenik &operator=(Ucenik &U){
            setIme(U.ime);
            prosek = U.prosek;
            godina = U.godina;
            return *this;
        }
        friend ostream& operator<<(ostream &out, Ucenik &U){
            out<<"Ime na student > \t"<<U.ime<<endl<<"Prosek > \t"<<U.prosek<<endl<<"Godina > \t"<<U.godina<<endl;
            return out;
        }
};
class Paralelka{
    private:
        Ucenik *klas;
        int broj;
    public:
        Paralelka(Ucenik *U = NULL, int br = 0){
            broj = br;
            klas = new Ucenik[broj];
            for(int i = 0; i < broj; i++){
                klas[i] = U[i];
            }
        }
        Paralelka(const Paralelka &p){
            broj = p.broj;
            klas = new Ucenik[broj];
            for(int i = 0; i < broj; i++){
                klas[i] = p.klas[i];
            }
        }
        ~Paralelka(){
            delete[] klas;
        }
        Paralelka &operator++(){
            for(int i = 0; i < broj; i++){
                ++klas[i];
               
            }
             return *this;
        }
        Paralelka &operator+=(Ucenik &U){
            Ucenik *pom;
            pom = new Ucenik[broj + 1];
            broj+=1;
            for(int i = 0; i < broj - 1; i++){
                pom[i] = klas[i];
            }
            pom[broj-1] = U;
            delete[] klas;
            klas = pom;
            return *this;
        }
        friend ostream &operator<<(ostream &out, Paralelka &p){
            out<<"Klasot ima > "<<p.broj<<" ucenici."<<endl;
            for(int i = 0; i < p.broj; i++){
                out<<p.klas[i];
            }
            return out;
        }

};
int main(){
    Ucenik u[4] = {Ucenik(), Ucenik("Prv", 5.0, 2012), Ucenik("Vtor", 4.5, 2013), Ucenik("Tret", 3.0, 2012)};
    cout<<u[1];
    u[1] = u[2];
    cout<<u[1];
    Paralelka p = Paralelka(u, 4);
    cout<<p;
    Ucenik nov = Ucenik("Nov", 5.0, 2015);
    p+=nov;
    cout<<p;
    ++p;
    cout<<p;

    return 0;
}