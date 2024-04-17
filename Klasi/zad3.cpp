#include <iostream>
using namespace std;
class ProdavnicaZaKnigi{
    private:
        string ime;
        string adresa;
        int godina;
        int brNaslovi;
        int brNerabotni;
        float procent;
    public:
        ProdavnicaZaKnigi(string i = "", string a = "", int g = 0, int brN = 0, int brNerab = 0, float p = 0.0){
            ime = i; adresa = a; godina = g; brNaslovi = brN; brNerabotni = brNerab; procent = p;
        }
        ProdavnicaZaKnigi(const ProdavnicaZaKnigi &P){
            ime = P.ime; adresa = P.adresa; godina = P.godina; brNaslovi = P.brNaslovi; brNerabotni = P.brNerabotni; procent = P.procent;
        }
        float getProcent(){
            int kolku = 0;
            int rest = 0;
            if(brNerabotni >= 30){
                kolku = brNerabotni / 31;
                rest = brNerabotni % 31;
            }else{
                rest = 365-brNerabotni;
            }

            return (12-kolku)*procent/12 + rest/365;
        }
};
class LanecProdavniciKnigi{
    private:
        string ime;
        string zemja;
        ProdavnicaZaKnigi prodavnici[20];
        int brProdavnici;
        float popust;
    public:
        LanecProdavniciKnigi(string i = "", string z = "", ProdavnicaZaKnigi prod[] = {}, int brP = 0, float p = 0.0){
            ime = i;
            zemja = z;
            for(int i = 0; i < brP; i++){
                prodavnici[i] = prod[i];
            }   
            brProdavnici = brP;
            popust = p;
        }
        LanecProdavniciKnigi(const LanecProdavniciKnigi &L){
            ime = L.ime; zemja = L.zemja; brProdavnici = L.brProdavnici; popust = L.popust;
            for(int )
        }
};