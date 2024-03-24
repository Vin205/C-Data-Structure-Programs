/*Assignment-09,Sakshi Pramod Malpure,39A
Expression conversion: Write a menu driven C++ program for expression
conversion and evaluation
1. infix to prefix
2. prefix to postfix
3. prefix to infix
4. postfix to infix
5. postfix to prefix
*/
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int getPrecedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

bool isEmpty(stack<char>& s) {
    return s.empty();
}

string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    for (char& ch : infix) {
        if (isalnum(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            while (!isEmpty(s) && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        } else {
            while (!isEmpty(s) && getPrecedence(s.top()) >= getPrecedence(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    while (!isEmpty(s)) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());

    for (char& ch : infix) {
        if (ch == '(') ch = ')';
        else if (ch == ')') ch = '(';
    }

    string postfix = infixToPostfix(infix);

    reverse(postfix.begin(), postfix.end());

    return postfix;
}

// Prefix to Postfix conversion
string prefixToPostfix(string prefix) {
    stack<string> s;

    for (int i = prefix.size() - 1; i >= 0; --i) {
        if (isalnum(prefix[i])) {
            s.push(string(1, prefix[i]));
        } else {
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();
            s.push(op1 + op2 + prefix[i]);
        }
    }

    return s.top();
}

// Prefix to Infix conversion
string prefixToInfix(string prefix) {
    stack<string> s;

    for (int i = prefix.size() - 1; i >= 0; --i) {
        if (isalnum(prefix[i])) {
            s.push(string(1, prefix[i]));
        } else {
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();
            s.push("(" + op1 + prefix[i] + op2 + ")");
        }
    }

    return s.top();
}

// Postfix to Infix conversion
string postfixToInfix(string postfix) {
    stack<string> s;

    for (char& ch : postfix) {
        if (isalnum(ch)) {
            s.push(string(1, ch));
        } else {
            string op2 = s.top(); s.pop();
            string op1 = s.top(); s.pop();
            s.push("(" + op1 + ch + op2 + ")");
        }
    }

    return s.top();
}

// Postfix to Prefix conversion
string postfixToPrefix(string postfix) {
    stack<string> s;

    for (char& ch : postfix) {
        if (isalnum(ch)) {
            s.push(string(1, ch));
        } else {
            string op2 = s.top(); s.pop();
            string op1 = s.top(); s.pop();
            s.push(ch + op1 + op2);
        }
    }

    return s.top();
}

int main() {
    int choice;
    char c;
    string expression;

    cout << "Enter the expression: ";
    getline(cin, expression);
do{
    cout << "\n1. Infix to Prefix\n2. Prefix to Postfix\n3. Prefix to Infix\n4. Postfix to Infix\n5. Postfix to Prefix\n6. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Infix to Prefix: " << infixToPrefix(expression);
            break;
        case 2:
            cout << "Prefix to Postfix: " << prefixToPostfix(expression);
            break;
        case 3:
            cout << "Prefix to Infix: " << prefixToInfix(expression);
            break;
        case 4:
            cout << "Postfix to Infix: " << postfixToInfix(expression);
            break;
        case 5:
            cout << "Postfix to Prefix: " << postfixToPrefix(expression);
            break;
        case 6:
        	return 0;
        default:
            cout << "Invalid choice!";
    }
    cout<<"\n Do you want to continue?: ";
    cin>>c;
}while(c ='Y');
    return 0;
}
/*Output

Enter the expression: 2+6(5*3)/9# 

1. Infix to Prefix
2. Prefix to Postfix
3. Prefix to Infix
4. Postfix to Infix
5. Postfix to Prefix
Enter your choice: 1
Infix to Prefix: #+2/6*539*/

