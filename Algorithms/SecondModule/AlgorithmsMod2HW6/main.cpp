#include <iostream>
#include <vector>

void CountingSort(std::vector<unsigned long long int> &array, unsigned long long int index) {
    std::vector<unsigned long long int> temporaryBuffer(array.size());
    std::vector<unsigned long long int> counting(10, 0);

    for (int i = 0; i < array.size(); i++) {
        counting[(array[i] / index) % 10]++;
    }
    for (int i = 1; i < 10; i++) {
        counting[i] += counting[i - 1];
    }
    for (int i = static_cast<int>(array.size() - 1); i >= 0; i--) {
        temporaryBuffer[--counting[(array[i] / index) % 10]] = array[i];
    }
    for (int i = 0; i < array.size(); i++) {
        array[i] = temporaryBuffer[i];
    }
};

void LSDSort(std::vector<unsigned long long int> &array, unsigned long long int biggest) {
    for (unsigned long long int i = 1; biggest / i > 0; i *= 10) {
        CountingSort(array, i);
    }
}

unsigned long long int Biggest(std::vector<unsigned long long int> &array) {
    unsigned long long int biggest = array[0];

    for (int i = 1; i < array.size(); i++) {
        if (array[i] > biggest) {
            biggest = array[i];
        }
    }

    return biggest;
};

int main() {
    size_t n;
    std::cin >> n;

    std::vector<unsigned long long int> array;

    for (size_t i = 1; i <= n; ++i) {
        unsigned long long int data = 0;
        std::cin >> data;

        array.push_back(data);
    }

    unsigned long long int biggest = Biggest(array);
    LSDSort(array, biggest);

    for (int i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }
    return 0;
}