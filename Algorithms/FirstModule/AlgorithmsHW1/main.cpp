#include <iostream>
#include <cmath>

int maxDivider(int n) {
    for (int i = 2; i < sqrt(n); ++i) {
        if (n%i == 0) {
            return n/i;
        }
    }
    return 1;
}

int sumNod(int n) {
    int first = 0;
    if (n%2 == 0) {
        first = n/2;
    } else {
        first = maxDivider(n);
    }
    return first;
}

int main() {
    int n;
    int first = 0;
    std::cin >> n;

    first = sumNod(n);
    std::cout << first << " " << n - first << std::endl;
    return 0;
}