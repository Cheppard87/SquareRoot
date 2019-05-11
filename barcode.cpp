#include <iostream>
#include <fstream>
#include <math.h>

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
        cout << hex << uppercase << digis[i];
    }
    cout << endl;
}

int main() {

    int width = 17, r = 8;
    // cout << "width = "; cin >> width;
    // cout << "r = "; cin >> r;
    int limit = width - r + 1;
    limit = 6;
    int digits[r], count = 0;

    for (int i = 0; i < r; i++) {
        digits[i] = 1;
    }
    
    ios_base::fmtflags f( cout.flags() );
    std::ofstream out("C:\\Users\\Nadeem\\Desktop\\new.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    int place;
    while (true) {

        digits[r-1] = width - usedDigitsSum(digits, r-1);
        if (digits[r-1] <= limit) {
        displayArray(digits, r);
        count++;
        }

        place = r-2;
        while ( digits[place] == min(width - (r - place - 1) - usedDigitsSum(digits, place), limit) ) {
            place--;
        }
        if (place < 0) break;
        
        digits[place]++;
        for (int i = place+1; i <= r-2; i++) {
            digits[i] = 1;
        }
    }
    cout.flags( f );
    
    // cout << endl;
    // cout << "width = " << width << endl;
    // cout << "r = " << r << endl;
    // cout << "limit = " << limit << endl;
    // cout << "Total count is " << count << endl;
    
    std::cout.rdbuf(coutbuf); //reset to standard output again
    cout << "width = " << width << endl;
    cout << "r = " << r << endl;
    cout << "limit = " << limit << endl;
    cout << endl << "Total count is " << count << endl;

    return 0;
}