#include <iostream>
using namespace std;
struct Jazol{
    Jazol* next;
    Jazol* prev;
    int info;
};
struct Lista{
    Jazol* head;
    Jazol* tail;
    int brElementi;
    void init(){
        head = tail = NULL; brElementi = 0;
    }
    void dodadiPosleden(int br);
    void brisiPosleden();
    void pecati();
    void brisiLista(){
        while(head != NULL){
            brisiPosleden();
        }
    }
};
void Lista::dodadiPosleden(int br){
    Jazol *pom = new Jazol;
    pom->info =br;
    if(head == NULL){
        tail = head = pom;
        pom->prev = pom->next = pom;
    }else{
        pom->next = head;
        pom->prev = tail;
        tail->next = pom;
        head->prev = pom;
        tail = pom;
    }
    brElementi++;
}
void Lista::brisiPosleden(){
    if(head != NULL){
        if(head == tail){
            delete head;
            init();
        }else{
            Jazol *pom = tail;
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
            delete pom;
        }
    }
    brElementi--;
}
void Lista::pecati(){
    cout<<"Pecatenje na listata > ";
    Jazol* dvizi = head;
    while(dvizi != tail){
        cout<<dvizi->info<<" <-> ";
        dvizi = dvizi->next;
    }
    cout<<dvizi->info<<" elementi > "<<brElementi<<endl;
}
void rotiraj(Lista &lista1, int br){
    // if(br == 0) return;
    // Jazol*dvizi = lista1.head;
    // int brojac = 1;
    // while(dvizi != lista1.tail && br > brojac){
    //     dvizi = dvizi->next;
    //     brojac++;
    // }
    // Jazol* pozicija = dvizi;
    // lista1.head = pozicija;
    // lista1.tail = lista1.head->prev;
    for(int i=1;i<br;i++)
    {
        lista1.head=lista1.head->next;
    }

    
}
int main(){
    Lista l1; int broj;
    l1.init();
    l1.dodadiPosleden(3);
    l1.dodadiPosleden(9);
    l1.dodadiPosleden(2);
    l1.dodadiPosleden(4);
    l1.dodadiPosleden(7);

    l1.pecati();
    cout<<"Vnesi za kolku pati sakas da ja rotiras MORA DA E POMALKU OD "<<l1.brElementi<<endl;
    cin>>broj;
    rotiraj(l1, broj);
    l1.pecati();
    return 0;
}