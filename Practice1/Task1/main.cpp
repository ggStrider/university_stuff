#include <iostream>
using namespace std;

int main() {
    double side1, side2;
    cout << "Enter side 1 and side 2 (using space): " << endl;
    cin >> side1 >> side2;

    if(side1 <= 0 || side2 <= 0) {
        cout << "Invalid input. Sides can't <= 0 or text" << endl;
        return 1;
    }

    double area = side1 * side2;
    cout << "The area of the rectangle is: " << area << endl;

    double perimeter = 2 * (side1 + side2);
    cout << "The perimeter of the rectangle is: " << perimeter << endl;

    double sum = area + perimeter;
    cout << "The sum of the rectangles area and perimeter is: " << sum << endl;

    double difference = area - perimeter;
    cout << "The difference of the rectangles area and perimeter is: " << difference << endl;

    double product = area * perimeter;
    cout << "The product of the rectangles area and perimeter is: " << product << endl;

    double quotient = area / perimeter;
    cout << "The quotient of the rectangles area and perimeter is: " << quotient << endl;

    cout << endl << "Addresses in memory: ";
    cout << endl << &side1 << endl << &side2 << endl << &area << endl << &perimeter << endl << &quotient << endl;

    return 0;
}
