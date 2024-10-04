#include <iostream>
using namespace std;

int main() {
    cout << "Enter triangle height: ";

    int triangleHeight;
    cin >> triangleHeight;
    cout << endl;

    for (int currentRow = 0; currentRow <= triangleHeight; currentRow++) {
        for (int currentColumn = 0; currentColumn <= currentRow; currentColumn++)
            cout << "*";

        cout << endl;
    }

    return 0;
}