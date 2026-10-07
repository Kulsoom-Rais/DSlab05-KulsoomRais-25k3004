#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
private:
    stack<int> stackIn;
    stack<int> stackOut;

public:

    void enqueue(int item)
    {
        stackIn.push(item);
    }

    int dequeue()
    {
        
       
        if (stackOut.empty())
        {
            while (!stackIn.empty())
            {
                stackOut.push(stackIn.top());
                stackIn.pop();
            }
        }

        
        if (stackOut.empty())
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        int item = stackOut.top();
        stackOut.pop();

        return item;
    }
};

int main()
{
    MyQueue q;

    q.enqueue(1);   
    q.enqueue(2);   

    cout << "Dequeued: " << q.dequeue() << endl;

    q.enqueue(3);   

    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    return 0;
}
