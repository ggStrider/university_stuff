#include <iostream>
using namespace std;

int main() {
    int startValue;
    cout << "Enter start value: ";
    cin >> startValue;
    
    int finalValue;
    cout << "Enter final value: ";
    cin >> finalValue;

    cout << "Addresses: (start) " << &startValue << " (final) " << &finalValue << endl;

    if(startValue > 0) startValue = -startValue;
    if(finalValue > 0) finalValue = -finalValue;

    if(startValue > finalValue){
        int tempFinal = finalValue;
        finalValue = startValue;

        startValue = tempFinal;
    }

    for (int currentValue = startValue; currentValue <= finalValue ; currentValue++) {
        cout << currentValue << endl;
    }

    return 0;
}
