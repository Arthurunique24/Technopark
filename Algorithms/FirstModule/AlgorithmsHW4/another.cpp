//
// Created by Arthur  on 10/6/17.
//

#include <iostream>

struct Node {
    int Data;
    Node* Next;

    Node() : Data(0), Next(0) {}
    Node(int value) : Data(value), Next(0) {}
};

class Queue {
public:
    Queue();
    ~Queue();
    void Enqueue(int value);
    int Dequeue();
private:
    Node* head;
    Node* tail;
};

Queue::Queue() {
    head = 0;
    tail = 0;
}

Queue::~Queue() {
    Node* nodeTail = tail;
    while (nodeTail) {
        Node* nextNode = nodeTail -> Next;
        delete(nodeTail);
        nodeTail = nextNode;
    }
}

void Queue::Enqueue(int value) {
    if (head == 0) {
        head = new Node(value);
        tail = new Node(value);
        return;
    }

    Node* newNode = new Node(value);
    head -> Next = newNode;
    head = newNode;
}

int Queue::Dequeue() {
    if (head == 0) {
        return -1;
    }

    Node* nodeTail = tail;
    tail = tail -> Next;
    int value = nodeTail -> Data;
    delete(nodeTail);

    if (tail == 0) {
        head = 0;
    }

    return value;
}

int main() {
    Queue queue;
    int countOfCommands = 0;
    bool isOk = true;

    std::cin >> countOfCommands;
    for (int i = 0; i < countOfCommands; ++i) {
        int command = 0;
        int value = 0;

        std::cin >> command;
        std::cin >> value;

        switch (command) {
            case 2:
                if (queue.Dequeue() != value || queue.Dequeue() != -1) {
                    isOk = false;
                }
                break;
            case 3:
                queue.Enqueue(value);
                break;
            default:
                break;
        }
    }

    if (isOk) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }

    return 0;
}