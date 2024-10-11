#include <iostream>
using namespace std;

int minByValue(int number1, int number2) {
    if(number1 < number2) {
        return number1;
    }
    return number2;
}

int minByReference(int& number1, int& number2) {
    if(number1 < number2) {
        return number1;
    }
    return number2;
}

int main() {
    int byValue1 = 3, byValue2 = 5;
    cout << minByValue(byValue1, byValue2) << endl;

    int byRef1 = 4, byRef2 = 6;
    cout << minByReference(byRef1, byRef2);

    return 0;
}
