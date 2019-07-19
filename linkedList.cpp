#include <iostream>
using namespace std;

struct  Node {
    int data;
    Node* link;
};

//head always points to first node
//don't modify head
Node* head, myTemp;


// function declarations
Node* newNode(int data);
int insertAtNthPosition(int data, int position);
int insertAtBegin(int data);
int insertAtEnd(int data);
bool deleteAtNthPosition(int position);
void traversal();
void recursiveTraversal(Node* Htemp);
void reverseList(Node* Htemp);
Node* iterativeRevList(Node* Htemp);


//main function
int main(void) {

    head = NULL;

    for(int i=0; i<10; i++) {
        insertAtBegin(i);
    }
    traversal();
    cout<<endl;
    iterativeRevList(head);
    traversal();
    cout<<endl;
    return 0;
}

Node* newNode(int data) {
    Node* myNewNode = new Node;
    myNewNode->data = data;
    myNewNode->link = NULL;
    return myNewNode;
}

int insertAtEnd(int data) {
    Node* tempNewNode = new Node;
    tempNewNode = head;
    if(head == NULL) {
        head = newNode(data);
        return data;
    } else {
        while(tempNewNode != NULL) {
            tempNewNode = tempNewNode->link;
        }
        tempNewNode = newNode(data);
        return data;
    }
}

int insertAtBegin(int data) {
    Node* tempNewNode = new Node;
    tempNewNode = newNode(data);
    tempNewNode->link = head;
    head = tempNewNode;
    return data;
}


void traversal() {
    Node* tempNewNode = new Node;
    tempNewNode = head;
    while(tempNewNode != NULL) {
        cout<<tempNewNode->data<<"  ";
        tempNewNode = tempNewNode->link;
    }
}


int insertAtNthPosition(int data, int position) {
    if(position == 1) {
        return insertAtBegin(data);
    } else {
        Node* tempNewNode = new Node;
        Node* temp = new Node;
        temp = head;
        tempNewNode = newNode(data);
        for(int i=0; i<position-2; i++) {
            temp = temp->link;
        }
        tempNewNode->link = temp->link;
        temp->link = tempNewNode;
        return data;
    }
}

bool deleteAtNthPosition(int position) {
    if(position == 1) {
        Node* temp = head;
        head = temp->link;
        delete temp;
    } else{
        Node* Htemp = new Node;
        Node* Dtemp = new Node;
        int value;
        Htemp = head;
        for(int i=0; i<position-2; i++) {
            Htemp = Htemp->link;
        }
        Dtemp = Htemp->link;
        Htemp->link = Dtemp->link;
        value = Dtemp->data;
        delete Dtemp;
        return true;
    }
    return false;
}


void recursiveTraversal(Node* Htemp) {
    if(Htemp != NULL) {
        recursiveTraversal(Htemp->link);
        cout<<Htemp->data<<" ";
    } else {
        return;
    }

}

void reverseList(Node* Htemp) {
    if(Htemp != NULL) {
        reverseList(Htemp->link);
        Node* nextNode = new Node;
        nextNode = Htemp->link;
        nextNode->link = Htemp;
        Htemp->link = NULL;
    } else {
        return;
    }
}


Node* iterativeRevList(Node* head){
    Node *current, *prev, *next;
    current = head;
    prev = NULL;

    while(current != NULL) {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }

    head = prev;
    return head;
}