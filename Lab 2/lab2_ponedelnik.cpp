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
void interval(int broj1, int broj2, magacin &m1){
    magacin pomoshen;
    pomoshen.init();
    if(broj1 > broj2){
        int temp = broj1;
        broj1 = broj2;
        broj2 = temp;
    }
    while(!m1.isEmpty()){
        int vred = m1.peek();
        //cout<<"Vrednost "<<vred<<endl;
        if(broj1 <= vred && broj2 >= vred){
            pomoshen.push(m1.pop());
        }else{
            m1.pop();
        }
    }
    m1.init();
    while(!pomoshen.isEmpty()){
        m1.push(pomoshen.pop());
    }
}
int main(){
    magacin m1;
    int broj, vrednost, br1, br2;
    m1.init();

    cout<<"Kolku elementi sakas vo prviot magacin?"<<endl;
    cin>>broj;
    cout<<"Pocni so vnesuvanje na magacin > ";
    for(int i=0; i<broj; i++){
        cin>>vrednost;
        m1.push(vrednost);
    }

    cout<<"Vnesi go prviot broj > "; cin>>br1;
    cout<<"Vnesi go vtoriot broj > "; cin>>br2;
    interval(br1, br2, m1);

    cout<<"Elementi od magacinot koi se vo interval od "<<br1<<" do "<<br2<<" > ";
    while(!m1.isEmpty()){
        cout<<m1.pop()<<" ";
    }
    cout<<endl;
    return 0;
}