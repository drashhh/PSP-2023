#include <iostream>
#define MAX 30
using namespace std;
struct Magacin{
    string Niza[MAX];
    string pop();
    string peek();
    int top;
    void put(string el);
    void init();
    bool isEmpty();


};
void Magacin::init(){
    top = -1;
}
void Magacin::put(string el){
    top++;
    Niza[top] = el;
}
string Magacin::peek(){
    return Niza[top];
}
string Magacin::pop(){
    int temp = top;
    top--;
    return Niza[temp];
}
bool Magacin::isEmpty(){
    return top<0;
}


int main(){
    Magacin lenta;
    lenta.init();
    string vlez[9] = {{"leva"}, {"desna"},  {"leva"}, {"desna"}, {"leva"}, {"desna"}, {"desna"}, {"leva"}, {"desna"}};
    for(int i = 0; i < 9; i++){
        lenta.put(vlez[i]);
    }

    int brojac = 0;
    string temp;
    while(!lenta.isEmpty()){
        temp = lenta.pop();
        if(temp != lenta.peek()){
            brojac++;
        }
        lenta.pop();
    }
    cout<<brojac<<endl;
    return 0;
}