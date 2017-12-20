#include <iostream>
#include <vector>

#define HashParamA 37
#define HashParamB 79

#define MinCapacity 8
#define RehashValue 0.75

template <class T>
struct Node {
    T data;
    bool isDeleted;

    explicit Node(T data)
            :data(std::move(data)), isDeleted(false) {}
};

template <class T>
class HashTable {
public:
    explicit HashTable() :capacity(MinCapacity), size(0), buffer(MinCapacity, nullptr) {}
    ~HashTable() = default;

    bool Insert(T &);
    bool Delete(T &);
    bool Search(T &);

private:
    int capacity;
    int size;
    std::vector<Node<T> *> buffer;

    int HashA(T &, int);
    int HashB(T &, int);
    void Rehash();
};

template <class T>
int HashTable<T>::HashA(T &data, int size) {
    int result = 0;

    for (char i : data) {
        result = (i + result * HashParamA) % size;
    }

    return result;
}

template <class T>
int HashTable<T>::HashB(T &data, int size) {
    int result = 0;

    for (char i : data) {
        result = (i + result * HashParamB) % size;
    }

    return ((result << 1) + 1) % size;
}

template <class T>
void HashTable<T>::Rehash() {
    int newSize = capacity << 1;
    std::vector<Node<T> *> newBuffer(static_cast<unsigned long>(newSize), nullptr);

    for (int i = 0; i < capacity; ++i) {
        if (buffer[i] != nullptr && !buffer[i]->isDeleted) {
            T data = buffer[i]->data;
            int currentHash = HashA(data, newSize);
            int otherHash = HashB(data, newSize);
            int j = 0;

            while (newBuffer[currentHash] != nullptr && j < newSize) {
                currentHash = (currentHash + otherHash) % newSize;
                ++j;
            }
            newBuffer[currentHash] = new Node<T>(data);
        }
    }

    buffer = newBuffer;
    capacity = newSize;
}

template <class T>
bool HashTable<T>::Insert(T &data) {
    if (RehashValue <= size / capacity) {
        Rehash();
    }

    int i = 0;
    int deletedNodeIndex = -1;
    int hashA = HashA(data, capacity);
    int hashB = HashB(data, capacity);

    while (buffer[hashA] != nullptr && i < capacity) {
        if (buffer[hashA]->data == data && !buffer[hashA]->isDeleted) {
            return false;
        }
        if (buffer[hashA]->isDeleted && deletedNodeIndex < 0) {
            deletedNodeIndex = hashA;
        }
        hashA = (hashA + hashB) % capacity;
        ++i;
    }
    if (deletedNodeIndex >= 0) {
        buffer[deletedNodeIndex]->data = data;
        buffer[deletedNodeIndex]->isDeleted = false;
    } else {
        buffer[hashA] = new Node<T>(data);
    }

    ++size;
    return true;
}

template <class T>
bool HashTable<T>::Delete(T &data) {
    int hashA = HashA(data, capacity);
    int hashB = HashB(data, capacity);
    int i = 0;

    while (buffer[hashA] != nullptr && i < capacity) {
        if (buffer[hashA]->data == data && !buffer[hashA]->isDeleted) {
            buffer[hashA]->isDeleted = true;
            --size;
            return true;
        }
        hashA = (hashA + hashB) % capacity;
        ++i;
    }

    return false;
}

template <class T>
bool HashTable<T>::Search(T &data) {
    int hashA = HashA(data, capacity);
    int hashB = HashB(data, capacity);
    int i = 0;

    while (buffer[hashA] != nullptr && i < capacity) {
        if (buffer[hashA]->data == data && !buffer[hashA]->isDeleted) {
            return true;
        }
        hashA = (hashA + hashB) % capacity;
        ++i;
    }

    return false;
}

int main() {
    char c;
    std::string str;
    HashTable<std::string> table;

    while (std::cin >> c >> str) {
        bool result;

        switch (c) {
            case '+':
                result = table.Insert(str);
                break;
            case '-':
                result = table.Delete(str);
                break;
            case '?':
                result = table.Search(str);
                break;
            default:
                result = false;
                break;
        }

        std::cout << ((result) ? "OK" : "FAIL") << "\n";
    }
    return 0;
}