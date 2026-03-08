
#include <iostream> 
#include "Stack.h" 

using namespace std;

int main() {

    string infix = "(A + B) * (C - D) + E";

    cout << "Infix Expression:" << endl;
    cout << infix << endl;

    string postfix = infixToPostfix(infix);

    cout << endl;
    cout << "Postfix Expression:" << endl;
    cout << postfix << endl;

    // Part 3: Infix to Postfix steps 
    cout << endl;
    cout << "Infix to Postfix Steps:" << endl;
    cout << "(A + B) * (C - D) + E" << endl;
    cout << "A B + C D - * E +" << endl;

    string postfixEval = "5 2 3 * + 9 -";

    cout << endl;
    cout << "Postfix Expression for Evaluation:" << endl;
    cout << postfixEval << endl;

    int result = evalPostfix(postfixEval);

    // Part 3: Postfix evaluation steps 
    cout << endl;
    cout << "Postfix Evaluation Steps:" << endl;
    cout << "Push 5" << endl;
    cout << "Push 2" << endl;
    cout << "Push 3" << endl;
    cout << "2 * 3 = 6" << endl;
    cout << "5 + 6 = 11" << endl;
    cout << "Push 9" << endl;
    cout << "11 - 9 = 2" << endl;

    cout << endl;
    cout << "Evaluation Result:" << endl;
    cout << result << endl;

    return 0;
}