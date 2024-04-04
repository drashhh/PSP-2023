#include <iostream>
using namespace std;
struct Igrac{
    string Ime;
    string Prezime;
    int poeni = 0;
};
struct Jazol{
    Jazol *next;
    Jazol *prev;
    int info;
};
struct Lista{
    Jazol* head;
    Jazol* tail;
    void init(){
        head = tail = NULL;
    }
    void dodadiPrv(int br);
    void dodadiPosleden(int br);
    void brisiPrv();
    void brisiPosleden();
    void brisiLista();
    void pecati();
};
void Lista::dodadiPrv(int br){
    Jazol *pom = new Jazol;
    pom->info = br;
    if(head == NULL){
        tail = head = pom;
        pom->prev = pom->next = pom;
    }else{
        pom->next = head;
        pom->prev = tail;
        head -> prev = pom;
        tail -> next = pom;
        head = pom;
    }
}
void Lista::dodadiPosleden(int br){
    Jazol *pom = new Jazol;
    pom->info = br;
    if(head == NULL){
        tail = head = pom;
        pom->prev = pom->next = pom;
    }else{
        pom->next = head;
        pom->prev = tail;
        head->prev = pom;
        tail->next = pom;
        tail = pom;
    }
}
void Lista::brisiPrv(){
    if(head != NULL){
        if(head->next == head){
            delete head;
            init();
        }else{
            Jazol*pom = head;
            tail->next = head->next;
            head = head->next;
            head->prev = tail;
            delete pom;
        }
    }
}
void Lista::brisiPosleden(){
    if(head != NULL){
        if(head -> next == head){
            delete head;
            init();
        }else{
            Jazol*pom = tail;
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
            delete pom;
        }
    }
}
void Lista::brisiLista(){
    while(head != NULL){
        brisiPrv();
    }
}
void Lista::pecati(){
    cout<<"Pecatenje na poeni > ";
    Jazol *dvizi = head;
    while(dvizi != tail){
        cout<<dvizi->info<<" <-> ";
        dvizi= dvizi->next;
    }
    cout<<dvizi->info<<endl;
}
void pocniIgra(Igrac &p1, Igrac &p2, Lista &poeni){
    Jazol* dvizi1 = poeni.head;
    Jazol* dvizi2 = poeni.head;
    int dviziZa, brojac = 0; char dviziNasoka;
    cout<<"Igrata zapocnuva..."<<endl;
    cout<<"Kako se igra? pisuvas brojka (1 do 7) i nasoka na dvizenje (l i d)"<<endl;
    while(dvizi1 != poeni.tail){
        brojac = 0;
        cout<<"Igrac "<<p1.Ime<<" vnesi go cekorot >";
        cin>>dviziZa>>dviziNasoka;
        cout<<"Se dvizi..."<<endl;
        while(dvizi1 != poeni.tail && brojac != dviziZa && dviziNasoka == 'd'){
            dvizi1 = dvizi1 ->next;
            brojac++;
        }
        while(dvizi1 != poeni.tail && brojac != dviziZa && dviziNasoka == 'l'){
            dvizi1 = dvizi1 ->prev;
            brojac++;
        }
        p1.poeni += dvizi1->info;
        cout<<"Vkupno poeni > "<<p1.poeni<<endl;
    }
    cout<<"Evaa botljak samo "<<p1.poeni<<" iskara odi izbrisija igrata be nubljak NPC boss"<<endl;
    cout<<"AJ pa sea da videme ovaj pa so ke naprave "<<endl<<endl;
    while(dvizi2 != poeni.tail){
        brojac = 0;
        cout<<"Igrac "<<p2.Ime<<" vnesi go cekorot >";
        cin>>dviziZa>>dviziNasoka;
        cout<<"Se dvizi..."<<endl;
        while(dvizi2 != poeni.tail && brojac != dviziZa && dviziNasoka == 'd'){
            dvizi2 = dvizi2 ->next;
            brojac++;
        }
        while(dvizi2 != poeni.tail && brojac != dviziZa && dviziNasoka == 'l'){
            dvizi2 = dvizi2 ->prev;
            brojac++;
        }
        p2.poeni += dvizi2->info;
        cout<<"Vkupno poeni > "<<p2.poeni<<endl;
    }
    cout<<"Evaa botljak samo "<<p2.poeni<<" iskara odi izbrisija igrata be nubljak NPC boss"<<endl;
}
int main(){
    //Inicijalizacija na poeni
    Lista poeni;
    poeni.init();
    poeni.dodadiPrv(6);
    poeni.dodadiPosleden(5);
    poeni.dodadiPosleden(2);
    poeni.dodadiPosleden(10);
    poeni.dodadiPosleden(3);
    poeni.dodadiPosleden(0);
    poeni.dodadiPosleden(7);
    poeni.pecati();

    //inicijalizacija na igraci
    Igrac p1,p2;
    p1.Ime = "Stole"; p1.Prezime = "Angelov"; p1.poeni = 0;
    p2.Ime = "Baska"; p2.Prezime = "Klaus"; p2.poeni = 0;


    pocniIgra(p1,p2,poeni);
    return 0;
}