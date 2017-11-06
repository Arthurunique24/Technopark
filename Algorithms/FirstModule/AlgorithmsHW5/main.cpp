//Прямоугольники 5.3
//Дана последовательность N прямоугольников различной ширины и высоты (wi, hi).
// Прямоугольники расположены, начиная с точки (0, 0), на оси ОХ вплотную друг за другом (вправо).
//Требуется найти M - площадь максимального прямоугольника (параллельного осям координат),
//который можно вырезать из этой фигуры.
//Время работы - O(n).

#include <iostream>

struct Rectangle {
    int width;
    int height;
    int length;

    Rectangle():width(0), height(0),length(0) {}
    Rectangle(int width_, int height_, int length_) :width(width_), height(height_), length(length_) {}

    int area() {
        return width * height;
    }
};

class Stack {
public:
    Stack();
    ~Stack();

    void push(const Rectangle& value);
    Rectangle pop();
    Rectangle& elementFromTop(int n);
    int getTop();
private:
    Rectangle* rectangle;
    int stackSize;
    int top;
    void resize();
};

Stack::Stack(): stackSize(8), top(0) {
    rectangle = new Rectangle[stackSize];
}

Stack::~Stack() {
    delete[](rectangle);
}

void Stack::resize() {
    int newStackSize = stackSize * 2;
    Rectangle* newRectangle = new Rectangle[newStackSize];
    for (int i = 0; i < stackSize; ++i) {
        newRectangle[i] = rectangle[i];
    }
    stackSize = newStackSize;
    delete[](rectangle);
    rectangle = newRectangle;
}

void Stack::push(const Rectangle& value) {
    if (top == stackSize) {
        resize();
    }

    rectangle[top++] = value;
}

Rectangle Stack::pop() {
    return rectangle[--top];
}

Rectangle &Stack::elementFromTop(int n) {
    return rectangle[top - 1];
}

int Stack::getTop() {
    return top;
}

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
            Rectangle previous = stack.pop(); //pop previous rectangle
            int endOfRec = rectangle[i].length + rectangle[i].width; //end of the current rectangle
            int previousEndOfRec = previous.length + previous.width; //end of the previous rectangle

            //if area of previous rectangle more, then current max area - change
            if (previous.area() > currentMaxArea) {
                currentMaxArea = previous.area();
            }

            //while stack isn't empty and height of last rectangle in the stack more or the same of current rectangle
            while (stack.getTop() != 0 && stack.elementFromTop(1).height >= rectangle[i].height) {
                previous = stack.pop(); //pop the last rectangle
                //find width and height
                int lastMaxArea = (previousEndOfRec - previous.length) * previous.height;

                //if area more = change
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
    int countOfRectangles = 0;
    std::cin >> countOfRectangles;

    Rectangle* rectangle = new Rectangle[countOfRectangles + 1]();

    for (int i = 0; i < countOfRectangles; i++) {
        int width = 0;
        int height = 0;

        std::cin >> width >> height;

        rectangle[i].width = width;
        rectangle[i].height = height;
    }

    std::cout << maxArea(rectangle, countOfRectangles + 1);

    delete [] rectangle;
    return 0;
}