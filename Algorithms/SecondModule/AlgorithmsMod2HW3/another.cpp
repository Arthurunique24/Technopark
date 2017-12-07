#include <iostream>
#include <vector>

struct Point {
    int _x;
    bool _begin;
};

bool less(const Point &lhs, const Point &rhs) {
    return lhs._x < rhs._x;
}

template <class T, class comparator>
void heapSiftDown(T begin, size_t size, size_t head, comparator &less) {
    while ((head << 1) + 1 < size) {
        size_t child = 2 * head + 1;
        if (child + 1 < size && less(*(begin + child), *(begin + child + 1))) {
            ++child;
        }
        if (!less(*(begin + head), *(begin + child))) {
            return;
        }
        std::swap(*(begin + head), *(begin + child));
        head = child;
    }
}

template <class T, class comparator>
void BuildHeap(T begin, size_t size, comparator &less) {
    for (size_t child = size - 1; ; child -= 2) {
        heapSiftDown(begin, size, (child - 1) >> 1, less);
        if (child <= 2) {
            break;
        }
    }
}

template <class T, class comparator>
void heapSort(T begin, T end, comparator &less) {
    size_t size = std::distance(begin, end);
    BuildHeap(begin, size, less);
    while (size > 1) {
        --size;
        std::swap(*begin, *(begin + size));
        heapSiftDown(begin, size, 0, less);
    }
}

size_t countPaint(const std::vector<Point> &points) {
    size_t paintSize = 0;
    size_t isColor = 0;
    Point begin;
    for (auto i = points.begin(); i != points.end(); ++i) {
        if (i->_begin) {
            if (isColor == 0) {
                begin = *i;
            }
            ++isColor;
        } else {
            --isColor;
        }
        if (isColor == 1) {
            paintSize += (i->_x - begin._x);
        }
    }
    return paintSize;
}

int main() {
    size_t n;
    std::cin >> n;
    std::vector<Point> points;
    for (size_t i = 1; i <= n; ++i) {
        Point begin;
        Point end;
        std::cin >> begin._x;
        std::cin >> end._x;
        if (begin._x < end._x) {
            begin._begin = true;
        } else {
            end._begin = true;
        }
        points.push_back(begin);
        points.push_back(end);
    }
    heapSort(points.begin(), points.end(), less);
    printf("%ld\n", countPaint(points));
    return 0;
}