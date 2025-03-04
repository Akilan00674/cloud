#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Queue {
    Node* front;
    Node* rear;
};

void initializeQueue(Queue& q) {
    q.front = nullptr;
    q.rear = nullptr;
}

void enq(Queue& q, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (q.rear == nullptr) { // Empty queue
        q.front = newNode;
        q.rear = newNode;
    } else {
        q.rear->next = newNode;
        q.rear = newNode;
    }
}

void deq(Queue& q) {
    if (q.front == nullptr) {
        cout << "empty" << endl;
        return;
    }

    Node* temp = q.front;
    cout << "deleted element: " << temp->data << endl;
    q.front = q.front->next;

    if (q.front == nullptr) { // Queue becomes empty
        q.rear = nullptr;
    }

    delete temp;
}

void display(Queue q) {
    if (q.front == nullptr) {
        cout << "empty" << endl;
        return;
    }

    Node* current = q.front;
    while (current != nullptr) {
        cout << current->data << endl;
        current = current->next;
    }
}

int main() {
    Queue q;
    initializeQueue(q);

    enq(q, 11);
    enq(q, 12);
    enq(q, 13);
    enq(q, 14);
    enq(q, 15);

    cout << "Queue contents:" << endl;
    display(q);

    deq(q);
    cout << "Queue after dequeue:" << endl;
    display(q);

    deq(q);
    cout << "Queue after another dequeue:" << endl;
    display(q);

    deq(q);
    deq(q);
    deq(q);
    cout << "Queue after all dequeues:" << endl;
    display(q);

    return 0;
}
