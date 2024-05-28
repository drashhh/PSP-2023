#include <iostream>
using namespace std;
struct Inventar{
    char tip;
    int InvenID;
};
class Kancelarija{
        int KancID;
        int brInventar;
        Inventar *niza;
    public:
        Kancelarija(int KID = 0, int brI = 0, Inventar n[] = NULL){
            KancID = KID;
            brInventar = brI;
            niza = new Inventar[brI+1];
            for(int i = 0; i < brInventar; i++){
                niza[i] = n[i];
            }
        }
        virtual int CenaKancelarija(){
            int cena = 0, brStol = 0, brMasa = 0;
            for(int i = 0; i < brInventar; i++){
                if(niza[i].tip == 'm')
                    brMasa++;
                else if(niza[i].tip == 's')
                    brStol++;
            }
            cena = brMasa * 5000 + brStol * 4000;
            return cena;
        }
        Kancelarija& operator=(Kancelarija &k){
            KancID = k.KancID;
            brInventar = k.brInventar;
            
            delete[] niza;
            niza = new Inventar[brInventar];
            for(int i =0; i < brInventar; i++){
                niza[i] = k.niza[i];
            
            }
            return *this;
        }
        Kancelarija& operator+=(Inventar n){
            Inventar *temp;
            temp = new Inventar[brInventar+1];
            temp[0] = n;
            for(int i = 0; i < brInventar;i++){
                temp[i+1] = niza[i];
            }
            delete[] niza;
            niza = temp;

            return *this;
        }
        friend ostream& operator<<(ostream& out, Kancelarija& k){
            out<<"Kancelarija > "<<k.KancID<<endl;
            out<<"Inventar > "<<endl;
            for(int i = 0; i < k.brInventar; i++){
                out<<"ID > "<<k.niza[i].InvenID<<" Tip > "<<k.niza[i].tip<<endl;
            }
            return out;
        }
        virtual ~Kancelarija(){
            delete[] niza;
        }
};
class Asistentska : public Kancelarija{
        int brTetratki;
    public:
        Asistentska(int KID = 0, int brI = 0, Inventar n[] = NULL, int brT = 0) : Kancelarija(KID, brI, n){
            brTetratki = brT;
        }
        int CenaKancelarija(){
            int cena = Kancelarija::CenaKancelarija();
            cena += (brTetratki * 20);
            return cena;
        }
        Asistentska& operator=(const Asistentska& A){
            this->operator=(A);
            brTetratki = A.brTetratki;
            return *this;
        }
        friend ostream& operator<<(ostream& out, Asistentska&A){
            out<<"Asistenskata Kancelarija ima > "<<A.brTetratki<<" tetratki."<<endl;
            return out;
        }
        ~Asistentska(){

        }
};
class Profesorska : public Kancelarija{
        bool Proektor;
    public:
        Profesorska(int KID = 0, int brI = 0, Inventar n[] = NULL, bool P = false) : Kancelarija(KID, brI, n){
            Proektor = P;
        }
        int CenaKancelarija(){
            int cena = Kancelarija::CenaKancelarija();
            if(Proektor)
                cena+=18000;
            return cena;
        }
        Profesorska& operator=(const Profesorska& P){
            this->operator=(P);
            Proektor = P.Proektor;
            return *this;
        }
        ~Profesorska(){

        }
};
int najneopremena(Kancelarija *pok[], int n){
    Kancelarija* temp = pok[0];
    int najne = 0;
    for(int i = 0; i < n; i++){
        if(temp->CenaKancelarija() > pok[i]->CenaKancelarija()){
            temp = pok[i];
            najne = i;
        }
    }
    return najne;
}
int main(){
    Inventar niza[] = {{'m', 1}, {'s', 2}, {'m', 3}, {'s', 4}, {'s', 5}};
    Kancelarija *pok[5];
    Profesorska p = Profesorska(211, 5, niza, false);
    Profesorska p2 = Profesorska(221, 5, niza, true);
    Asistentska a = Asistentska(311, 5, niza, 15);
    Asistentska a2 = Asistentska(102, 5, niza, 100);
    Asistentska a3 = Asistentska(105, 5, niza, 50);
    cout<<p.CenaKancelarija()<<" "<<p2.CenaKancelarija()<<" "<<a.CenaKancelarija();
    cout<<" "<<a2.CenaKancelarija()<<" "<<a3.CenaKancelarija()<<endl;
    pok[0] = &p; pok[1] = &p2; pok[2] = &a; pok[3] = &a2; pok[4] = &a3;
    cout<<pok[0]->CenaKancelarija()<<endl;
    cout<<najneopremena(pok, 5)<<endl;

    return 0;
}