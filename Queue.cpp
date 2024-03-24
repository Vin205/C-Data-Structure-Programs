/*

Simulation of pizza parlor: Pizza parlor accepting maximum M orders.
Orders are served on a first come first served basis. Order once placed
cannot be canceled.
Write C++ program to simulate the system using simple queue or circular
queue
*/

#include <iostream>
using namespace std;
class Pizza
{
private:
    int front, rear, arr[4], size = 4;

public:
    Pizza()
    {
        front = -1;
        rear = -1;
    }
    bool isFull()
    {
        if (front == 0 && rear == size - 1 || front == rear + 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void addOrder()
    {
        if (!isFull())
        {
            int data;
            cout << "\tEnter Pizza ID :";
            cin >> data;
            if (front == -1 && rear == -1)
            {
                front = 0;
                rear = 0;
                arr[rear] = data;
            }
            else
            {
                rear = (rear + 1) % size;
                arr[rear] = data;
            }
            char c;
            cout << "\tDo you want to add another order ? Enter (y/n) : ";
            cin >> c;
            if (c == 'y' || c == 'Y')
                addOrder();
        }
        else
        {
            cout << "\tOrder full try Leater !!" << endl;
        }
    }

    int serveOrder()
    {
        if (!isEmpty())
        {
            if (front == rear)
            {
                cout << "\tOrder served is : " << arr[front] << endl;
                front = -1;
                rear = -1;
            }
            else
            {
                cout << "\tOrder served is : " << arr[front] << endl;
                front = (front + 1) % 5;
            }
        }
        else
        {
            cout << "\tOrders are empty (NO Order are available)" << endl;
        }
    }
    void countOrder()
    {
        cout << "\tOrder count is : " << rear - front + 1 << endl;
    }
    void Display()
    {
        for (int i = front; i <= rear; i++)
        {
            cout << "\tPizza ID NO. " << i+1 << " :" << arr[i] << endl;
        }
    }
    void placeOrder () {
        int choice;
    do
    {
        cout << "\n\t-----> Welcome to Pizza Parlour <------\n\n" << endl;
        cout << "\t0 -> For Exit . " << endl;
        cout << "\t1 -> For enter order ID . " << endl;
        cout << "\t2 -> For Serve Order ID . " << endl;
        cout << "\t3 -> For count of order ID." << endl;
        cout << "\t4 -> For Display all Order ID ." << endl;
        cout << "\t5 -> For clear screen ." << endl;
        cout << "\tEnter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 0 : 
            cout << "\n\n\t----- > Thanks For Vist <-----\n" << endl ;
            break;
        case 1:
            addOrder();
            break;
        case 2:
            serveOrder();
            break;
        case 3:
            countOrder();
            break;
        case 4:
            Display();
            break;
        case 5:
            system("cls");
            break;
        default:
            cout << "\t Enter valid No !!" << endl;
        }
    } while (choice != 0);
    }
};
int main()
{
    Pizza p1;
    p1.placeOrder();
    return 0; 
}

/*
                <<-- OUTPUT -->>
        -----> Welcome to Pizza Parlour <------


        0 -> For Exit . 
        1 -> For enter order ID . 
        2 -> For Serve Order ID . 
        3 -> For count of order ID.
        4 -> For Display all Order ID .
        5 -> For clear screen .
        Enter your choice : 1
        Enter Pizza ID :1111
        Do you want to add another order ? Enter (y/n) : y
        Enter Pizza ID :2222
        Do you want to add another order ? Enter (y/n) : y
        Enter Pizza ID :3333
        Do you want to add another order ? Enter (y/n) : n

        -----> Welcome to Pizza Parlour <------


        0 -> For Exit .
        1 -> For enter order ID .
        2 -> For Serve Order ID .
        3 -> For count of order ID.
        4 -> For Display all Order ID .
        5 -> For clear screen .
        Enter your choice : 2
        Order served is : 1111

        -----> Welcome to Pizza Parlour <------


        0 -> For Exit .
        1 -> For enter order ID .
        2 -> For Serve Order ID .
        3 -> For count of order ID.
        4 -> For Display all Order ID .
        5 -> For clear screen .
        Enter your choice : 2
        Order served is : 2222

        -----> Welcome to Pizza Parlour <------


        0 -> For Exit .
        1 -> For enter order ID .
        2 -> For Serve Order ID .
        3 -> For count of order ID.
        4 -> For Display all Order ID .
        5 -> For clear screen .
        Enter your choice : 3
        Order count is : 1

        -----> Welcome to Pizza Parlour <------


        0 -> For Exit .
        1 -> For enter order ID .
        2 -> For Serve Order ID .
        3 -> For count of order ID.
        4 -> For Display all Order ID .
        5 -> For clear screen .
        Enter your choice : 4
        Pizza ID NO. 3 :3333

        -----> Welcome to Pizza Parlour <------


        0 -> For Exit .
        1 -> For enter order ID .
        2 -> For Serve Order ID .
        3 -> For count of order ID.
        4 -> For Display all Order ID .
        5 -> For clear screen .
        Enter your choice : 0


        ----- > Thanks For Vist <-----
*/
