//Задано N точек на плоскости. Указать (N-1)-звенную
// несамопересекающуюся незамкнутую ломаную, проходящую через все эти точки.

#include <iostream>

struct Point {
    int x;
    int y;
};

//template <class T>
bool Comp(const Point &firstTmp, const Point &secondTmp) {
    return firstTmp.x > secondTmp.x || (firstTmp.x == secondTmp.x && firstTmp.y > secondTmp.y);
}

template <class T>
Point *SortPoints(Point *point, int left, int right, bool (*isLess)(const T&, const T&)) {
    Point tmp;
    int index = 0;

    for (int i = 0; i < right - 1; i++) {
        tmp = point[i + 1];
        index = i;

        while (index >= 0 && isLess(point[index], tmp)) {
            point[index + 1] = point[index--];
        }
        point[index + 1] = tmp;
    }

    return point;
}

int main() {
    int countOfPoints = 0;
    std::cin >> countOfPoints;
    Point *point = new Point[countOfPoints];

    for (int i = 0; i < countOfPoints; i++) {
        std::cin >> point[i].x >> point[i].y;
    }
    point = SortPoints(point, 0, countOfPoints, Comp);

    for (int i = 0; i < countOfPoints; i++) {
        std::cout << point[i].x << " " << point[i].y << std::endl;
    }

    delete[] point;
    return 0;
}