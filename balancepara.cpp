#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

int main(void) {
    char equation[20], currentChar, temp;
    cout<<"Enter a equation :"<<endl;
    cin>>equation;
    stack<char> Stack;
    int length = strlen(equation);
    for(int i=0; i<length; i++) {
        currentChar = equation[i];
        if(currentChar == '{' || currentChar == '[' || currentChar == '(') {
            Stack.push(currentChar);
            continue;
        }

        if(Stack.empty()) {
            cout<<"UNBALANCED";
            break;
        }

        switch(currentChar) {
            case ']':
                temp = Stack.top();
                Stack.pop();
                if(temp == '{' || temp == '(') {
                    cout<<"UNBALANCED"<<endl;
                    exit(0);
                }
                break;
            case ')':
                temp = Stack.top();
                Stack.pop();
                if(temp == '{' || temp == '[') {
                    cout<<"UNBALANCED"<<endl;
                    exit(0);
                }
                break;
            case '}':
                temp = Stack.top();
                Stack.pop();
                if(temp == '[' || temp == '(') {
                    cout<<"UNBALANCED"<<endl;
                    exit(0);
                }
                break;
        }
    }
    if(Stack.empty()) {
        cout<<"Balanced"<<endl;
    }
    return 0;
}