#include <iostream>
using namespace std;
struct Red{
    int Clen[30];
    int napred, nazad;
    void init();
    void put(int broj);
    int peek();
    int pull();
    bool isEmpty();
    bool isFull();
};
void Red::init(){
    napred = nazad = -1;
}
void Red::put(int broj){
    if(nazad >= 29){
        cout<<"Previse clenovi!"<<endl;
        exit(-1);
    }
    if(napred == -1){
        napred = 0;
    }
    Clen[++nazad] = broj;
}
int Red::pull(){
    int temp;
    if(napred == -1){
        cout<<"Premalce clenovi! u pull"<<endl;
        exit(-1);
    }else{
        temp = Clen[napred];
        if(napred == nazad){
            napred = nazad = -1;
        }else napred++;
    }
    return temp;
}
int Red::peek(){
    int temp;
    if(napred == -1){
        cout<<"Premalce clenovi! u peek"<<endl;
        exit(-1);
    }else{
        temp = Clen[napred];
    }
    return temp;
}
bool Red::isEmpty(){
    return (nazad == -1);
}
bool Red::isFull(){
    return (napred == 29);
}
void funk(Red &red){
    Red pomoshen;
    pomoshen.init();
    int broj1, broj2;
    while(!red.isEmpty()){
        pomoshen.put(red.pull());
    }
    while(!pomoshen.isEmpty()){
        broj1 = pomoshen.pull();
        if(pomoshen.isEmpty()) break;
        broj2 = pomoshen.peek();
        red.put(broj1-broj2);
    }
}
int main(){
    Red r;
    r.init();
    int i,broj, element;
    cout<<"Kolku elementi da ima redot > ";
    cin>>broj;
    cout<<"Pocni so vnesuvanje na elementite > ";
    for(i =0; i<broj; i++){
        cin>>element;
        r.put(element);
    }

    funk(r);

    while(!r.isEmpty()){
        cout<<r.pull()<<" ";
    }
}