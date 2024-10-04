#include <iostream>
using namespace std;

bool isPrime(int value){
    if(value <= 1) return false;

    if(value == 2 || value == 3) return true;

    int decreasedRange = value / 2;
    for (int i = 2; i < decreasedRange ; i++) {
        if(value % i == 0) return false;
    }

    return true;
}

int main() {
    int finalValue;

    cout << "Enter final value: " << endl;
    cin >> finalValue;

    for (int currentValue = 0; currentValue <= finalValue; ++currentValue) {
        if(!isPrime(currentValue)) continue;

        cout << currentValue << endl;
    }

    return 0;
}