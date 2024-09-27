#include <iostream>

using namespace std;

int main() {
    int checkRemainderNumber;
    cout << "Enter a number: \n";
    cin >> checkRemainderNumber;

    double remainder = checkRemainderNumber % 7;
    cout << "The remainder of " << checkRemainderNumber << " / 7 = " << remainder << endl;

    int num1, num2;
    cout << "Enter two numbers: \n";
    cin >> num1 >> num2;

    if (num1 % num2 == 0) {
        cout << "No remainder by " << num1 << " / " << num2;
    }

    string isFirstNumberEven = num1 % 2 == 0 ? " is even" : " is odd";
    cout << num1 << isFirstNumberEven << endl;

    string isSecondNumberEven = num2 % 2 == 0 ? " is even" : " is odd";
    cout << num2 << isSecondNumberEven << endl;

    return 0;
}
