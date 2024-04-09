// CPP Postfixc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    cout << "Enter a Postfix expression:" << endl;

    string expression;
    getline(cin, expression);
    stack<int> numberStack = stack<int>();

    for (int i = 0; i < expression.size(); i++) {
        while (expression[i] == ' ') {
            i++;

            if (i >= expression.size()) {
                break;
            }
        }

        if (expression[i] == '+') {
            if (numberStack.size() < 2) {
                cout << "Invalid postfix expression";
                return -1;
            }

            int numA = numberStack.top();
            numberStack.pop();
            int numB = numberStack.top();
            numberStack.pop();
            numberStack.push(numA + numB);

            continue;
        }

        if (expression[i] == '*') {
            if (numberStack.size() < 2) {
                cout << "Invalid postfix expression";
                return -1;
            }

            int numA = numberStack.top();
            numberStack.pop();
            int numB = numberStack.top();
            numberStack.pop();
            numberStack.push(numA * numB);

            continue;
        }

        int startChar = i;
        
        while (expression[i] != ' ') {
            i++;

            if (i >= expression.size()) {
                break;
            }

            if (expression[i] == '*' || expression[i] == '+') {
                cout << "Invalid postfix expression";
                return -1;
            }
        }

        numberStack.push(stoi(expression.substr(startChar, i)));
    }

    cout << "result: " << numberStack.top();
}