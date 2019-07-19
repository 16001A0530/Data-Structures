#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* top;

Node* getNewNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void push(int value) {
    Node* newNode = getNewNode(value);
    if(top == NULL) {
        top = newNode;
    } else {
        newNode->next = top;
        top = newNode;
    }
}
void pop() {
    Node* temp = top;
    if(top == NULL) {
        return;
    } else {
        top = top->next;
        delete temp;
    }
}
int peek() {
    if(top == NULL) {
        return 0;
    } else {
        return top->data;
    }
}

void display() {
    Node* temp = top;
    if(top == NULL) {
        return;
    } else {
        while(temp != NULL) {
            cout<<temp->data<<"  ";
            temp = temp->next;
        }
        cout<<endl;
    }
}

int main(void) {
    for(int i=0; i<10; i++) {
        push(i+1);
    }
    display();
    pop();
    display();
    cout<<peek()<<endl;
    pop();
    display();

}
