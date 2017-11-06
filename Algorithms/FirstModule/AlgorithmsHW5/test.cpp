#include <iostream>
#include <assert.h>

struct Rectangle {
public:
    int width;
    int height;
    int length;
    Rectangle() : width(0), height(0), length(0) {}
    Rectangle(int _width, int _height, int _length)
            : width(_width), height(_height), length(_length) {}
    ~Rectangle() {}
    inline int area() { return width * height; }
};

class Stack {
private:
    Rectangle* stackPtr;  // указатель на стек
    int size;             // максимальное количество элементов в стеке
    int top;  // номер текущего элемента стека
    inline void resize();

public:
    Stack();
    ~Stack();
    inline void push(const Rectangle&);  // поместить элемент в вершину стека
    inline Rectangle pop();       // удалить элемент из вершины стека и вернуть его
    inline Rectangle& elementFromTop(int);  // n-й элемент от вершины стека
    inline int getTop() const;  // получить номер текущего элемента в стеке
};

inline void Stack::resize() {
    Rectangle* temp = new Rectangle[size + 10];
    for (size_t i = 0; i < size; i++) temp[i] = stackPtr[i];
    size += 10;
    delete[] stackPtr;
    stackPtr = temp;
}
Stack::Stack() : size(10), top(0) { stackPtr = new Rectangle[10]; }
Stack::~Stack() { delete[] stackPtr; }
inline void Stack::push(const Rectangle& value) {
    if (top == size) resize();
    stackPtr[top++] = value;
}
inline Rectangle Stack::pop() { return stackPtr[--top]; }
inline Rectangle& Stack::elementFromTop(int n) { return stackPtr[top - n]; }
inline int Stack::getTop() const { return top; }

int maxArea(Rectangle* rectangle, int contOfRectangles) {
    Stack stack;
    int currentMaxArea = 0;

    for (int i = 0; i < contOfRectangles; ++i) {
        if (stack.getTop() == 0) {
            rectangle[i].length = 0;

            if (rectangle[i].area() > currentMaxArea) {
                currentMaxArea += rectangle[i].area();
            }
            stack.push(rectangle[i]);
            continue;
        } else {
            rectangle[i].length = stack.elementFromTop(1).length + stack.elementFromTop(1).width;
        }

        if (rectangle[i].height > stack.elementFromTop(1).height) {
            stack.push(rectangle[i]);
        } else {
            Rectangle previous = stack.pop();
            int endOfRec = rectangle[i].length + rectangle[i].width;
            int previousEndOfRec = previous.length + previous.width;

            if (previous.area() > currentMaxArea) {
                currentMaxArea = previous.area();
            }

            while (stack.getTop() != 0 && stack.elementFromTop(1).height >= rectangle[i].height) {
                previous = stack.pop();
                int lastMaxArea = (previousEndOfRec - previous.length) * previous.height;

                if (lastMaxArea > currentMaxArea) {
                    currentMaxArea = lastMaxArea;
                }
            }
            stack.push(Rectangle(endOfRec - previous.length, rectangle[i].height, previous.length));
        }
    }
    return currentMaxArea;
}

int main() {
    int n = 0;
    assert(scanf("%d", &n) == 1);
    Rectangle* array = new Rectangle[n + 1]();
    for (int i = 0; i < n; i++) {
        int width, height;
        if (scanf("%d %d", &width, &height) == 2) {
            array[i].width = width;
            array[i].height = height;
        }
    }
    printf("%d", maxArea(array, n + 1));
    delete[] array;

    return 0;
}