#include <iostream>
using namespace std;
struct Jazol{
    Jazol* prev;
    Jazol* next;
    int podatok;
};
struct KruznaDvojnaLista{
    Jazol* head;
    Jazol* tail;
    int brElementi;
    void init(){
        head = tail = NULL; brElementi = 0;
    }
    void dodadiPrv(int info){
        Jazol*pom = new Jazol;
        pom->podatok = info;
        if(head == NULL){
            tail = head = pom;
            pom->prev = pom->next = pom;
        }else{
            pom->next = head;
            pom->prev = tail;
            tail->next = pom;
            head->prev = pom;
            head = pom;
        }
        brElementi++;
    }
    void dodadiPosleden(int info){
        Jazol*pom = new Jazol;
        pom->podatok = info;
        if(tail == NULL){
            tail = head = pom;
            pom->prev = pom->next = pom;
        }else{
            pom->prev = tail;
            pom->next = head;
            tail->next = pom;
            head->prev = pom;
            tail = pom;
        }
        brElementi++;
    }
    void brisiPrv(){
        if(head != NULL){
            if(head->next == head){
                delete head;
                head = tail = NULL;
            }else{
                Jazol*pom = head;
                tail->next = head->next;
                head = head->next;
                head->prev = tail;
                delete pom;
            }

            brElementi--;
        }
    }
    void brisiPosleden(){
        if(head != NULL){
            if(head == tail){
                delete head;
                head = tail = NULL;
            }else{
                Jazol*pom = tail;
                tail = tail->prev;
                tail->next = head;
                head->prev = tail;
                delete pom;
            }
        }
    }
    void pecati(){
        cout<<"Pecatenje na listata > ";
        Jazol *dvizi = head;
        do{
            cout<<dvizi->podatok<<" ";
            dvizi = dvizi -> next;
        }while(dvizi != tail);
        cout<<dvizi->podatok<<endl;
    }
    Jazol* brisiMomentalen(Jazol* momentalen){
        Jazol* pom = momentalen;
       // cout<<"momentalen predhodnik "<<momentalen->prev->podatok<<" momentalen sledbenik"<<momentalen->next->podatok<<endl;
        if(momentalen->prev == tail && momentalen->next != tail){
            head = head -> next;
            tail-> next = head;
        }
        if(momentalen->next == head && momentalen->prev != head){
            tail = tail ->prev;
            head->prev = tail;
        }
        momentalen->next->prev = momentalen->prev;
        momentalen->prev->next = pom->next;
        return momentalen->prev->prev;
    }
};
void spojgi(KruznaDvojnaLista &l1, KruznaDvojnaLista &l2, KruznaDvojnaLista &l3){
    Jazol* dvizi1 = l1.head;
    Jazol* dvizi2 = l2.head;
    do{
        if(dvizi1->podatok % 3 == 0){
            //cout<<"Podatokot "<<dvizi1->podatok<<endl;
            l3.dodadiPosleden(dvizi1->podatok);
            dvizi1 = l1.brisiMomentalen(dvizi1);
        }
        dvizi1 = dvizi1->next;
    }while(dvizi1 != l1.tail);
    if(dvizi1->podatok % 3 == 0){
            l3.dodadiPosleden(dvizi1->podatok);
            dvizi1 = l1.brisiMomentalen(dvizi1);
    }
    int brojac;
    for(brojac = 0; dvizi2 != l2.tail;brojac++, dvizi2 = dvizi2->next){
        if(brojac % 2 == 0){
            l3.dodadiPosleden(dvizi2->podatok);
            l2.brisiMomentalen(dvizi2);
        }
        cout<<"brojac "<<brojac<<" clen "<<dvizi2->podatok;
    }
    cout<<endl<<"Nadvor od for ciklus " << brojac<<endl;
    if(brojac % 2 == 0){
        l3.dodadiPosleden(dvizi2->podatok);
        l2.brisiMomentalen(dvizi2);
    }
}
int main(){
    KruznaDvojnaLista lista1, lista2, lista3;
    lista1.init();
    lista2.init();
    lista3.init();
    int niza1[] = {2, 5, 7, 9, 3,3,7,1};
    int niza2[] = {5,3,4,1,5,1,1,5,3,4,4,3};

    lista1.dodadiPrv(niza1[0]);
    for(int i = 1; i<8; i++){
        lista1.dodadiPosleden(niza1[i]);
    }
    lista2.dodadiPrv(niza2[0]);
    for(int i = 1; i< 13; i++){
        lista2.dodadiPosleden(niza2[i]);
    }
    cout<<"Pred promeni"<<endl;
    lista1.pecati(); lista2.pecati(); //lista3.pecati();
    cout<<"----------------------------------------------------"<<endl;
    spojgi(lista1, lista2, lista3);
    cout<<"Novite listi"<<endl;
    lista1.pecati(); lista2.pecati(); lista3.pecati();
    cout<<"----------------------------------------------------"<<endl;
    return 0;
}