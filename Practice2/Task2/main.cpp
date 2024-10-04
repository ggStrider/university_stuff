#include <iostream>
using namespace std;

int main() {
    cout << "Enter two years (using space): ";

    int year1, year2;
    cin >> year1 >> year2;

    if (year1 > year2) {
        int temp = year2;

        year1 = year2;
        year2 = temp;
    }

    int difference = year2 - year1;
    if(difference >= 100) {
        cout << "Difference between two years is more than 100";
        return 0;
    }

    cout << "The difference is: " << difference << endl;

    int decades = 0;
    for(int i = year1 + 10; i <= year2; i += 10) {
        cout << i << endl;
        decades++;
    }

    cout << "Decades: " << decades << endl;

    return 0;
}
