#include <iostream>
#define MAX 50
using namespace std;
struct Covek{
    string ime, prezime;
    bool lk, p, vd; //za deka ceka
};
struct Element{
    Covek podatok;
};
struct Red{
    Element niza[MAX];
    int napred, nazad;
    void init();
    bool isEmpty();
    bool isFull();
    void stavi(Element e);
    Element izvadi();
    Element peek();
};
void Red::init(){
    napred = 0;
    nazad = -1;
}
bool Red::isEmpty(){
    return (nazad == -1);
}
bool Red::isFull(){
    return (nazad == MAX-1);
}
void Red::stavi(Element e){
    if(isFull()){
        cout<<"Redot e poln"<<endl;
        exit(-1);
    }
    niza[++nazad] = e;
}
Element Red::izvadi(){
    if(isEmpty()){
        cout<<"Redot e prazen!"<<endl;
        exit(-1);
    }
    Element pom = niza[napred];
    for(int i = napred; i < nazad; i++){
        niza[i] = niza[i+1];
    }

    nazad++;
    return pom;
}
Element Red::peek(){
    if(isEmpty()){
        cout<<"Redot e prazen!"<<endl;
        exit(-1);
    }
    return niza[napred];
}
void opsluzuvanje(Red &licna, Red &pasos, Red &vozacka){
    Element e;
    while(!licna.isEmpty()){
        e = licna.izvadi();
        e.podatok.lk = 0;
        cout<<"Za licna karta e opsluzen "<<e.podatok.ime<<endl;
        if(e.podatok.p == 1){
            pasos.stavi(e);
        }else if(e.podatok.vd == 1){
            vozacka.stavi(e);
        }
    }
    while(!pasos.isEmpty()){
        e = pasos.izvadi();
        e.podatok.p = 0;
        cout<<"Za pasos e opsluzen "<<e.podatok.ime<<endl;
        if(e.podatok.vd == 1){
            vozacka.stavi(e);
        }
    }
    while(!vozacka.isEmpty()){
        e = vozacka.izvadi();
        e.podatok.vd = 0;
        cout<<"Za vozacka e opsluzen "<<e.podatok.ime<<endl;
    }
}
int main(){
    Red lk, p, vd;
    lk.init(); p.init(); vd.init();

    Covek covek;
    char znak;

    while(true){ //prekinuva koga vneseme .
        cin>>covek.ime;
        cin>>covek.prezime;
        cin>>covek.lk;
        cin>>covek.p;
        cin>>covek.vd;
        Element e;
        e.podatok = covek;
        if(covek.lk){
            lk.stavi(e);
        }else if(covek.p){
            p.stavi(e);
        }else if(covek.vd){
            vd.stavi(e);
        }

        cout<<"Vnesi . za prekin"<<endl;
        cin>>znak;
        if(znak == '.'){
            break;
        }
    }

    opsluzuvanje(lk, p, vd);

    return 0;
}