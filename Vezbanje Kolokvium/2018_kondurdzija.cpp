#include <iostream>
#define MAX 30
using namespace std;
struct Red{
    int niza[MAX];
    int front;
    int rear;
    void init();
    void push(int podatok);
    int pull();
    int peek();
    bool isEmpty();
    void print();
};
void Red::init(){
    front = rear = -1;
}
bool Red::isEmpty(){
    return (rear == -1);
}
void Red::push(int podatok){
    rear++;
    niza[rear] = podatok;
}
int Red::pull(){
    if(isEmpty()){
        cout<<"redot e prazen.u pull"<<endl;
        exit(-1);
    }
    int pom = niza[front];
    if(front == rear)
        front = rear = -1;
    else    
        front++;
    return pom;
}
int Red::peek(){
    if(isEmpty()){
        cout<<"redot e prazen. u peek"<<endl;
        exit(-1);
    }
    return niza[front];
}
void Red::print(){
    cout<<"Pecatenje na redot > ";
    for(int i = front; i <= rear; i++){
        cout<<niza[i]<<" ";
    }
}
struct Magacin{
    int niza[MAX];
    int top;
    void init(){
        top = -1;
    }
    void push(int podatok);
    int pop();
    int peek();
    bool isEmpty(){
        return (top == -1);
    }
    void print(){
        cout<<"Pecatenje na redot > ";
        for(int i = top; i <= 0; i--){
            cout<<niza[i]<<" ";
        }
    }
};
void Magacin::push(int podatok){
    top++;
    niza[top] = podatok;
}
int Magacin::pop(){
    if(isEmpty()){
        cout<<"Magacinot e prazen."<<endl;
        exit(-1);
    }
    int pom = niza[top];
    top--; 
    return pom;
}
int Magacin::peek(){
    if(isEmpty()){
        cout<<"Magacinot e prazen."<<endl;
        exit(-1);
    }
    return niza[top];
}
int funk(Red &red1, Magacin &mag1){
    int brojac = 0;
    while(!red1.isEmpty()){
        mag1.push(red1.pull());
        if(red1.isEmpty()){
            break;
        }
        if(mag1.peek() != red1.peek()){
            brojac++;
            mag1.pop();
            red1.pull();
        }
    }
    return brojac;
}
int main(){
    Red masina;
    masina.init();
    Magacin kutija;
    kutija.init();
    int brojac = 0;

    int niza[] = {1,2,1,2,2,2,2,1,2};
    for(int i = 0; i<9; i++){
        masina.push(niza[i]);
    }
    cout<<"Sostojba na masina "<<endl<<"-----------------------"<<endl;
    masina.print();
    masina.pull();
    brojac = funk(masina, kutija);
    cout<<"Brojac > "<<brojac<<endl;
    return 0;
}