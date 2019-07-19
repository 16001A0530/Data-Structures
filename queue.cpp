#include <iostream>
using namespace std;
const int MAX_VALUE = 100;

int front = -1;
int rear = -1;
int queue[MAX_VALUE];

void enqueue(int value) {
    if(rear == MAX_VALUE-1) {
        cout<<"Queue if FULL"<<endl;
        return;
    }
    if(front == -1){
        front++;
    }
    queue[++rear] = value;
}

void dequeue() {
    if(rear == front == -1) {
        cout<<"Queue is EMPTY"<<endl;
        return;
    }
    if(rear == front) {
        front == rear == -1;
        return;
    }
    rear--;

}
int peek() {
    if(rear == front == -1) {
        cout<<"Queue is EMPTY"<<endl;
        return 0;
    } else {
        return queue[front];
    }
}
void display() {
    if(front == rear == -1){
        return;
    }
    for(int i=front; i<rear+1; i++) {
        cout<<queue[i]<<"  ";
    }
}
