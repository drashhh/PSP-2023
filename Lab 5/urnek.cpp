#include <iostream>
using namespace std;
struct Jazol{
    int podatok;
    Jazol *prev;
    Jazol *next;
};
struct Lista{
    Jazol *head;
    Jazol *tail;

    void init();
    void vnesiPrv(int info);
    void vnesiPosleden(int info);
    int brisiPrv();
    void brisiPosleden();
    void brisiJazol(Jazol *pom);
    void pecati();
};
void Lista::init(){
    head = tail = NULL;
}
void Lista::vnesiPrv(int info){
    Jazol *pom = new Jazol;
    pom->podatok = info;
    pom->next = head;
    pom->prev = NULL;
    if(head == NULL){
        tail = pom;
    }else
        head->prev = pom;
    head = pom;
}
void Lista::vnesiPosleden(int info){
    Jazol *pom = new Jazol;
    pom->podatok = info;
    pom->next = NULL;
    pom->prev = tail;
    if(head == NULL){
        head = pom;
    }else
        tail->next = pom;
    tail = pom;
}
int Lista::brisiPrv(){
    int temp = head->podatok;
    if(head != NULL){
        if(head -> next == NULL){
            delete head;
            head = tail = NULL;
        }else{
            Jazol *pom = head;
            head = head->next;
            head->prev = NULL;
            delete pom;
        }
    }
    return temp;
}
void Lista::brisiPosleden(){
    if(head!=NULL){
        if(head -> next == NULL){
            delete head;
            head = tail = NULL;
        }else{
            Jazol *pom = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete pom;
        }
    }
}
void Lista::brisiJazol(Jazol *pom){
    if(pom==NULL || head == NULL)
        return;
    if(pom == head){
        brisiPrv();
    }
    if(pom == tail){
        brisiPosleden();
    }
    pom->next->prev = pom->prev;
    pom->prev->next = pom->next;
    delete pom;
}
void Lista::pecati(){
    if(head == NULL)
        return;
    Jazol *dvizi = head;
    cout<<"Pecatenje na listata > ";
    while(dvizi != tail){
        cout<<dvizi->podatok<<" ";
        dvizi = dvizi->next;
    }
    cout<<dvizi->podatok<<endl;
}
void spoi(Lista &l1, Lista &l2, Lista &l3){
    l3.init();
    Jazol* dvizi1 = l1.head;
    Jazol* dvizi2 = l2.head;
    int temp = l1.brisiPrv();
    cout<<"Brisi prv lista1 "<<temp<<endl;
    l1.vnesiPrv(temp);
    while(dvizi1->next != l1.tail || dvizi2->next != l2.tail){
            l3.vnesiPosleden(l1.brisiPrv());
            l3.vnesiPosleden(l1.brisiPrv());
            l3.vnesiPosleden(l2.brisiPrv());
            l3.vnesiPosleden(l2.brisiPrv());
            dvizi1 = dvizi1->next; dvizi2= dvizi2->next;
    }
    l3.pecati();
}
// void spoi(DPlista &L1,DPlista &L2,DPlista &L3){
//     L3.init();
//     if(L1.brel<=L2.brel){
//         for(int i=0;i<L2.brel;i+=2){
//             if(L1.brel>=i+2){
//                 L3.dodadiPosleden(L1.citajNaPozicija(i));
//                 L3.dodadiPosleden(L1.citajNaPozicija(i+1));
//                 L3.dodadiPosleden(L2.citajNaPozicija(i));
//                 L3.dodadiPosleden(L2.citajNaPozicija(i+1));
//             }else{
//                 if(L1.brel==i+1&&L2.brel>=i+2){
//                     L3.dodadiPosleden(L1.citajNaPozicija(i));
//                     L3.dodadiPosleden(L2.citajNaPozicija(i));
//                     L3.dodadiPosleden(L2.citajNaPozicija(i+1));
//                 }else if(L1.brel<i+1&&L2.brel>=i+2){
//                     L3.dodadiPosleden(L2.citajNaPozicija(i));
//                     L3.dodadiPosleden(L2.citajNaPozicija(i+1));
//                 }else if(L1.brel<i+1&&L2.brel==i+1){
//                     L3.dodadiPosleden(L2.citajNaPozicija(i));
//                 }
//             }
//         }
//     }
// }
int main(){
    Lista lista1, lista2, lista3;
    lista1.init();
    lista2.init();
    int niza1[] = {11, 21, 31};
    int niza2[] = {21, 22, 32};
    lista1.vnesiPosleden(11);
    lista1.vnesiPosleden(21);
    lista1.vnesiPosleden(31);
    lista2.vnesiPosleden(12);
    lista2.vnesiPosleden(22);
    lista2.vnesiPosleden(32);
    lista1.pecati(); lista2.pecati();

    spoi(lista1, lista2, lista3);
    cout<<"zavrsil"<<endl;
    lista3.pecati();
    return 0;
}