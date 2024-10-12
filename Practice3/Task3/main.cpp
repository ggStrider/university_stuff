#include <iostream>
#include <cmath>
using namespace std;

float boxArea(float side) {
    if(side <= 0) {
        cout << "Box side can't <= 0";
        return 0;
    }
    return side * side;
}

float rectangleArea(float side1, float side2) {
    if(side1 <= 0 || side2 <= 0) {
        cout << "Side can't <= 0";
        return 0;
    }

    return side1 * side2;
}

float circleArea(float radius) {
    return M_PI * radius * radius;
}

float triangleArea(float side1, float side2, float side3) {
    if(side1 <= 0 || side2 <= 0 || side3 <= 0) {
        cout << "Side can't <= 0";
        return 0;
    }

    float halfPerimeter = (side1 + side2 + side3) / 2;
    float area = sqrt(halfPerimeter * (halfPerimeter - side1) * (halfPerimeter - side2)
            * (halfPerimeter - side3));

    return area;
}

int main() {
    int boxSide = 4;
    cout << boxArea((float)boxSide) << endl;

    int rectangleSide1 = 2, rectangleSide2 = 3;
    cout << rectangleArea((float)rectangleSide1, (float)rectangleSide2) << endl;

    int triangleSide1 = 2, triangleSide2 = 3, triangleSide3 = 4;
    cout << triangleArea((float)triangleSide1, (float)triangleSide2, (float)triangleSide3) << endl;

    int radius = 3;
    cout << circleArea((float)radius);

    return 0;
}
