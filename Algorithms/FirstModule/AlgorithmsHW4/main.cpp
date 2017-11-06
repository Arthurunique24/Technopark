//Очередь с динамическим буфером 4.1
//Реализовать очередь с динамическим зацикленным буфером.
//Обрабатывать команды push back и pop front.

//Формат ввода
//В первой строке количество команд n. n ≤ 1000000.
//Каждая команда задаётся как 2 целых числа: a b.
//a = 2 - pop front
//a = 3 - push back
//Если дана команда pop front, то число b - ожидаемое значение.
// Если команда pop front вызвана для пустой структуры данных, то ожидается “-1”.

#include <iostream>

class Queue {
public:
    Queue(int size);
    ~Queue();

    void Enqueue(int value);
    int Dequeue();
    void Print();
private:
    bool resize();
    int move(int& pos);

    int *queueArray;
    int queueSize;
    int start;
    int end;
    int countOfElem;
};

Queue::Queue(int size): queueSize(size), start(0), end(0), countOfElem(0) {
    queueArray = new int[queueSize];
}

Queue::~Queue() {
    delete[](queueArray);
}

void Queue::Enqueue(int value) {
    if (countOfElem >= queueSize) {
        resize();
    }

    queueArray[end++] = value;

    ++countOfElem;

    end %= queueSize;

}


int Queue::Dequeue() {
    if (countOfElem <= 0) {
        return -1;
    }

    int returnValue = queueArray[start++];
    countOfElem--;

    start %= queueSize;

    return returnValue;
}

void Queue::Print() {
    std::cout << "Queue ";
    if (end == 0 && start == 0) {
        std::cout << "is empty..." << std::endl;
    } else {
        for (int i = end; i > start; --i) {
            std::cout << queueArray[i - 1] << " ";
        }
        std::cout << std::endl;
    }

}

bool Queue::resize() {
    int newQueueSize = queueSize * 2;
    int* newQueueArray = new int[newQueueSize];

    int ptr = start;
    for (int i = 0; i < countOfElem; ++i) {
        //newQueueArray[i] = queueArray[(start + i) % queueSize];
        newQueueArray[i] = queueArray[move(ptr)];
    }

    start = 0;
    end = countOfElem;
    queueSize = newQueueSize;

    delete[](queueArray);
    queueArray = newQueueArray;
    return true;
}

int Queue::move(int& position) {
    int tmp = position;
    ++position;
    position %= queueSize;
    return tmp;
}

int main() {
    int countOfCommands = 0;
    bool isOk = true;

    std::cin >> countOfCommands;
    Queue queue(2);
    for (int i = 0; i < countOfCommands; ++i) {
        int command = 0;
        int value = 0;

        std::cin >> command;
        std::cin >> value;

        switch (command) {
            case 2:
                if (queue.Dequeue() != value) {
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