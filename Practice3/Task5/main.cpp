#include <iostream>
using namespace std;

int factorial(int& number) {
    if(number <= 1){
        return 1;
    }
    int factorialDecremented = number - 1;

    return number * factorial(factorialDecremented);
}

int main() {
    int factorialNumber;
    cin >> factorialNumber;

    cout << factorial(factorialNumber);

    return 0;
}
