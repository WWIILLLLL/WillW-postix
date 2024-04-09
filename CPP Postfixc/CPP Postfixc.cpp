// CPP Postfixc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int DoPostfix(string expressionStart) {
    bool founde = false;
    int expressionLength = 0;
    string expression = expressionStart;

    while (expression[expressionLength] != '=') {
        for (int i = expressionLength; i < expression.size(); i++) {
            if (expression[i] == '=') {
                expressionLength = i;
                founde = true;
                break;
            }
        }

        if (founde) break;

        expressionLength = expression.size();
        string tempExpression;
        getline(cin, tempExpression);
        expression += " " + tempExpression;
    }

    expression = expression.substr(0, expressionLength);

    cout << expression << endl;

    stack<int> numberStack = stack<int>();

    bool endEarly = false;
    for (int i = 0; i < expression.size(); i++) {
        while (expression[i] == ' ') {
            i++;

            if (i >= expression.size()) {
                endEarly = true;
                break;
            }
        }

        if (endEarly) break;

        if (expression[i] == '+') {
            if (numberStack.size() < 2) {
                cout << "Invalid postfix expression" << endl;
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
                cout << "Invalid postfix expression" << endl;
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
                cout << "Invalid postfix expression" << endl;
                return -1;
            }
        }

        numberStack.push(stoi(expression.substr(startChar, i - startChar)));
    }

    if (numberStack.size() > 1) {
        cout << "Invalid postfix expression" << endl;
        return -1;
    }
    else {
        cout << "The result is: " << numberStack.top() << endl;
    }
}

int main()
{
    cout << "Please type in a PostFix expressions (ending with =): " << endl;
    string input;
    getline(cin, input);

    while (input[0] != 'q') {
        int res = DoPostfix(input);

        cout << "Please type in a PostFix expressions (ending with =): " << endl;
        getline(cin, input);
    }
}