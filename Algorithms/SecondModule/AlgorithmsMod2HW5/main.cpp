#include <iostream>
#include <vector>

template <class T>
bool LessOrEqual(const T tmp1, const T tmp2) {
    return tmp1 <= tmp2;
}

template <class T>
bool IsLess(const T tmp1, const T tmp2) {
    return tmp1 < tmp2;
}

//Like in lectures
template <class T>
void Merge(std::vector<T> &array, size_t left, size_t right, bool (*Compare)(const T&, const T&)) {
    size_t middle = (left + right) / 2;
    size_t firstIndex = left;
    size_t secondIndex = middle + 1;

    std::vector<T> temporaryBuffer(right - left + 1);
    size_t temporaryBufferIndex = 0;

    while (Compare(firstIndex, middle) && Compare(secondIndex, right)) {
        if (Compare(array[firstIndex], array[secondIndex])) {
            temporaryBuffer[temporaryBufferIndex++] = array[firstIndex++];
        } else {
            temporaryBuffer[temporaryBufferIndex++] = array[secondIndex++];
        }
    }

    while (Compare(firstIndex, middle)) {
        temporaryBuffer[temporaryBufferIndex++] = array[firstIndex++];
    }
    while (Compare(secondIndex, right)) {
        temporaryBuffer[temporaryBufferIndex++] = array[secondIndex++];
    }
    std::copy(temporaryBuffer.begin(), temporaryBuffer.end(), array.begin() + left);
}

//Like in lectures
template <class T>
void MergeSort(std::vector<T> &array, size_t left, size_t right, bool (*Compare)(const T&, const T&)) {
    if (left == right) {
        return;
    }

    size_t len = left + right;
    size_t firstIndex = len / 2;

    MergeSort(array, left, firstIndex, Compare);
    MergeSort(array, firstIndex + 1, right, Compare);

    Merge(array, left, right, Compare);
}

template <class T>
void kSequence(std::vector<T> &lhs, std::vector<T> &rhs, size_t k,
               size_t i, bool (*Compare)(const T&, const T&)) {
    size_t firstPosition = 0;
    size_t secondPosition = 0;

    std::vector<T> temporaryBuffer(k);
    size_t temporaryBufferIndex = 0;

    while (Compare(firstPosition, k) && Compare(secondPosition, i) && Compare(temporaryBufferIndex, k)) {
        if (lhs[firstPosition] <= rhs[secondPosition]) {
            temporaryBuffer[temporaryBufferIndex++] = lhs[firstPosition++];
        } else {
            temporaryBuffer[temporaryBufferIndex++] = rhs[secondPosition++];
        }
    }

    while (Compare(firstPosition, k) && Compare(temporaryBufferIndex, k)) {
        temporaryBuffer[temporaryBufferIndex++] = lhs[firstPosition++];
    }

    std::copy(temporaryBuffer.begin(), temporaryBuffer.end(), lhs.begin());
}

int main() {
    size_t n = 0;
    std::cin >> n;

    size_t kIndex = 0;
    std::cin >> kIndex;

    std::vector<int> sequence(kIndex);
    std::vector<int> temporaryBuffer(kIndex);

    for (size_t i = 0; i < kIndex; i++) {
        std::cin >> sequence[i];
    }

    MergeSort(sequence, 0, kIndex - 1, LessOrEqual);

    size_t j = kIndex;
    while (j < n) {
        size_t i = 0;
        for (; i < kIndex && j < n; i++, j++) {
            std::cin >> temporaryBuffer[i];
        }

        MergeSort(temporaryBuffer, 0, i - 1, LessOrEqual);
        kSequence(sequence, temporaryBuffer, kIndex, i, IsLess);
    }

    for (int k = 0; k < kIndex; k++) {
        std::cout << sequence[k] << " ";
    }

    return 0;
}