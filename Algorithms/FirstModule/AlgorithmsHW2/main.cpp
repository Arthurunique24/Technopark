//Нужная сумма
//Даны два строго возрастающих массива целых чисел A[0..n) и B[0..m) и число k.
//Найти количество таких пар индексов (i, j), что A[i] + B[j] = k.
//Время работы O(n + m). n, m ≤ 100000.
//Указание. Обходите массив B от конца к началу.

#include <iostream>

int correctAmount(int sizeOfA, int *arrayA, int sizeOfB, int *arrayB, int numberAmout) {
    int countOf = 0;
    int indexB = 0;
    int indexA = sizeOfA - 1;

    while ( 0 <= indexA && indexB < sizeOfB ) {
        int sum = arrayA[indexA] + arrayB[indexB];
        if (sum > numberAmout) {
            --indexA;
        }
        if (sum < numberAmout) {
            ++indexB;
        }
        if (sum == numberAmout) {
            --indexA;
            ++indexB;
            ++countOf;
        }
    }

    return countOf;
}

int main() {
    int sizeA = 0;
    std::cin >> sizeA;
    int arrayA[sizeA];
    for (int i = 0; i < sizeA; ++i) {
        std::cin >> arrayA[i];
    }

    int sizeB = 0;
    std::cin >> sizeB;
    int arrayB[sizeB];
    for (int i = 0; i < sizeB; ++i) {
        std::cin >> arrayB[i];
    }

    int amount = 0;
    std::cin >> amount;

    int countOf = 0;
    countOf = correctAmount(sizeA, arrayA, sizeB, arrayB, amount);
    std::cout << countOf << std::endl;
    return 0;
}