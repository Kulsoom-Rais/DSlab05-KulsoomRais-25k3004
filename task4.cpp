#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int arr[6];
    int front;
    int rear;
    int count;

public:
    CircularQueue()
    {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isFull()
    {
        return count == 6;
    }

    bool isEmpty()
    {
        return count == 0;
    }

    void enqueue(int id)
    {
        if (isFull())
        {
            cout << "Queue is full. Passenger " << id << " cannot enter.\n";
            return;
        }

        rear = (rear + 1) % 6;
        arr[rear] = id;
        count++;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return -1;
        }

        int id = arr[front];

        front = (front + 1) % 6;
        count--;

        
        if (count == 0)
        {
            front = 0;
            rear = -1;
        }

        return id;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Final passengers in boarding order: ";

        int index = front;

        for (int i = 0; i < count; i++)
        {
            cout << arr[index] << " ";
            index = (index + 1) % 6;
        }

        cout << endl;
        cout << "Final front position: " << front << endl;
        cout << "Final rear position: " << rear << endl;
    }
};

int main()
{
    CircularQueue q;

    
    q.enqueue(101);
    q.enqueue(102);
    q.enqueue(103);
    q.enqueue(104);
    q.enqueue(105);
    q.enqueue(106);

    
    cout << "Boarded: " << q.dequeue() << endl;
    cout << "Boarded: " << q.dequeue() << endl;
    cout << "Boarded: " << q.dequeue() << endl;

    
    q.enqueue(107);
    q.enqueue(108);
    q.enqueue(109);

    
    cout << "Boarded: " << q.dequeue() << endl;
    cout << "Boarded: " << q.dequeue() << endl;

   
    q.enqueue(110);

  
    cout << "Boarded: " << q.dequeue() << endl;

 
    q.enqueue(111);
    q.enqueue(112);

    cout << "\n";
    q.display();

    return 0;
}
