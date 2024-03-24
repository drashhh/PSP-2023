/*
Да се напише функција за работа со единечно поврзани кружни листи, која на влез добива
две пополнети листи. Функцијата треба да ги измине истовремено листите и доколку наиде на
јазли со иста вредност, јазолот од втората листа да се префрли во првата листа (во втората листа
повеќе да го нема) и тоа пред моментално разгледуваниот јазол во првата листа. Изминувањето
се прави се додека има јазли и во двете листи. Изминувањето на листите да се направи во
глобална функција promeni.
Како дел од програмата да се напишат структури за имплементација на јазол и листа и
функциите за поддршка на листата: функција за иницијализација, функции додавање и бришење
на елемент на почеток од листата, додавање и бришење на елемент на крај од листата, бришење
на цела листа, печатење на елементите од листата и бришење на јазол (адресата на јазолот кој
треба да се брише се добива на влез од функцијата)
Влез:
Lista1: |10|->|2|->|5|->|7|->|13|
Lista2: |5|->|2|->|7|->|7|
Излез:
Lista1: |10|->|2|->|2|->|5|->|7|->|7|->|13|
Lista2: |5|->|7|
*/

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
void promeni(EPLista &l1, EPLista &l2){
    Jazol *dvizi1 = l1.head;
    Jazol *dvizi2 = l2.head;
    while(dvizi1 != NULL && dvizi2 != NULL){
        cout<<"Podatok l1 "<<dvizi1->podatok<<" podatok l2 "<<dvizi2->podatok<<endl;
        if(dvizi1->podatok == dvizi2->podatok){
            cout<<"Isti podatok "<<dvizi1->podatok<<endl;
            l1.dodadiPred(dvizi1, dvizi2->podatok);
            l2.brisi(dvizi2);
        }
        dvizi1 = dvizi1->pok;
        dvizi2 = dvizi2->pok;
        
    }
    return;
}
int main(){
    EPLista lista1, lista2;
    int niza1[] = {10, 2, 5, 7, 13}, niza2[] = {5, 2, 7, 5};
    lista1.init();
    lista2.init();
    lista1.dodadiPrv(niza1[0]);

    for(int i = 1; i<5; i++){
        lista1.dodadiPosleden(niza1[i]);
    }

    lista2.dodadiPrv(niza2[0]);

    for(int j =1; j<4; j++){
        lista2.dodadiPosleden(niza2[j]);
    }
    lista1.pecati();
    lista2.pecati();
    promeni(lista1, lista2);
    lista1.pecati();
    lista2.pecati();
    return 0;
}