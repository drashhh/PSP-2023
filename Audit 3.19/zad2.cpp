#include <iostream>
#include <stdlib.h>
using namespace std;
struct Jazol{
    int info;
    Jazol *link;
};
struct Lista{
    Jazol *head;
    void init();
    void kreirajLista(int element);
    void dodadiPrv(int element);
    void dodadiPosleden(int element);
    void brisiPrv();
    void brisiPosleden();
    void pechati();
    void brisiLista();
    Lista spoidDveListi(Lista &l1, Lista &l2);
};
void Lista::init(){
    head = NULL;
}
void Lista::kreirajLista(int element){
    head = new Jazol;
    head->info = element;
    head->link = NULL;
}
void Lista::dodadiPrv(int element){
    Jazol *pom = new Jazol;
    pom->info = element;
    pom->link = head;
    head = pom;
}
void Lista::dodadiPosleden(int element){
    Jazol *dvizi = head;
    Jazol *pom = new Jazol;
    pom->info = element;
    if(head == NULL){
        head = pom;
    }else{
        while(dvizi->link != NULL){
            dvizi = dvizi->link;
        }
        dvizi->link = pom;
    }
    pom->link = NULL;
}
void Lista::brisiPrv(){
    if(head != NULL){
        if(head->link == NULL){
            delete head;
            head = NULL;
        }else{
            Jazol *pom= head;
            head = head->link;
            delete pom;
        }
    }
}
void Lista::brisiPosleden(){
    if(head !=NULL){
        if(head->link == NULL){
            delete head;
            head == NULL;
        }else{
            Jazol *pom = head;
            Jazol *brisi;
            while(pom->link->link != NULL){
                pom = pom->link;
            }
            brisi = pom->link;
            pom->link = NULL;
            delete brisi;
        }
    }
}
void Lista::pechati(){
    cout<<"Elementi > ";
    for(Jazol *pom = head; pom!=NULL; pom = pom->link){
        cout<<pom->info<<" ";
    }
    cout<<endl;
}
void Lista::brisiLista(){
    while(head!=NULL){
        brisiPosleden();
    }
}
Lista spoidDveListi(Lista &l1, Lista &l2){
    Lista l3;
    l3.init();
    Jazol *dv1 = l1.head;
    Jazol *dv2 = l2.head;
    while((dv1 != NULL) && (dv2 != NULL)){
        if(dv1->info < dv2->info){
            l3.dodadiPosleden(dv1->info);
            dv1 = dv1->link;
        }else{
            l3.dodadiPosleden(dv2->info);
            dv2 = dv2->link;
        }
    }
    while(dv1 != NULL){
        l3.dodadiPosleden(dv1->info);
        dv1=dv1->link;
    }
    while(dv2 != NULL){
        l3.dodadiPosleden(dv2->info);
        dv2 = dv2->link;
    }
    return l3;
}

int main(){
    Lista l1,l2,l3;
    l1.kreirajLista(2);
    l1.dodadiPosleden(4);
    l1.dodadiPosleden(7);

    l2.kreirajLista(3);
    l2.dodadiPosleden(6);
    l2.dodadiPosleden(5);

    l3 = spoidDveListi(l1, l2);
    l3.pechati();
    return 0;
}