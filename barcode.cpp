#include <iostream>

using namespace std;

int usedDigitsSum(int digis[], int indexLimit) {
    int sum = 0;
    for (int i = 0; i < indexLimit; i++) {
        sum += digis[i];
    }
    return sum;
}

void displayArray(int digis[], int indexLimit) {
    for (int i = 0; i < indexLimit; i++) {
        cout << digis[i];
    }
    cout << endl;
}

int main() {

    int width, r;
    cout << "(width, r) = "; cin >> width >> r;
    int digits[r], count = 0;

    for (int i = 0; i < r; i++) {
        digits[i] = 1;
    }

    int place;
    while (true) {

        digits[r-1] = width - usedDigitsSum(digits, r-1);
        displayArray(digits, r);
        count++;

        place = r-2;
        while ( digits[place] == (width - (r - place - 1) - usedDigitsSum(digits, place)) ) {
            place--;
        }
        if (place < 0) break;
        
        digits[place]++;
        for (int i = place+1; i <= r-2; i++) {
            digits[i] = 1;
        }
    }
    cout << count << endl;
    return 0;
}