// Name : Tanushka Patil
// Prn No. : 123B1B036

#include <iostream>
#include <algorithm>  // For reverse function
using namespace std;

// Stack class definition (as per your original structure, you can expand it as needed)
class Stack {
    char arr[100]; // To store characters (operators and parentheses)
    int top;

public:
    Stack() {
        top = -1;
    }

    // Push an element to the stack
    void push(char x) {
        arr[++top] = x;
    }

    // Pop an element from the stack
    char pop() {
        if (top == -1) {
            return '\0'; // Return null character if stack is empty
        }
        return arr[top--];
    }

    // Peek the top element of the stack
    char peek() {
        if (top == -1) {
            return '\0'; // Return null character if stack is empty
        }
        return arr[top];
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }
};

// Helper functions to complete your code

// Check if a character is an operand (digit)
bool isOperand(char ch) {
    return (ch >= '0' && ch <= '9'); // You can extend this to letters if needed
}

// Function to define precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Function to convert infix to postfix (based on your original code)
void postfix(string exp) {
    Stack myStack;
    string PostfixExp = "";
    int i = 0;

    while (exp[i] != '\0') {
        if (exp[i] == '(') {
            myStack.push(exp[i]);
        }
        else if (exp[i] == ')') {
            while (myStack.peek() != '(') {
                PostfixExp += myStack.pop();
            }
            myStack.pop();  // Remove '(' from the stack
        }
        else if (isOperand(exp[i])) {
            PostfixExp += exp[i];  // Append operand to postfix expression
        }
        else {  // Operator case
            while (!myStack.isEmpty() && myStack.peek() != '(' && precedence(exp[i]) <= precedence(myStack.peek())) {
                PostfixExp += myStack.pop();
            }
            myStack.push(exp[i]);
        }
        i++;
    }

    // Pop remaining operators from the stack
    while (!myStack.isEmpty()) {
        PostfixExp += myStack.pop();
    }

    cout << "Postfix Expression: " << PostfixExp << endl;
}

// Function to convert infix to prefix (based on your original structure)
void prefix(string exp) {
    // Step 1: Reverse the infix expression
    reverse(exp.begin(), exp.end());

    // Step 2: Replace '(' with ')' and vice versa
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == '(') {
            exp[i] = ')';
        }
        else if (exp[i] == ')') {
            exp[i] = '(';
        }
    }

    // Step 3: Get the postfix expression of the modified infix expression
    Stack myStack;
    string PostfixExp = "";
    int i = 0;

    while (exp[i] != '\0') {
        if (exp[i] == '(') {
            myStack.push(exp[i]);
        }
        else if (exp[i] == ')') {
            while (myStack.peek() != '(') {
                PostfixExp += myStack.pop();
            }
            myStack.pop();  // Remove '(' from the stack
        }
        else if (isOperand(exp[i])) {
            PostfixExp += exp[i];  // Append operand to postfix expression
        }
        else {  // Operator case
            while (!myStack.isEmpty() && myStack.peek() != '(' && precedence(exp[i]) <= precedence(myStack.peek())) {
                PostfixExp += myStack.pop();
            }
            myStack.push(exp[i]);
        }
        i++;
    }

    // Pop remaining operators from the stack
    while (!myStack.isEmpty()) {
        PostfixExp += myStack.pop();
    }

    // Step 4: Reverse the postfix expression to get the prefix expression
    reverse(PostfixExp.begin(), PostfixExp.end());

    cout << "Prefix Expression: " << PostfixExp << endl;
}

int main() {
    string infixExp;
    cout << "Enter Infix Expression: ";
    cin >> infixExp;

    // Convert infix to postfix
    postfix(infixExp);

    // Convert infix to prefix
    prefix(infixExp);

    return 0;
}
