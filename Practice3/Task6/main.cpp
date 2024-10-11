#include <iostream>
using namespace std;

int main() {
    int boxSize;
    cin >> boxSize;

    if(boxSize <= 0) {
        cout << "Box size can't <= 0";
        return 0;
    }

    for (int row = 1; row <= boxSize; row++) {
        for (int column = 1; column <= boxSize; column++){
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}
