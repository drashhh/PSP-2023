#include <iostream>
using namespace std;
struct Jazol{
    Jazol* next;
    int info;
};
struct Lista{
    Jazol* head;
    Jazol* tail;
    void init(){
        head = tail = NULL;
    }
    void dodadiPrv(int podatok){
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
    void dodadiPosleden(int podatok){
        Jazol *pom = new Jazol;
        Jazol *dvizi = head;
        pom->info = podatok;
        if(head == NULL){
            pom->next = pom;
            head = pom = tail;
        }else{
           pom->next = head;
           tail->next = pom;
           tail = pom;
        }
    }
    void brisiPrv(){
        if(head != NULL){
            if(head == tail){
                delete head;
                head = tail = NULL;
                return;
            }
            Jazol *pom = head;
            tail->next = head->next;
            head = head->next;
            delete pom;
        }
    }
    void brisiPosleden(){
        if(head != NULL){
            if(head == tail){
                delete head;
                head = tail = NULL;
                return;
            }
            Jazol * pom = tail;
            Jazol * dvizi = head;
            while(dvizi->next != tail)
                dvizi = dvizi->next;
            dvizi->next = head;
            tail = dvizi;
            delete pom;
        }
    }
    void brisiLista(){
        while(head!=NULL){
            brisiPrv();
        }
    }
    void pecati(){
        cout<<"Pecatenje na lista > ";
        Jazol* dvizi = head;
        while(dvizi != tail){
            cout<<dvizi->info<<" ";
            dvizi = dvizi->next;
        }
        cout<<dvizi->info<<endl;
    }
    void brisiJazol(Jazol* brisi){
        if(brisi == head){
            brisiPrv();
            return;
        }
        //Jazol* pom = brisi;
        Jazol *dvizi = head;
        while(dvizi->next != brisi)
            dvizi = dvizi->next;
        dvizi->next = brisi->next;
        // brisi = brisi->next;
        //delete pom;
    }
};
void podeli(Lista &l1, Lista &l2){
    Jazol* dvizi1 = l1.head;
    l2.dodadiPrv(dvizi1->info);
    Jazol *pom=dvizi1;
    
    dvizi1 = dvizi1->next;
//l1.brisiJazol(pom);
    while(dvizi1 != l1.head && dvizi1->info != 107 && dvizi1 != l1.tail){
        cout<<"Ulezeno e do tuka dvizi 1 podatok"<<dvizi1->info<<endl;
        l2.dodadiPosleden(dvizi1->info);
        l1.brisiJazol(dvizi1);
        dvizi1 = dvizi1->next;
    }
    //l1.brisiPrv();
}
int main(){
    Lista lista1, lista2;
    lista1.init(); lista2.init();
    int niza[] = {108, 105, 110, 107, 101,100,108,111,111,112};
    lista1.dodadiPrv(niza[0]);
    for(int i=1; i<10; i++){
        lista1.dodadiPosleden(niza[i]);
    }
    lista1.pecati();
    podeli(lista1, lista2);
    cout<<"Lista 1 > ";
    lista1.pecati();
    cout<<"Lista 2 > ";
    lista2.pecati();
    return 0;
}