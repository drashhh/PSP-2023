#include <iostream>
using namespace std;
struct Magacin{
    char niza[30];
    int top;
    void init(){
        top = -1;
    }
    void put(char c);
    char peek();
    char pop();
    void pecati();
    bool ePrazna(){
        return (top == -1);
    }
};
void Magacin::put(char c){
    if(top >= 29){
        cout<<"nizata e polna!"<<endl;
        exit(-1);
    }
    niza[++top] = c;
}
char Magacin::peek(){
    if(top < 0){
        cout<<"nizata e prazna!"<<endl;
        exit(-1);
    }
    return niza[top];
}
char Magacin::pop(){
    if(top < 0){
        cout<<"nizata e prazna!"<<endl;
        exit(-1);
    }
    char temp = niza[top];
    top--;
    return temp;
}
void Magacin::pecati(){
    cout<<"Pecatenje na magacinot > ";
    for(int i = 0; i <= top; i++){
        cout<<niza[i]<<" ";
    }
    cout<<endl;
}
int funk(Magacin &m1, char bukva){
    Magacin pomosen;
    int pomoshna = -1, zname = 0;
    pomosen.init();
    char pomos = bukva;
    while(!m1.ePrazna()){
        if(m1.peek() == pomos && zname == 0){
            m1.pop();
            zname = 1;
        }else{
            pomosen.put(m1.pop());
        }
    }
    while(!pomosen.ePrazna()){
        m1.put(pomosen.pop());
    }
    return pomoshna;
}
int main(){
    Magacin bukvi;
    bukvi.init();
    char bukva;
    char nizaBukvi[] = {'e', 'b', 'a', 'd', 'r', 'a', 'g'};
    for(int i = 0; i < 7; i++){
        bukvi.put(nizaBukvi[i]);
    }
    bukvi.pecati();
    cout<<"Vnesi ja bukva koja sakas da ja trgnes > "; cin>>bukva;
    cout<<"Bukvata vnesena e > "<<bukva<<endl;
    int indeks;
    indeks = funk(bukvi, bukva);

    cout<<"Bukvata" << bukva << " e trgnata od magacinot!"<<endl;
    bukvi.pecati();
    return 0;
}