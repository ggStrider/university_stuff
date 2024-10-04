#include <iostream>
using namespace std;

int main() {
    cout << "Enter the number: ";

    int number;
    cin >> number;

    cout << endl << "Even numbers from 1 to " << number << endl;

    float sumOfEvenNumbers = 0;
    for (int i = 1; i <= number; i++) {
        if(i % 2 != 0) continue;

        cout << i << endl;
        sumOfEvenNumbers += i;
    }

    cout << endl << "Sum of all of this numbers: " << sumOfEvenNumbers << endl << endl;
    cout << "Sum divided by 2: " << sumOfEvenNumbers / 2.0;

    return 0;
}
