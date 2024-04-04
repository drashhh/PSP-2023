#include <iostream>
using namespace std;
struct Jazol{
    Jazol* next;
    int info;
};
struct Lista{
    Jazol *head;
    Jazol *tail;
    void init(){
        head = tail = NULL;
    }
    void dodadiPrv(int podatok);
    void dodadiPosleden(int podatok);
    void brisiPrv();
    void brisiLista();
    void pecati();
};
void Lista::dodadiPosleden(int podatok){
        Jazol *pom = new Jazol;
        Jazol *dvizi = head;
        pom->info = podatok;
        if(head == NULL){
            pom->next = pom;
            head = tail = pom;
        }else{
           pom->next = head;
           tail->next = pom;
           tail = pom;
        }
    }
void Lista::dodadiPrv(int podatok){
        Jazol* pom = new Jazol;
        pom->info = podatok;
        if(head == NULL){
            pom->next = pom;
            tail = head = pom;
        }else{
            pom->next = head;
            head = pom; 
            tail->next = head;
        }
    }
void Lista::brisiPrv(){
    if(head != NULL){
        if(head == tail){
            delete head;
            init();
            return;
        }
        Jazol*pom = head;
        tail->next = head->next;
        head = head->next;
        delete pom;
    }
}
void Lista::brisiLista(){
    while(head != NULL){
        brisiPrv();
    }
}
void Lista::pecati(){
    cout<<"pecatenje na lista > ";
    Jazol*dvizi = head;
    while(dvizi != tail){
        cout<<dvizi->info<<" -> ";
        dvizi = dvizi->next;
    }
    cout<<dvizi->info<<endl;
}
Lista presek(Lista &li1, Lista &li2){
    Lista l3; l3.init();
    Jazol *dvizi1 = li1.head;
    Jazol *dvizi2 = li2.head;
    while(dvizi1 != li1.tail && dvizi2 != li2.tail){
        if(dvizi1->info == dvizi2->info){
            l3.dodadiPosleden(dvizi1->info);
        }else{
            l3.dodadiPosleden(0);
        }
        dvizi1 = dvizi1->next; dvizi2 = dvizi2 -> next;
    }
    if(dvizi1->info == dvizi2->info){
            l3.dodadiPosleden(dvizi1->info);
    }else{
            l3.dodadiPosleden(0);
    }
    return l3;
}
int main(){
    Lista lista1, lista2, lista3;
    lista1.init(); lista2.init(); lista3.init();
    int niza[] = {1,3,4,5,7,9,10,15};
    int niza2[] = {1,9,7,6,7,8,10};
    
    lista1.dodadiPrv(niza[0]);
    for(int i = 1; i< 8; i++){
        lista1.dodadiPosleden(niza[i]);
    }
    
    lista2.dodadiPrv(niza2[0]);
    for(int i = 1; i< 7; i++){
        lista2.dodadiPosleden(niza2[i]);
    }
    
    lista1.pecati(); lista2.pecati();
    cout<<"Pronaogjanje prosek..."<<endl;
    lista3 = presek(lista1, lista2);
    lista3.pecati();
    return 0;
}