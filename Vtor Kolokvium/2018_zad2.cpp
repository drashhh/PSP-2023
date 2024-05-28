#include <iostream>
using namespace std;
class Elementi{
    private:
        string ImeK;
        char Mat;
        float cena;
        int meseci;
    public:
        Elementi(string ik = "", char m = ' ', int me = 0){
            ImeK = ik;
            Mat = m;
            meseci = me;
        }
        virtual int PresmetajCena(){
            if(Mat == 'm')
                cena = 4000;
            else if(Mat == 'i')
                cena = 2000;
            else
                cena = 0;

            return cena;
        }
        virtual void pecati() = 0;
        virtual ~Elementi(){

        };
};
class Masi : public Elementi{
    private:
        int povrsina;
        int fioki;
        int* zafatnina;
    public: 
    Masi(string ik = "", char m = ' ', int me = 0, int p = 0, int f = 0, int *zaf = {}) : Elementi(ik,m,me){
        povrsina = p;
        fioki = f;
        zafatnina = new int[fioki+1];
        for(int i = 0; i < fioki; i++){
            zafatnina[i] = zaf[i];
        }
    }
    int PresmetajCena(){
        int vkupnaZaf =0;
        for(int i = 0; i < fioki; i++){
            vkupnaZaf += zafatnina[i];
        }
        return Elementi::PresmetajCena() * (0.25*povrsina + vkupnaZaf*0.20);
    }
    void pecati(){
        cout<<"Masata ima "<<fioki<<" fioki i povrsina od "<<povrsina<<" kvadratni metri"<<endl;
        cout<<"Cenata iznesuva: "<<PresmetajCena()<<endl;
    }
    ~Masi(){
        delete[] zafatnina;
    }
};
class Visecki : public Elementi{
    private:
        int brVrati;
        int brPolici;
    public:
        Visecki(string ik = "", char m = ' ', int me = 0, int brV = 0, int brP = 0) : Elementi(ik,m,me){
            brVrati = brV;
            brPolici = brP;
        }   
        int PresmetajCena(){
            return Elementi::PresmetajCena() + brVrati * 500 + brPolici * 2000;
        }
        void pecati(){
            cout<<"Viseckiot element ima "<<brVrati<<" vrati i "<<brPolici<<" polici."<<endl;
            cout<<"Cenata iznesuva: "<<PresmetajCena()<<endl;
        }
        ~Visecki(){

        }
};
void najmal(Elementi *pok[], int n){
    int najmalIndeks = 0;
    Elementi* najmala = pok[0];
    for(int i = 1; i < n; i++){
        if(najmala->PresmetajCena() > pok[i]->PresmetajCena()){
            najmala = pok[i];
            najmalIndeks = i;
        }
    }
    cout<<"Najmala cena iznesuva > "<<najmala->PresmetajCena()<<" so indeks na pokazuvac "<<najmalIndeks<<endl;
}
int VkupnaCena(Elementi *pok[], int n){
    int vkCena = 0;
    for(int i =0; i < n; i++){
        vkCena+=pok[i]->PresmetajCena();
    }
    return vkCena;
}
int main(){
    Elementi *pok[3];
    int niza[] = {4,4,5,3,4};
    Masi m = Masi("Mebel-Vi", 'i', 5, 5, 5, niza);
    Masi m2 = Masi("Decathlon", 'i', 5, 10, 5, niza);
    Visecki v = Visecki("MEBEL", 'm', 5, 5, 4);

    pok[1] = &m;
    pok[0] = &m2;
    pok[2] = &v;
    m.pecati();
    v.pecati();
    pok[0]->pecati();
    najmal(pok, 3);
    cout<<"Vkupna cena na site elementi > "<<VkupnaCena(pok,3)<<endl;
    return 0;
}