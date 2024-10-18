#include <iostream>
using namespace std;

void copyValue(int* source, int* destination) {
    *destination = *source;
}

void countEvenOdd(int* a, int* b, int* c, int* evenCount, int* oddCount) {
    int numsToCheck[] = {*a, *b, *c};

    for(int i = 0; i <= 2; i++) {
        if(numsToCheck[i] % 2 == 0) {
            // Можна використати префіксну інкрементацію
            *evenCount += 1;
        }
        else *oddCount += 1;
    }
}

void multiply(int* a, int* b, int* result) {
    *result = (*a) * (*b);
}

void swapWithoutTemp(int* a, int* b) {
    // Я впевнений, що є варіант краще, але це єдине, до чого я дійшов
    *a = (*a) + (*b);
    *b = (*a) - (*b);
    *a = (*a) - (*b);
}

void findMinMax(int* a, int* b, int* c, int* min, int* max) {
    int nums[] = {*a, *b, *c};
    *min = nums[0];
    *max = nums[0];

    for (int i = 0; i <= 2 ; ++i) {
        for (int j = 0; j <= 2; j++) {
            if(j == i) continue;

            if(nums[i] > *max) *max = nums[i];
            if(*min > nums[i]) *min = nums[i];
        }
    }
}

int main() {
    int a1 = 3, b1 = 5;

    cout << a1 << endl << b1 << endl;
    copyValue(&a1, &b1);
    cout << a1 << endl << b1 << endl << endl;

    int a2 = 1, b2 = 6, c2 = 3, evenCount = 0, oddCount = 0;
    countEvenOdd(&a2, &b2, &c2, &evenCount, &oddCount);
    cout << evenCount << endl << oddCount << endl << endl;

    int a3 = 4, b3 = 5, result3 = 1;
    multiply(&a3, &b3, &result3);
    cout << result3 << endl << endl;

    int a4 = -3, b4 = 9;
    cout << a4 << endl << b4 << endl;
    swapWithoutTemp(&a4, &b4);
    cout << a4 << endl << b4 << endl << endl;

    int a5 = -10, b5 = 100, c5 = 0, min5, max5;
    findMinMax(&a5, &b5, &c5, &min5, &max5);
    cout << min5 << endl << max5 << endl;
}
