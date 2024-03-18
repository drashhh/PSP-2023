#include <iostream>
#define MAX 100
using namespace std;
struct Element{
    int podatok;

};
struct Red{
    Element niza[MAX];
    int napred, nazad;
    void init();
    bool isEmpty();
    bool isFull();
    void stavi(Element e);
    Element izvadi();
    Element peek();
};
void Red::init(){
    napred = 0;
    nazad = -1;
}
bool Red::isEmpty(){
    return (nazad == -1);
}
bool Red::isFull(){
    return (nazad == MAX-1);
}
void Red::stavi(Element e){
    if(isFull()){
        cout<<"Redot e poln"<<endl;
        exit(-1);
    }
    niza[++nazad] = e;
}
Element Red::izvadi(){
    if(isEmpty()){
        cout<<"Redot e prazen!"<<endl;
        exit(-1);
    }
    Element pom = niza[napred];
    for(int i = napred; i < nazad; i++){
        niza[i] = niza[i+1];
    }

    nazad--;
    return pom;
}
Element Red::peek(){
    if(isEmpty()){
        cout<<"Redot e prazen!"<<endl;
        exit(-1);
    }
    return niza[napred];
}
Element najdiElementNaPoz(Red red, int poz){
    while(--poz){
        red.izvadi();
    }
    return red.peek();
}
void proveri(Red &red1, Red &red2){
    Red novRed;
    novRed.init();
    while(!red2.isEmpty()){
        novRed.stavi(najdiElementNaPoz(red1, red2.izvadi().podatok));
    }
    while(!novRed.isEmpty()){
        cout<< novRed.izvadi().podatok<<endl;
    }
}
int main(){
    Red r1, r2;
    r1.init();
    r2.init();
    int a[6] = {5, 8, 3, 1, 4, 9};
    for(int i = 0; i < 6; i++){
        Element e;
        e.podatok = a[i];
        r1.stavi(e);
    }
    while(!r1.isEmpty()){
        cout << r1.izvadi().podatok <<endl;
    }
    for(int i = 0; i < 6; i++){
        Element e;
        e.podatok = a[i];
        r1.stavi(e);
    }
    return 0;
}