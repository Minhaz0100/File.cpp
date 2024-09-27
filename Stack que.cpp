#include <bits/stdc++.h>
using namespace std;
#define  SIZE 5
class Queue {
private:
    int front;
    int rear;
    int arr[SIZE];

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return rear == SIZE - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is full" << endl;
        } else {
            if (front == -1) front = 0; 
            rear++;
            arr[rear] = val;
            cout << val << " enqueued" << endl;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        } else {
            int dequeued = arr[front];
            arr[front] = 0;  
            front++;
            if (front > rear) {
                front = rear = -1; 
            }
            cout << dequeued << " dequeued" << endl;
            return dequeued;
        }
    }

    int count() {
        if (isEmpty()) return 0;
        return (rear - front + 1);
    }
    
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "Queue elements: ";
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Queue q1;
    int option, value;

    do {
        cout << "\nWhat operation do you want to perform? Select option number. Enter 0 to exit." << endl;
        cout << "1. Enqueue()" << endl;
        cout << "2. Dequeue()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. count()" << endl;
        cout << "6. display()" << endl;
        cout << "7. Clear Screen" << endl;

        cin >> option;

        switch (option) {
        case 0:
            break;
        case 1:
            cout << "Enqueue Operation\nEnter an item to enqueue: ";
            cin >> value;
            q1.enqueue(value);
            break;
        case 2:
            q1.dequeue();
            break;
        case 3:
            if (q1.isEmpty())
                cout << "Queue is Empty" << endl;
            else
                cout << "Queue is Not Empty" << endl;
            break;
        case 4:
            if (q1.isFull())
                cout << "Queue is Full" << endl;
            else
                cout << "Queue is Not Full" << endl;
            break;
        case 5:
            cout << "Number of elements in the queue: " << q1.count() << endl;
            break;
        case 6:
            q1.display();
            break;
        case 7:
            system("clear"); 
            break;
        default:
            cout << "Enter a valid option" << endl;
        }

    } while (option != 0);

    return 0;
}
