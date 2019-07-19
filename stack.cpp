#include <iostream>

using namespace std;

const int STACK_SIZE = 10;
int top = -1;
int stack[STACK_SIZE];


void push(int value) {
    if(top == STACK_SIZE-1) {
        cout<<"OVERFLOW"<<endl;
    } else {
        top += 1;
        stack[top] = value;
    }
}

int pop() {
    if(top == -1) {
        cout<<"UNDERFLOW"<<endl;
        return 0;
    } else {
        top -= 1;
        return stack[top+1];
    }
}

int peek() {
    if(top == -1) {
        cout<<"UNDERFLOW"<<endl;
        return 0;
    } else {
        return stack[top];
    }
}

bool isEmpty() {
    if(top == -1) {
        return true;
    } else {
        return false;
    }
}

void traverse() {
    if(top == -1) {
        cout<<"UNDERFLOW"<<endl;
    } else {
        for(int i=0; i<top+1; i++) {
            cout<<stack[i]<<" ";
        }
        cout<<endl;
    }
}



int main(void) {

    cout<<isEmpty()<<endl;
    cout<<peek()<<endl;
    cout<<pop()<<endl;
    push(10);
    push(20);
    traverse();
    cout<<isEmpty()<<endl;
    cout<<peek()<<endl;
    cout<<pop()<<endl;

    return 0;
}