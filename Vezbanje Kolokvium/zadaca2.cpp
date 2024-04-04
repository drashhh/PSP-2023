/*
Да се напишат потребните структури и функции за работа со двојно поврзана нул
терминирана скалеста листа. Скалеста листа е двојно поврзана листа чии јазли најпрвин се
зголемуваат, па се намалуваат. Да се направи глобална функција sortiraj која што ќе ги сортира
јазлите на скалестата листа.
Како дел од програмата да се напишат структурата за имплементација на листата заедно со
функции за креирање на листа, додавање и бришење на елемент од листата, печатење на листата,
бришење на листата, додавање после јазол (два влезни аргументи: вредноста која се става во
новиот јазолот и покажувач кон јазол после кој треба да се изврши додавањето). Дополнително да
се напише главна програма за да се тестираат листата и функциите.
Пример:
Влез: 2 <->5<->7<->12<->10<->6<->4<->1
Излез: 1<->2<->4<->5<->6<->7<->10<->12
Влез: 20<->17<->14<->8<->3
Излез: 3<->8<->14<->17<->20
*/
#include <iostream>
using namespace std;
struct Jazol{
    Jazol*next;
    Jazol*prev;
    int info;
};
struct Lista{
    Jazol* head;
    Jazol* tail;
    void init(){
        head = tail = NULL;
    }
    void dodadiPrv(int podatok);
    void dodadiPosleden(int podatok);
    void brisiPrv();
    void brisiPosleden();
    void brisiLista();
    void pecati();
    void dodadiPo(int podatok, Jazol* pok);
    void brisi(Jazol* brisi);
    void smeniJazolSoSleden(Jazol *smeni);
};
void Lista::brisi(Jazol*brisi){
    if(brisi->prev == head){
        head->next = brisi->next;
        head->prev = NULL;
    }
    if(brisi->next == tail){
        tail->prev = brisi->prev;
        tail->next = NULL;
    }
    brisi->prev->next = brisi->next;
    brisi->next->prev = brisi->prev;
}
void Lista::dodadiPo(int podatok, Jazol* pok){
    Jazol*pom = new Jazol;
    if(pok->next == NULL){ // taj e pok e posleden jazol
        pom->info = podatok;
        pom->next = NULL;
        pom->prev = pok;
        pok->next = pom;
        tail = pom;
    }
    pom->info = podatok;
    pom->prev = pok->next->prev;
    pom->next = pok->next;
    pok->next->prev = pom;
    pok->next = pom;
}
void Lista::dodadiPrv(int podatok){
    Jazol*pom = new Jazol;
    pom->info = podatok;
    pom->prev = NULL;
    pom->next = head;
    if(head == NULL){
        tail = pom;
    }else 
        head->prev = pom;
    head = pom;
}
void Lista::dodadiPosleden(int podatok){
    Jazol* pom = new Jazol;
    pom->info = podatok;
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
        if(head->next == NULL){
            delete head; init();
        }else{
            Jazol *pom = head;
            head = head->next;
            head->prev = NULL;
            delete pom;
        }
    }
}
void Lista::brisiPosleden(){
    if(head != NULL){
        if(head->next == NULL){
            delete head; init();
        }else{
            Jazol *pom = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete pom;
        }
    }
}
void Lista::brisiLista(){
    while(head != NULL){
        brisiPosleden();
    }
}
void Lista::pecati(){
    cout<<"Pecatenje na lista > ";
    Jazol*dvizi = head;
    while(dvizi != tail){
        cout<<dvizi->info<<" ";
        dvizi = dvizi->next;
    }
    cout<<dvizi->info<<endl;
}
void Lista::smeniJazolSoSleden(Jazol *smeni){
    Jazol* sleden = smeni->next;
    Jazol* pomSleden = sleden;
    Jazol*pomSmeni = smeni;
    Jazol *pom = new Jazol;
    if(head == NULL || head->next == NULL)
        return;
    pom = smeni->next;
    smeni->next = sleden->next;
    sleden->next = pom;
    if(smeni->next != NULL)
        smeni->next->prev = smeni;
    if(sleden->next != NULL)
        sleden->next->prev = sleden;
    pom = smeni->prev;
    smeni->prev = sleden->prev;
    sleden->prev = pom;

    if(smeni->prev != NULL)
        smeni->prev->next = smeni;
    if(sleden->prev != NULL)
        sleden->prev->next = sleden;
    
}
void sortiraj(Lista &lista1){
    Jazol *dvizi1 = lista1.head;
    Jazol *dvizi2 = NULL;
    int pom;

    while(dvizi1 != NULL){
        dvizi2 = dvizi1->next;
        while(dvizi2 != NULL){
            if(dvizi1->info > dvizi2->info){
                pom = dvizi1->info;
                dvizi1->info = dvizi2->info;
                dvizi2->info = pom;
            }
            dvizi2 = dvizi2->next;
        }
        dvizi1 = dvizi1->next;
    }
}   
int main(){
    Lista l1;
    l1.init();
    l1.dodadiPrv(2); l1.dodadiPosleden(5); l1.dodadiPosleden(3);
    // Jazol* dvizi = l1.head; 
    // dvizi = dvizi->next->next;
    // l1.dodadiPo(10, dvizi);
    l1.pecati();
    sortiraj(l1);
    l1.pecati();
    return 0;
}