#include <iostream>
#include <string.h>
using namespace std;
#define size 7
class queue
{
public:
    int item_no;
    string item_name;
    float price;

    int front = -1;
    int rear = -1;

public:
    void enqueue(queue arr[], int data, string name, float p)
    {
        if (front == -1 && rear == -1)
        {
            front = 0;
            rear++;
            arr[rear].item_no = data;
            arr[rear].item_name = name;
            arr[rear].price = p;
        }
        else if (front == (rear + 1) % size)
        {
            cout << "\nqueue full\n";
        }
        else if (front != 0)
        {
            rear = (rear + 1) % size;
            arr[rear].item_no = data;
            arr[rear].item_name = name;
            arr[rear].price = p;
        }
        else
        {
            rear = (rear + 1) % size;
            arr[rear].item_no = data;
            arr[rear].item_name = name;
            arr[rear].price = p;
        }
    }

    void display(queue arr[])
    {
        if (front == -1 && rear == -1)
        {
            cout << "\nqueue is empty\n";
        }
        else
        {
            cout << "Item no.\t\tName\t\tPrice\n";

            for (int i = front; i <= rear; i++)
            {
                cout << arr[i].item_no << "\t\t\t" << arr[i].item_name << "\t\t" << arr[i].price << "\n";
            }
            cout << endl;
        }
    }

    void dequeue(queue arr[])
    {
        if (front == -1 && rear == -1)
        {
            cout << "\nqueue is empty\n";
        }
        else if (front == rear)
        {
            cout << "\n"
                 << arr[front].item_no << " deleted\n";
            front = -1;
            rear = -1;
        }
        else
        {
            cout << "\n"
                 << arr[front].item_no << " deleted\n";
                 front++;
            // rear = (rear - 1) % size;
        }
    }
};

int main()
{
    queue q;

    queue *arr = new queue[size];

    while (true)
    {

        int choice;
        cout << "\nEnter choice\n1.enqueue\n2.dequeue\n3.display\n4.stop\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "\nEnter item no.\n";
            int data;
            cin >> data;
            cout << "\nEnter item name.\n";
            string item_name;
            cin >> item_name;
            cout << "\nEnter item price.\n";
            float p;
            cin >> p;
            q.enqueue(arr, data, item_name, p);
            break;
        } // put braces


    
        case 2:
            q.dequeue(arr);
            break;
        case 3:
            q.display(arr);
            break;
        }
        if (choice == 4)
        {
            break;
        }
    }
}