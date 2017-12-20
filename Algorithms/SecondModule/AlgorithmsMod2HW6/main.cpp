#include <iostream>

int Digit( long long value, int byte ) {
    return (value >> (8 * byte)) & 255;
}

void LSDLongLong(long long *arr, int countOfNumbers) {
    for( int i = 0; i < sizeof(long long); ++i ) {
        long long* buffer = new long long [countOfNumbers];
        int c[256] = {0};

        for (int j = 0; j < countOfNumbers; ++j) {
            c[Digit(arr[j], i)]++;
        }
        for (int j = 1; j < 256; ++j) {
            c[j] += c[j - 1];
        }
        for (int j = countOfNumbers - 1; j >= 0; --j) {
            buffer[--c[Digit(arr[j], i)]] = arr[j];
        }
        std::memcpy(arr, buffer, sizeof(long long) * countOfNumbers);

        delete[] buffer;
    }
}

int main() {
    int countOfNumbers = 0;
    std::cin >> countOfNumbers;

    if (countOfNumbers <= 0) {
        return 0;
    }

    long long* arr = new long long [countOfNumbers];

    for(int i = 0; i < countOfNumbers; i++) {
        std::cin >> arr[i];
    }

    LSDLongLong(arr, countOfNumbers);

    for(int i = 0; i < countOfNumbers; i++) {
        std::cout << arr[i] << " ";
    }

    delete[] arr;

    return 0;
}