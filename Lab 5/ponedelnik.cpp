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
    void brisiPrv();
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
void Lista::brisiPrv(){
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
void spoj(Lista &lista1, Lista &lista2, Lista &lista3){
    Jazol *dvizi1 = lista1.head;
    Jazol *dvizi2 = lista2.head;
    int brojac = 0;
    while(dvizi1 != lista1.tail){
        if(dvizi1->podatok % 3 == 0){
            lista3.vnesiPosleden(dvizi1->podatok);
            lista1.brisiJazol(dvizi1);
        }
        dvizi1 = dvizi1->next;
    }
    cout<<"Po prvata lista > "; lista3.pecati();
    while(dvizi2 != lista2.tail){
        cout<<brojac<<" ";
        if(brojac % 2 == 0){
            lista3.vnesiPosleden(dvizi2->podatok);
            lista2.brisiJazol(dvizi2);
        }
        dvizi2 = dvizi2->next;
        brojac+=1;
    }
    
}
int main(){
    Lista l1, l2, l3;
    l1.init(); l2.init(); l3.init();
    int n1[] = {2, 5, 7, 9, 3, 3, 7, 1};
    int n2[] = {5, 3, 4, 1, 5, 1, 1, 5, 3, 4, 4, 3};
    for(int i=0; i<8;i++){
        l1.vnesiPosleden(n1[i]);
    }
    for(int i=0; i<12;i++){
        l2.vnesiPosleden(n2[i]);
    }
    l1.pecati(); l2.pecati();
    spoj(l1, l2, l3);
    l3.pecati();
    return 0;
}