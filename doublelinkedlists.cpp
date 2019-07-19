#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Global variable
Node* head;

Node* getNewNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void insertAtHead(int value) {
    Node* newNode = getNewNode(value);
    if(head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}


void insertAtTail(int value) {
    Node* temp = head;
    Node* newNode = getNewNode(value);
    if(head == NULL) {
        head = newNode;
    } else {
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}


void insertAtNthPosition(int value, int position) {
    Node* temp = head;
    Node* newNode = getNewNode(value);
    if(head == NULL) {
        head = newNode;
    } else {
        if(position == 1) {
            insertAtHead(value);
            return;
        }
        for(int i=0; i<position-2; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = (newNode->next)->prev;
        (newNode->next)->prev = newNode;
        temp->next = newNode;
    }
}


void deleteAtHead() {
    Node* temp = head;
    if(head == NULL) {
        return;
    } else if(head->next == NULL){
        head = NULL;
        delete head;
    }else {
        head = head->next;
        head->prev = NULL;
        delete temp;
    }
}

void deleteAtTail() {
    Node* temp = head;
    if(head == NULL) {
        return;
    } else if(head->next == NULL){
        head = NULL;
        delete head;
    }else {
        while(temp->next != NULL) {
            temp = temp->next;
        }
        (temp->prev)->next = NULL;
        delete temp;
    }
}

void deleteAtNthPosition(int position) {
    Node* Htemp = head;
    Node *Dtemp;
    if(position == 1) {
        deleteAtHead();
    } else {
        for(int i=0; i<position-2; i++) {
            Htemp = Htemp->next;
        }
        Dtemp = Htemp->next;
        Htemp->next = Dtemp->next;
        (Htemp->next)->prev = Dtemp->prev;
        delete Dtemp;       
    }

}

void forwardTraversal() {
    Node* temp = head;
    if(temp == NULL) {
        return;
    }
    cout<<"\nForward Traversal :"<<endl;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void reverseTraversal() { 
    Node* temp = head;
    if(temp == NULL) {
        return;
    }
    cout<<"\nReverse Traversal :"<<endl;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->prev;
    }
}

int main(void) {
    head = NULL;
    for(int i=0; i<10; i++) {
        insertAtTail(i+1);
    }
    forwardTraversal();
    deleteAtNthPosition(3);
    forwardTraversal();
    return 0;
}