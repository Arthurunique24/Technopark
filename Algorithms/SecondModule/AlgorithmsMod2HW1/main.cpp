//Задано N точек на плоскости. Указать (N-1)-звенную
// несамопересекающуюся незамкнутую ломаную, проходящую через все эти точки.

#include <iostream>

struct Point {
    int x;
    int y;

    Point(): x(0), y(0) {}
};

bool Comp(const Point &firstTmp, const Point &secondTmp) {
    return firstTmp.x > secondTmp.x || (firstTmp.x == secondTmp.x && firstTmp.y > secondTmp.y);
}

template <class T>
void MySort(T *array, int left, int right, bool (*Compare)(const T&, const T&)) {
    T tmp;
    int index = 0;

    for (int i = 0; i < right - 1; i++) {
        tmp = array[i + 1];
        index = i;

        while (index >= 0 && Compare(array[index], tmp)) {
            array[index + 1] = array[index--];
        }
        array[index + 1] = tmp;
    }
}

int main() {
    int countOfPoints = 0;
    std::cin >> countOfPoints;
    Point *point = new Point[countOfPoints];

    for (int i = 0; i < countOfPoints; i++) {
        std::cin >> point[i].x >> point[i].y;
    }
    MySort(point, 0, countOfPoints, Comp);

    for (int i = 0; i < countOfPoints; i++) {
        std::cout << point[i].x << " " << point[i].y << std::endl;
    }

    delete[] point;
    return 0;
}