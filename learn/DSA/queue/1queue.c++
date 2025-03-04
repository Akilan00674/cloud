#include <iostream>
using namespace std;

struct Queue {
    int* arr;
    int rear;
    int front;
    int max;
};

void enq(Queue& q, int value) {
    if (q.rear == q.max - 1) {
        cout << "isfull" << endl;
    } else if (q.rear == -1 && q.front == -1) {
        q.rear = 0;
        q.front = 0;
        q.arr[q.rear] = value;
    } else {
        q.rear++;
        q.arr[q.rear] = value;
    }
}

void deq(Queue& q) {
    if (q.rear == -1 && q.front == -1) {
        cout << "empty" << endl;
    } else if (q.rear == 0 && q.front == 0) { // Corrected empty check
        cout << "empty" << endl;
        q.front = -1; // Reset front and rear
        q.rear = -1;
    } else {
        cout << "deleted elements: " << q.arr[q.front] << endl;
        q.front++;
    }
}

void display(Queue q) {
    if (q.front == -1 || q.front > q.rear) { // Corrected empty check
        cout << "empty" << endl;
    } else {
        for (int i = q.front; i <= q.rear; i++) {
            cout << q.arr[i] << endl;
        }
    }
}

int main() {
    Queue q;
    q.max = 5;
    q.rear = -1;
    q.front = -1;
    q.arr = new int[5];

    enq(q, 11);
    enq(q, 12);
    enq(q, 13);
    enq(q, 14);
    enq(q, 15);

    cout << "Queue contents:" << endl;
    display(q);

    // Example of using deq:
    cout << "After dequeue:" << endl;
    deq(q);
    display(q);

    deq(q);
    display(q);
    deq(q);
    deq(q);
    deq(q);
    display(q);

    delete[] q.arr; // Important: deallocate memory
    return 0;
}
