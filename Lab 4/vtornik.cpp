#include <iostream>
using namespace std;
struct Jazol{
    Jazol *pok;
    int podatok;
};
struct EPLista{
    Jazol *head;
    void init();
    void dodadiPrv(int vred);
    void dodadiPosleden(int vred);
    void brisiPrv();
    void brisiPosleden();
    void brisiLista();
    void pecati();
    void dodadiPred(Jazol *jazol, int vred);
    void brisi(Jazol *brisi);
};
void EPLista::init(){
    head = NULL;
}
void EPLista::dodadiPrv(int vred){
    Jazol *pom = new Jazol;
    pom->pok=head;
    pom->podatok=vred;
    head = pom;
}
void EPLista::dodadiPosleden(int vred){
    Jazol *dvizi = head;
    Jazol *pom = new Jazol;
    pom->podatok = vred;
    if(head == NULL){
        head = pom;
    }else{
        while(dvizi->pok != NULL){
            dvizi = dvizi->pok;
        }
        dvizi->pok = pom;
    }
    pom->pok = NULL;
}
void EPLista::brisiPrv(){
    if(head != NULL){
        if(head->pok == NULL){
            delete head;
            head = NULL;
        }else{
            Jazol *pom = head;
            head = head->pok;
            delete pom;
        }
    }
}
void EPLista::brisiPosleden(){
    if(head != NULL){
        if(head->pok == NULL){
            delete head;
            head = NULL;
        }else{
            Jazol *pom = head, *brisi;
            while(pom->pok->pok != NULL){
                pom = pom->pok;
            }
            brisi = pom->pok;
            pom->pok = NULL;
            delete brisi;
        }
    }
}
void EPLista::brisiLista(){
    while(head != NULL){
        brisiPosleden();
    }
}
void EPLista::pecati(){
    cout<<"Pecatenje na povrzana lista > ";
    for(Jazol *pom = head; pom != NULL; pom = pom->pok){
        cout<<pom->podatok<<" ";
    }
    cout<<endl;
}
void EPLista::dodadiPred(Jazol *jazol, int vred){
    if(jazol == head){
        dodadiPrv(vred);
        return;
    }
    Jazol *dvizi = head;
    while(dvizi != NULL && dvizi->pok != jazol){
        dvizi = dvizi->pok;
    }
    if(dvizi != NULL){
        Jazol *nov = new Jazol;
        nov->pok = jazol;
        nov->podatok = vred;
        dvizi->pok = nov;
    }
}
void EPLista::brisi(Jazol *brisi){
    Jazol *dvizi = head;
    Jazol *temp = new Jazol;
    while(dvizi != NULL && dvizi!=brisi){
        temp = dvizi;
        dvizi = dvizi->pok;
    }
    //cout<<"Temp vrednost"<<temp->podatok<<endl;
    temp->pok = brisi->pok;
}
void funk(EPLista &l1, EPLista &l2, int br1, int br2){
    if(br2 < br1){
        int temp = br2;
        br2 = br1;
        br1 = temp;
    }
    cout<<br1<<" "<<br2;
    Jazol *dvizi = l1.head;
    while(dvizi != NULL){
        if(dvizi->podatok >= br1 && dvizi->podatok <= br2){
            l2.dodadiPosleden(dvizi->podatok);
            l1.brisi(dvizi);
        }

        dvizi = dvizi->pok;
    }
}
int main(){
    int broj1, broj2;
    EPLista l1,l2;
    l1.init();
    l2.init();
    int nizaBr[] = {12, 7, 5, 13, 5, 9, 2};

    l1.dodadiPrv(nizaBr[0]);
    for(int i = 1; i < 7; i++){
        l1.dodadiPosleden(nizaBr[i]);
    }

   l1.pecati();

    cout<<"Vnesi gi dvata broja > "; cin>>broj1>>broj2;
    funk(l1,l2,broj1,broj2);

    cout<<"Novi listi"<<endl;
    l1.pecati();
    l2.pecati();
    l1.brisiLista();
    l2.brisiLista();
    return 0;
}