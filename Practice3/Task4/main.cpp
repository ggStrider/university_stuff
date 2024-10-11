#include <iostream>
using namespace std;

void swapRef(float& number1, float& number2){
    float temp = number1;

    number1 = number2;
    number2 = temp;
}

// doesn't affect anything
void swapValue(float number1, float number2) {
    float temp = number1;

    number1 = number2;
    number2 = temp;

    cout << "Swap by value inside function, first number: " << number1 << ", second: " << number2 << endl;
}

int main() {
    float swapNumberRef1 = 2.5, swapNumberRef2 = 4.5;

    cout << "(ref) Before swap, first: " << swapNumberRef1 << ", second: " << swapNumberRef2 << endl;
    swapRef(swapNumberRef1, swapNumberRef2);

    cout << "(ref) After swap, first: " << swapNumberRef1 << ", second: " << swapNumberRef2 << endl << endl;

    float swapNumberValue1 = 1.1, swapNumberValue2 = 3;
    cout << "(value) Before swap, first: " << swapNumberValue1 << ", second: " << swapNumberValue2 << endl;

    swapValue(swapNumberValue1, swapNumberValue2);
    cout << "(value) After swap, first: " << swapNumberValue1 << ", second: " << swapNumberValue2 << endl;

    return 0;
}
