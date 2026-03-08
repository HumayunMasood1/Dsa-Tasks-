#include "Stack.h" 
#include <iostream> 

Stack::Stack() {
    top = -1;
}

bool Stack::isEmpty() {
    return top == -1;
}

bool Stack::isFull() {
    return top == MAX - 1;
}

void Stack::push(char c) {
    if (!isFull())
        items[++top] = c;
}

char Stack::pop() {
    if (!isEmpty())
        return items[top--];
    return '\0';
}

char Stack::peek() {
    if (!isEmpty())
        return items[top];
    return '\0';
}

bool isOperand(char c) {
    return (c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z') ||
        (c >= '0' && c <= '9');
}

int prec(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string infixToPostfix(string infix) {

    Stack st;
    string result = "";

    for (int i = 0; i < infix.length(); i++) {

        char c = infix[i];

        if (c == ' ')
            continue;

        if (isOperand(c)) {
            result += c;
        }

        else if (c == '(') {
            st.push(c);
        }

        else if (c == ')') {

            while (!st.isEmpty() && st.peek() != '(')
                result += st.pop();

            st.pop();
        }

        else {

            while (!st.isEmpty() && prec(st.peek()) >= prec(c))
                result += st.pop();

            st.push(c);
        }
    }

    while (!st.isEmpty())
        result += st.pop();

    return result;
}

int evalPostfix(string postfix) {

    int stack[MAX];
    int top = -1;

    for (int i = 0; i < postfix.length(); i++) {

        char c = postfix[i];

        if (c == ' ')
            continue;

        if (c >= '0' && c <= '9') {
            stack[++top] = c - '0';
        }

        else {

            int b = stack[top--];
            int a = stack[top--];
            int result;

            if (c == '+') result = a + b;
            else if (c == '-') result = a - b;
            else if (c == '*') result = a * b;
            else if (c == '/') result = a / b;

            stack[++top] = result;
        }
    }

    return stack[top];
}