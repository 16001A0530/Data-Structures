#include <iostream>
#include <stack>
#include <string.h>


int main(void) {
    char infixExpression[10], currentChar;
    int length, postfixCounter = -1;

    std::stack<char> stk;

    std::cin>>infixExpression;

    length = strlen(infixExpression);
    char postfixExpression[length];

    for(int i=0; i<length; i++) {
        currentChar = infixExpression[i];
        if(!(currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/')) {
            postfixExpression[++postfixCounter] = currentChar;
            continue;
        }
        if(stk.empty()) {
            stk.push(currentChar);
            continue;
        }
        if(currentChar == '*' || currentChar == '/') {
            if(stk.top() == '+' || stk.top() == '-') {
                stk.push(currentChar);
                continue;
            }
            postfixExpression[++postfixCounter] = stk.top();
            stk.pop();
            stk.push(currentChar);
        }
        if(currentChar == '-' || currentChar == '+') {
            if(stk.top() == '*' || stk.top() == '/') {
                postfixExpression[++postfixCounter] = stk.top();
                stk.pop();
                stk.push(currentChar);
                continue;
            }  
            postfixExpression[++postfixCounter] = stk.top();
            stk.pop();
            stk.push(currentChar);
        }
    }

    if(!stk.empty()) {
        while(!stk.empty()) {
            postfixExpression[++postfixCounter] = stk.top();
            stk.pop();
        }
    }

    std::cout<<strlen(postfixExpression)<<std::endl;

    return 0;
}