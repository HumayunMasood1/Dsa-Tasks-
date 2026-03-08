#pragma once 
#include <string> 
using namespace std;

const int MAX = 100;

class Stack {
    char items[MAX];
    int top;

public:
    Stack();
    bool isEmpty();
    bool isFull();
    void push(char);
    char pop();
    char peek();
};

bool isOperand(char);
int prec(char);

string infixToPostfix(string);
int evalPostfix(string);