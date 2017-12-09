#include <iostream>
#include <vector>

//template <class T>
//bool IsLess(const T &tmp1, const T &tmp2) {
//    return tmp1 < tmp2;
//}

template <class T>
class Heap {
public:
    Heap(): heapSize(0) {
        heapArray.push_back(0);
    }

    Heap(T* array, int size): heapSize(0) {
        heapArray.push_back(0);

        for (int i = 0; i < size; ++i) {
            heapArray.push_back(array[i]);
            ++heapSize;
        }

        for (int i = size/2 - 2; i > 0; --i) {
            SiftDown(i);
        }
    }

    void Push(T data) {
        heapArray.push_back(data);

        SiftUp(heapSize);

        ++heapSize;
    }

    T Max() {
        return heapArray[1];
    }

    T ExtractMax() {
        T data = heapArray[1];
        std::swap(heapArray[1], heapArray[heapSize]);
        heapArray.pop_back();

        SiftDown(1);

        --heapSize;

        return data;
    }

    bool IsEmpty() {
        return heapSize == 0;
    }

private:
    std::vector<T> heapArray;
    int heapSize;

    void SiftUp(int index) {
        for (int i = index + 1; i > 1;) {
            if (heapArray[i] > heapArray[i / 2]) {
                std::swap(heapArray[i], heapArray[i / 2]);
                i = i / 2;
            } else {
                break;
            }
        }
    }

    void SiftDown(int index) {
        for (; 2 * index < heapSize;) {
            index *= 2;
            if ((index + 1) < heapSize && heapArray[index] < heapArray[index + 1]) {
                index += 1;
            }
            if (heapArray[index / 2] < heapArray[index]) {
                std::swap(heapArray[index / 2], heapArray[index]);
            }
        }
    }
};

template <class T>
int Greedy(T *array, int fruitCount, int capacity) {

    Heap<int> heap(array, fruitCount);

    int countOfApproach = 0;
    std::vector<T> buffer;

    while (!heap.IsEmpty()) {
        int totalWeight = 0;
//        int currentWeight =

        while (!heap.IsEmpty() && totalWeight + heap.Max() <= capacity) {
            int currentWeight = heap.ExtractMax();

            totalWeight += currentWeight;
            buffer.push_back(currentWeight);
        }
        for (T i = buffer.size() - 1; i >= 0; --i) {
            if (buffer[i] != 1) {
                heap.Push(buffer[i] / 2);
            }
            buffer.pop_back();
        }
        countOfApproach++;
    }

    return countOfApproach;
}

int main() {
    int fruitCount = 0;
    std::cin >> fruitCount;
    auto *array = new int[fruitCount];

    for (int i = 0; i < fruitCount; ++i) {
        std::cin >> array[i];
    }

    int capacity = 0;
    std::cin >> capacity;

    std::cout << Greedy(array, fruitCount, capacity);

    delete[] array;

    return 0;
}