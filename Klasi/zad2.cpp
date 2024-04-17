#include <iostream>
using namespace std;
class Proizvod{
    private:
        string ime;
        int sifra;
        int zaliha;
        int prodadeno;
    public:
        Proizvod(string i = "", int s = 0, int z = 0, int p = 0){
            ime = i; s = sifra; zaliha = z; prodadeno = p;
        }
        Proizvod(const Proizvod &P){
            ime = P.ime; sifra = P.sifra; zaliha = P.zaliha; prodadeno = P.prodadeno;
        }
        void setIme(string i){
            ime =  i;
        }
        void setSifra(int s){
            sifra = s;
        }
        void setZaliha(int z){
            zaliha = z;
        }
        void setProdadeno(int p){
            prodadeno = p;
        }
        string getIme(){
            return ime;
        }
        int getSifra(){
            return sifra;
        }
        int getZaliha(){
            return zaliha;
        }
        int getProdadeno(){
            return prodadeno;
        }
        void pecati(){
            cout<<"Proizvod > "<<ime<<" Sifra > "<<sifra<<" Zaliha > "<<zaliha<<" Prodadeni > "<<prodadeno<<endl;
        }
};
void Sort(Proizvod proizvodi[], int brProizvodi, bool kriterium, bool nasoka){
    //ako nasoka e 1 opagjacki ako e 0 rastecki redosled
    //ako kriterium e 1 za sortiranje po zaliha ako e 0 po sifra
    if(kriterium){
        if(nasoka){
            sortirajZalihaOpagjacki(proizvodi, brProizvodi);
        }else   
            sortirajZalihaRastecki(proizvodi, brProizvodi);
    }else{
        if(nasoka){
            sortirajSifraOpagjacki(proizvodi, brProizvodi);
        }else{
            sortirajSifraRastecki(proizvodi, brProizvodi);
        }
    }
}
void sortirajZalihaOpagjacki(Proizvod proizvodi[], int brProizvodi){
    Proizvod pom;
    for(int i =0; i < brProizvodi; i++){
        for(int j = i+1; i < brProizvodi; j++){
            if(proizvodi[i].getZaliha() < proizvodi[j].getZaliha()){
                pom = proizvodi[i];
                proizvodi[i] = proizvodi[j];
                proizvodi[j] = pom;
            }
        }
    }
}
void sortirajSifraOpagjacki(Proizvod proizvodi[], int brProizvodi){
    Proizvod pom;
    for(int i =0; i < brProizvodi; i++){
        for(int j = i+1; i < brProizvodi; j++){
            if(proizvodi[i].getSifra() < proizvodi[j].getSifra()){
                pom = proizvodi[i];
                proizvodi[i] = proizvodi[j];
                proizvodi[j] = pom;
            }
        }
    }
}
void sortirajZalihaRastecki(Proizvod proizvodi[], int brProizvodi){
    Proizvod pom;
    for(int i =0; i < brProizvodi; i++){
        for(int j = i+1; i < brProizvodi; j++){
            if(proizvodi[i].getZaliha() > proizvodi[j].getZaliha()){
                pom = proizvodi[i];
                proizvodi[i] = proizvodi[j];
                proizvodi[j] = pom;
            }
        }
    }
}
void sortirajSifraRastecki(Proizvod proizvodi[], int brProizvodi){
    Proizvod pom;
    for(int i =0; i < brProizvodi; i++){
        for(int j = i+1; i < brProizvodi; j++){
            if(proizvodi[i].getSifra() > proizvodi[j].getSifra()){
                pom = proizvodi[i];
                proizvodi[i] = proizvodi[j];
                proizvodi[j] = pom;
            }
        }
    }
}
int main(){

    return 0;
}