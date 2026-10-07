#include <iostream>
using namespace std;

class Stack
{
private:
    int arr[8];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(int value)
    {
        if (top == 7)
        {
            cout << "Stack is full!" << endl;
            return;
        }

        top++;
        arr[top] = value;

        cout << "Current top: " << arr[top] << endl;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Undo requested, but stack is empty!" << endl;
            return;
        }

        top--;

        if (top == -1)
            cout << "Current top: Stack is empty" << endl;
        else
            cout << "Current top: " << arr[top] << endl;
    }

    void display()
    {
        if (top == -1)
        {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "\nOperations remaining in stack (top to bottom): ";

        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    Stack s;

    
    s.push(12);
    s.push(25);
    s.push(17);
    s.push(31);
    s.push(44);
    s.push(19);


    cout << "\nUndo 1:" << endl;
    s.pop();

    cout << "Undo 2:" << endl;
    s.pop();

    cout << "Undo 3:" << endl;
    s.pop();


    cout << "\nNew operation 52:" << endl;
    s.push(52);

 
    cout << "\nUndo 1:" << endl;
    s.pop();

    cout << "Undo 2:" << endl;
    s.pop();

  
    s.display();

    return 0;
}
