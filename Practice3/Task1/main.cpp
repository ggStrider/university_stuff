#include <iostream>
using namespace std;

int sum(int number1, int number2){
    return number1 + number2;
}

float sum(float number1, float number2){
    return number1 + number2;
}

int main() {
    int intNum1 = 1, intNum2 = 2;
    cout << sum(intNum1, intNum2) << endl;

    float floatNum1 = 1.5, floatNum2 = 2.5;
    cout << sum(floatNum1, floatNum2);
	
	return 0;
}
