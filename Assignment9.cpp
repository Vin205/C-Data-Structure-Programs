/*
=====>>>>>> PROBLEM STATEMENT <<<<<<======
Sakshi Pramod Malpure,39A,Assignment-09
String operations: A palindrome is a string of characters that's identical
when read in forward and backward direction. Typically, punctuation,
capitalization, and spaces are ignored. For example, “1.Poor Dan is in a
droop!!” is a palindrome, as can be seen by examining the characters
“poordanisinadroop” and observing that they are identical when read
forward and backward directions. One way to check for a palindrome is to
reverse the characters in the string and compare them with the original-in a
palindrome, the sequence will be identical.
Write C++ program with functions using Standard Template Library (STL)
stack-
1. To print original string followed by reversed string using stack
2. To check whether given string is palindrome or not
*/

#include <iostream>
#include <string.h>
using namespace std;
class stack
{
private:
    int top;
    char arr[100];

public:
    stack()
    {
        top = -1;
    }

    bool isEmpty()
    {
        if (top == (-1))
            return true;
        else
        {
            return false;
        }
    }

    bool isFull()
    {
        if (top == 99)
            return true;
        else
        {
            return false;
        }
    }

    void push(char value)
    {
        if (isFull())
            cout << "stack overflow" << endl;
        else
        {
            top++;
            arr[top] = value;
        }
    }

    char pop()
    {
        if (isEmpty())
        {
            return '\0';
        }
        else
        {
            char popValue = arr[top];
            arr[top] = 0;
            top--;
            return popValue;
        }
    }

    char peek()
    {
        if (isEmpty())
        {
            return '\0';
        }
        else
        {
            return arr[top];
        }
    }
};

class StringOp
{
private:
    string str, compstr, revstr;

public:
    void EntStr()
    {
        cin.ignore();
        cout << "Enter string : ";
        getline(cin, str);
        for (int i = 0; str[i] != '\0'; i++)
        {
            if ((str[i] != ' ') && (str[i] != '!') && (str[i] != '?')&& (str[i] != '/') && (str[i] != '$')&& (str[i] != '#') && (str[i] != '@')&& (str[i] != '|') && (str[i] != '/'))
            {
                compstr += tolower(str[i]);
            }
        }
        OGStrRev();
    }
    void OGStrRev()
    {
        string temp;
        stack s1;
        for (int i = 0; str[i] != '\0'; i++)
        {
            s1.push(str[i]);
        }

        for (int i = 0; s1.peek() != '\0'; i++)
        {
            temp += s1.pop();
        }
        cout << "Reverse string is -->>" << temp << endl;
        StrRev();
    }
    void StrRev()
    {
        stack s1;
        for (int i = 0; compstr[i] != '\0'; i++)
        {
            s1.push(compstr[i]);
        }

        for (int i = 0; s1.peek() != '\0'; i++)
        {
            revstr += s1.pop();
        }
    }

    void IsPalindrome()
    {
        bool IsPale = true;
        for (int i = 0; i < compstr.length(); i++)
        {
            if (compstr[i] != revstr[i])
            {
                IsPale = false;
            }
        }

        if (IsPale)
        {
            cout << "Given string is Palindrome !!" << endl;
        }
        else
        {
            cout << "Given string is NOT Palindrome !!" << endl;
        }
    }
};

int main()
{
    int choice;
    StringOp r1;
    do
    {
        cout << "\n\n---------MENU---------" << endl;
        cout << "Enter 1: Enter string.\n";
        cout << "Enter 2: Reverse of given string. \n";
        cout << "Enter 3: Check string is Palindrome or not . \n";
        cout << "Enter 0: To Exit.  \n";
        cout << "\nEnter your choice :  ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            r1.EntStr();
            break;
        case 2:
            r1.OGStrRev();
            break;
        case 3:
            r1.IsPalindrome();
            break;

        case 0:
            exit(0);

        default:
            cout << endl
                 << "!!! Enter valid choice !!!" << endl;
            break;
        }

    } while (choice != 0);
}

/*
=========>>>>> OUTPUT <<<<<=======
---------MENU---------
Enter 1: Enter string.
Enter 2: Reverse of given string. 
Enter 3: Check string is Palindrome or not . 
Enter 0: To Exit.  

Enter your choice :  1
Enter string : Poor Dan is in a droop!!


---------MENU---------
Enter 1: Enter string.
Enter 2: Reverse of given string. 
Enter 3: Check string is Palindrome or not . 
Enter 0: To Exit.  

Enter your choice :  2
Reverse string is -->>!!poord a ni si naD rooP


---------MENU---------
Enter 1: Enter string.
Enter 2: Reverse of given string. 
Enter 3: Check string is Palindrome or not . 
Enter 0: To Exit.

Enter your choice :  3
Given string is Palindrome !!


---------MENU---------
Enter 1: Enter string.
Enter 2: Reverse of given string.
Enter 3: Check string is Palindrome or not .
Enter 0: To Exit.

Enter your choice :  0

*/
