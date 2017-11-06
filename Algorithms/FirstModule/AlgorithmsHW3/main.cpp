//Поиск близнеца
//Дан отсортированный массив различных целых чисел A[0..n-1] и массив целых чисел B[0..m-1].
//Для каждого элемента массива B[i] найдите минимальный индекс элемента массива A[k], ближайшего по значению к B[i].
//Время работы поиска для каждого элемента B[i]: O(log(k)). n ≤ 110000, m ≤ 1000.

#include <iostream>

int binarSearch(int* array, int first, int second, int element) {
    while(first < second - 1) {
        int middle = (first + second) / 2;
        if (array[middle] < element) {
            first = middle;
        } else {
            if (array[middle] > element) {
                second = middle;
            } else {
                return middle;
            }
        }
    }

    return (abs(array[first] - element) <= abs(array[second] - element) ? first : second);
}

int twinElements(int* array, int size, int element) {
    int second = 1;
    if (array[0] >= element) {
        second = 0;
    } else {
        while (array[second] < element) {
            second *= 2;
            if (second > size) {
                second = size - 1;
                break;
            }
        }
    }
    return binarSearch(array, second / 2, second, element);
}

int main() {
    int sizeA = 0;
    std::cin >> sizeA;
    if (sizeA < 1) {
        return 0;
    }

    int* arrayA = new int[sizeA];
    for (int i = 0; i < sizeA; ++i) {
        std::cin >> arrayA[i];
    }

    int sizeB = 0;
    std::cin >> sizeB;
    if (sizeB < 1) {
        return 0;
    }

    int* arrayB = new int[sizeB];
    for (int i = 0; i < sizeB; ++i) {
        std::cin >> arrayB[i];
        std::cout << twinElements(arrayA, sizeA, arrayB[i]) << " ";
    }

    delete[](arrayA);
    delete[](arrayB);

    return 0;
}