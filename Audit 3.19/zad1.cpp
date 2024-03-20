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
void podeliParnost(Lista &lista){
    Lista l1,l2;
    l1.init();
    l2.init();
    Jazol *dvizi = lista.head;

    while(dvizi != NULL){
        if(dvizi -> info % 2 == 0){
            l1.dodadiPosleden(dvizi->info);
        
        }else{
            l2.dodadiPosleden(dvizi->info);
        }
        dvizi = dvizi->link;
    }

    cout<<"Parna lista"<<endl;
    l1.pechati();
    cout<<"Neparna lista"<<endl;
    l2.pechati();
    l1.brisiLista();
    l2.brisiLista();
}

int main(){
    Lista lista;
    lista.kreirajLista(1);

    for(int i =2; i< 7; i++){
        lista.dodadiPosleden(i);
    }

    lista.pechati();

    podeliParnost(lista);
    lista.brisiLista();
    return 0;
}