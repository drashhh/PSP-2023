#include <iostream>
using namespace std;
class Let{
    private:
        int sifraL;
        string gradP;
        string gradS;
        int sifraP;
    public:
        Let(int sL=0, string gradPolet = "", string gradSletu ="", int sP=0){
            sifraL = sL;
            gradP = gradPolet;
            gradS = gradSletu;
            sifraP = sP;
        }
        int getSifraLet(){
            return sifraL;
        }
        string getGradPoletuvanje(){
            return gradP;
        }
        string getGradSletuvanje(){
            return gradS;
        }
        int getSifraPilot(){
            return sifraP;
        }
};
class Pilot{
    private:
        int sifraP, plata;
        string ime;
    public:
        Pilot(int sP = 0, int p = 0, string i = ""){
            sifraP = sP;
            plata = p;
            ime = i;
        }
        int getSifraPilot(){
            return sifraP;
        }
        int getPilotPlata(){
            return plata;
        }
        string getImePilot(){
            return ime;
        }
};
class AvioKompanija{
    private:
        Let letovi[30];
        int brLetovi;
        string ime;
};  
int main(){
    return 0;
}