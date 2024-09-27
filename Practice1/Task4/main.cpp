#include <iostream>

using namespace std;

int main() {
    int age, salary;

    cout << "Enter your age: ";
    cin >> age;

    cout << "Enter your salary: ";
    cin >> salary;

    if(!(age > 20 && salary > 400 && salary < 1000)) {
        cout << "You are not suitable" << endl;
        return 0;
    }

    cout << "We will consider your position" << endl;

    string name;
    cout << "Enter your name: ";
    cin >> name;

    string desiredPosition;
    cout << "Enter your desired position: ";
    cin >> desiredPosition;

    cout << endl << "Your salary: " << salary << endl << "Your age: " << age << endl;
    cout << "Your name: " << name << endl << "Your desired position: " << desiredPosition << endl;
	
	return 0;
}
