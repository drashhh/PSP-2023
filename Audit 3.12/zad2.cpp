#include <iostream>
using namespace std;
#define MAX 100
struct element
{
    string prezime;
    int brIndex;
    string ispit;
    int brPoeni;
};
struct Queue{
    element niza[MAX];
    int front, rear;
    void init();
    void enqueue(element e);
    bool isEmpty();
    bool isFull();
    element dequeue();
    element peek();
};
void Queue::init(){
    front = 0;
    rear = -1;
}
bool Queue::isEmpty(){
    return (rear == -1);
}
bool Queue::isFull(){
    return (rear == MAX -1);
}

int main(){
    
}