#include <iostream>

template <class T>
bool Compare(const T left, const T right) {
    return left < right;
}

template <class T>
T FindMedian(T *array, size_t left, size_t right, bool (*IsLess)(const T&, const T&)) {
    if (IsLess(array[left], array[(left + right) / 2])) {
        std::swap(array[left], array[right]);
    }

    if (IsLess(array[left], array[right])) {
        std::swap(array[left], array[right]);
    }

    if (!IsLess(array[(left + right) / 2], array[right])) {
        std::swap(array[(left + right) / 2], array[right]);
    }

    return array[right];
}

template <class T>
size_t Partition(T *array, size_t left, size_t right, bool (*IsLess)(const T&, const T&)) {
    T pivot = FindMedian(array, left, right, Compare);
    size_t i = left;
    size_t j = left;

    while (IsLess(j, right)) {
        if (array[j] <= pivot) {
            std::swap(array[i++], array[j++]);
        } else {
            j++;
        }
    }
    std::swap(array[i], array[right]);
    return i;
}

template <class T>
T OrderStatistic(T *array, size_t n, size_t k, bool (*IsLess)(const T&, const T&)) {
    size_t left = 0;
    size_t right = n - 1;

    while (true) {
        size_t partition = Partition(array, left, right, IsLess);

        if (partition == k) {
            return array[partition];
        }
        partition > k ? right = partition - 1 : left = partition + 1;
    }
}

int main() {
    size_t n = 0;
    std::cin >> n;

    size_t k = 0;
    std::cin >> k;

    int *array = new int[n];

    for (size_t i = 0; i < n; i++) {
        std::cin >> array[i];
    }

    std::cout << OrderStatistic(array, n, k, Compare);

    delete[] array;
    return 0;
}