#include <iostream>
using namespace std;

class Queue
{
private:
    int arr[6];
    int front;
    int rear;
    int size;

public:
    Queue()
    {
        front = -1;
        rear = -1;
        size = 6;
        for (int i=0; i<size; i++)
        {
            arr[i] = 0;
        }
    }

    bool isFull()
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void enqueue(int data)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }

        if (front == -1)
        {
            front = rear = 0;
            arr[rear] = data;
        }
        else if ((rear == size - 1) && (front != 0))
        {
            rear = 0;
            arr[rear] = data;
        }
        else
        {
            rear++;
            arr[rear] = data;
        }
    }
    bool isEmpty()
    {
        if (front == -1)
        {
            cout << "Queue is empty " << endl;
            return true;
        }
        else
        {
            return false;
        }
    }
    void deque()
    {
        if (isEmpty())
        {
            cout << "Queue is empty " << endl;
            return;
        }
        int ans = arr[front];
        arr[front] = -1;
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
    // void show()
    // {
    //     for (int i = front; i = rear + 1; i = ((i + 1) % size))
    //     {
    //         cout << arr[i%size] << " ";
    //     }
    //     cout << endl;
    // }
    void show()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout<<endl;
    }
};
int main()
{
    Queue q;
    q.enqueue(8);
    q.show();
    q.enqueue(25);
    q.show();
    q.enqueue(23);
    q.show();
    q.enqueue(28);
    q.show();
    q.deque();
    q.show();
    q.deque();
    q.show();
    q.deque();
    q.show();
    q.enqueue(38);
    q.show();
    q.enqueue(98);
    q.show();
    q.enqueue(12);
    q.show();
    q.enqueue(3);
    q.show();

    return 0;
}