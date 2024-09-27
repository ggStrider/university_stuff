#include <iostream>

using namespace std;

int main() {
    int grade;

    cout << "Enter your grade: " << endl;
    cin >> grade;

    if(grade > 100 || grade < 0) {
        cout << "Grade out of range." << endl;
        return 1;
    }

    if (grade >= 90) {
        cout << "You have an excellent grade!";
    }
    else if (grade >= 70) {
        cout << "You have a good grade!";
    }
    else if (grade >= 45) {
        cout << "You have a satisfactory grade!";
    }
    else {
        cout << "You have a unsatisfactory grade!";
    }

    return 0;
}
