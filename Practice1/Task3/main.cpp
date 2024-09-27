#include <iostream>

using namespace std;

int main() {
    int number;

    cout << "Enter a number: ";
    cin >> number;

    cout << "number++: " << number++ << endl;
    cout << "After number++: " << number << endl;

    cout << "++number: " << ++number << endl;

    cout << "number--: " << number-- << endl;
    cout << "After number--: " << number << endl;

    cout << "--num: " << --number << endl;

    return 0;
}
