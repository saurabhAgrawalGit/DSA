//implement stack using array
#include <iostream>
#define MAX 10
using namespace std;

class stack
{
public:
    int stack[MAX];
    int top = -1;

    void push(int data)
    {
        if (top == MAX - 1)
        {
            cout << "stack is full \n";
        }

        else
        {
            stack[++top] = data;
        }
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "stack is empty\n";
        }

        else
        {
            cout << "remove " << stack[top] << "\n";
            top--;
        }
    }
    void display()
    {
        if (top == -1)
        {
            cout << "stack is empty\n";
        }
        else
        {
            int i = top;
            while (i >= 0)
            {
                cout << stack[i] << " ";
                i--;
            }
            cout << endl;
        }
    }
};
int main()
{
    stack ob;
    int choice = 1, x;
    while (choice < 4 && choice != 0) // while loop
    {
        cout << "\nPress 1: Insert an element";
        cout << "\nPress 2: Delete an element";
        cout << "\nPress 3: Display the element";
        cout << "\nPress 0: Exit";
        cout << "\nEnter your choice ";
        cin >> choice;

        switch (choice)
        {

        case 1:

            cout << "Enter the element which is to be inserted ";
            cin >> x;
            ob.push(x);
            break;
        case 2:
            ob.pop();
            break;
        case 3:
            ob.display();
            break;
        }
    }
}
