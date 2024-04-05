#include <iostream>
using namespace std;
struct Magacin{
    int niza[30];
    int top;
    void init(){
        top = -1;
    }
    void stavi(int info);
    int peek();
    int pop();
    bool isEmpty();
    bool isFull();
    void pecati();
};
struct Red{
    int nizaRed[30];
    int front, rear;
    void init(){
        front = 0;
        rear = -1;
    }
    bool isEmpty();
    bool isFull();
    void stavi(int info);
    int pull();
    int peek();
    void pecati();
    
};
bool Magacin::isEmpty(){
    return (top == -1);
}
bool Magacin::isFull(){
    return (top == 30);
}
void Magacin::stavi(int info){
    if(isFull()){
        cout<<"nizata e polna!"<<endl;
        exit(-1);
    }
    niza[++top] = info;
}
int Magacin::peek(){
    if(isEmpty()){
        cout<<"nizata e prazna! u peek"<<endl;
        exit(-1);
    }
    return niza[top];
}
int Magacin::pop(){
    if(isEmpty()){
        cout<<"Nizata e prazna! u pop"<<endl;
        exit(-1);
    }
    return niza[--top];
}
void Magacin::pecati(){
    cout<<"pecatenje na magacin od gore gledan"<<endl;
    for(int i = top; i >= 0 ; i--){
        cout<<niza[i]<<" ";
    }
    cout<<endl;
}

bool Red::isFull(){
    return (front == 29);
}
bool Red::isEmpty(){
    return (rear == -1);
}
void Red::stavi(int info){
    if(front == -1){
        front = 0;
    }
    nizaRed[++rear] = info;
}
int Red::pull(){
    if(isEmpty()){
        cout<<"nema clenovi"<<endl;
        exit(-1);
    }else{
        int temp = nizaRed[front];
        if(front == rear){
            front = rear = -1;
        }else front++;
        return temp;
    }
    
}
int Red::peek(){
    return nizaRed[front];
}
void Red::pecati(){
    cout<<"pecatenje od nazad na redot"<<endl;
    for(int i = rear; i >= front; i--){
        cout<<nizaRed[i]<<" ";
    }
    cout<<endl;
}
struct Jazol{
    Jazol* next;
    int podatok;
};
struct EKruznaLista{
    Jazol* head;
    Jazol* tail;
    void init(){
        head = tail = NULL;
    }
    void dodadiPrv(int i){
        Jazol *pom = new Jazol;
        pom->podatok = i;
        if(head == NULL){
            pom->next = pom;
            head= tail = pom;
        }else{
            pom->next = head;
            head = pom;
            tail->next = head;
        }
    }
    void dodadiPosleden(int i){
        Jazol*pom = new Jazol;
        pom->podatok = i;
        if(head == NULL){
            pom->next = pom;
            head = tail = pom;
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
                init();
            }else{
                Jazol*pom = head;
                head = head->next;
                tail->next = head;
                delete pom;
            }
        }
    }
    void brisiPosleden(){
        if(head != NULL){
            if(head == tail){
                delete head;
                init();
            }else{
                Jazol*pom = tail;
                Jazol*dvizi = head;
                while(dvizi->next != tail){
                    dvizi = dvizi->next;
                }
                dvizi->next = head;
                tail = dvizi;
                delete pom;
            }
        }
    }
    void pecati(){
        cout<<"Pecatenje > ";
        Jazol*dvizi = head;
        while(dvizi != tail){
            cout<<dvizi->podatok<<" -> ";
            dvizi= dvizi->next;
        }
        cout<<dvizi->podatok<<endl;
    }
};
int main(){
    Magacin m1;
    m1.init();
    m1.stavi(5);
    m1.stavi(10);
    m1.stavi(15);
    m1.pecati();
    m1.pop();
    m1.pecati();
    Red r1;
    r1.init();
    r1.stavi(5); r1.stavi(10); r1.stavi(15);
    r1.pecati();
    r1.pull();
    int temp = r1.peek();
    cout<<temp<<endl;

    EKruznaLista lista1;
    lista1.init();
    lista1.dodadiPrv(7);
    lista1.dodadiPosleden(14);
    lista1.dodadiPosleden(21);
    lista1.pecati();
    lista1.brisiPrv(); lista1.brisiPosleden();
    lista1.pecati();
    cout<<lista1.head->podatok<<endl;
    return 0;
}