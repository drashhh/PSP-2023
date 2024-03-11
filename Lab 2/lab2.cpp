#include <iostream>
#define MAX 30
using namespace std;

struct magacin{
    int M[MAX];
    int top;
    void init();
    void push(int vrednost);
    int peek();
    int pop();
    bool isEmpty();
    bool isFull();
};
void magacin::init(){
    top = -1;
}
void magacin::push(int vrednost){
    if(top>=MAX-1){
        cout<<"Previse clenovi!"<<endl;
        exit(-1);
    }
    top++;
    M[top] = vrednost;
}
int magacin::peek(){
    if(top<0){
        cout<<"Nema clenovi!"<<endl;
        exit(-1);
    }
    return M[top];
}
int magacin::pop(){
    if(top<0){
        cout<<"Nema clenovi! u pop"<<endl;
        exit(-1);
    }
    int temp = top;
    top--;
    return M[temp];
}
bool magacin::isEmpty(){
    return top<0;
}
bool magacin::isFull(){
    return top>MAX-1;
}
void func(magacin &m1, magacin &m2){
    magacin pomoshen;
    pomoshen.init();
    while(!m1.isEmpty()){
        int vred = m1.pop();
        if(vred == m2.peek()){
            m2.pop();
            pomoshen.push(vred);
        }
    } 
    while(!pomoshen.isEmpty()){
        int temp = pomoshen.pop();
        m1.push(temp);
    }
}
int main(){
    magacin m1, m2;
    int broj, vrednost;
    m1.init(); m2.init();

    cout<<"Kolku elementi sakas vo prviot magacin?"<<endl;
    cin>>broj;
    cout<<"Pocni so vnesuvanje na prviot magacin > ";
    for(int i=0; i<broj; i++){
        cin>>vrednost;
        m1.push(vrednost);
    }

    cout<<"Kolku elementi sakas vo vtoriot magacin?"<<endl;
    cin>>broj;
    cout<<"Pocni so vnesuvanje na vtoriot magacin > ";
    for(int i=0; i<broj; i++){
        cin>>vrednost;
        m2.push(vrednost);
    }
    
    func(m1, m2);

    cout<<"Pecatenje na prviot magacin > ";
    while(!m1.isEmpty()){
        cout<<m1.pop()<<" ";
    }
    cout<<endl<<"Pecatenje na vtoriot magacin > ";
    while(!m2.isEmpty()){
        cout<<m2.pop()<<" ";
    }
    cout<<endl;
    return 0;
}