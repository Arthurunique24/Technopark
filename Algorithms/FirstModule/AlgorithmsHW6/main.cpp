//Широкая пирамида
//Дано N кубиков. Требуется определить каким количеством способов можно выстроить из этих кубиков пирамиду.

//Формат ввода
//На вход подается количество кубиков N.

//Формат вывода
//Вывести число различных пирамид из N кубиков.

#include <iostream>

long long widePyramid(long long countOfCubes){
    long long** arrayOfPyramid = new long long*[countOfCubes];
    long long count = 0;
    int base = 0;

    for (int i = 0; i < countOfCubes; ++i) {
        arrayOfPyramid[i] = new long long[countOfCubes];
    }

    for (int j = 0; j < countOfCubes; ++j) {
        for (int k = 0; k < countOfCubes; ++k) {
            arrayOfPyramid[j][k] = 0;
        }
    }

    arrayOfPyramid[0][0] = 1;
    arrayOfPyramid[1][1] = 1;

    if (countOfCubes >= 2) {
        for (int i = 2; i < countOfCubes; ++i) {
            arrayOfPyramid[i][i] = 1;
            for (int j = i - 1; j >= 0; j--) {
                base = i - j - 1;
                if (base < i / 2) {
                    for (int k = 0; k <= base; ++k) {
                        arrayOfPyramid[i][j] += arrayOfPyramid[base][k];
                    }
                } else {
                    for (int l = 0; l < j; l++) {
                        arrayOfPyramid[i][j] += arrayOfPyramid[base][l];
                    }
                }
            }
        }
    }

    for (int i = 0; i < countOfCubes; ++i) {
        count += arrayOfPyramid[countOfCubes - 1][i];
        delete[](arrayOfPyramid[i]);
    }

    for (int i = 2; i < countOfCubes; ++i) {
        for (int j = i - 1; j >= 0; j--) {
            std::cout << arrayOfPyramid[i][j] << " ";
        }
        std::cout << std::endl;
    }

    delete[](arrayOfPyramid);
    return count;
}

int main() {
    int countOfCubes = 0;
    std::cin >> countOfCubes;

    if (countOfCubes < 0) {
        return 0;
    }

    std::cout << widePyramid(countOfCubes);

    return 0;
}