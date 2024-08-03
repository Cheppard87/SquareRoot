#include <iostream>
#include <iomanip>
using namespace std;

//Custom square root function (long division method).
long double sqrtDivision(long double num, int precission = 5) {

    if (num < 0) num *= -1;
    if (num >= 1000000000000000000) {
        cout << "TOO BIG!";
        return 0;
    }

    short digit, intRootDigits = 0, i = 1;
    long double nextPair, currRemain = 0;
    unsigned long long int pairs, currRootInt = 0, order = 1, intOrder = 1, pairCountr = 1;

    while(num >= intOrder) {
        intOrder *= 100;
        intRootDigits++;
    }

    do {    
        pairs = (unsigned long long int)((long double)pairCountr / intOrder * pairCountr * num);
        nextPair = ((long double)pairCountr / intOrder * pairCountr * 100) * num - ((long double)pairs * 100);
        currRemain = 100 * currRemain + (short)nextPair;

        digit = 0;
        while ((20 * (long double)currRootInt + digit) * digit <= currRemain) {
            digit++;
        }
        digit--;

        currRemain -= (20 * (long double)currRootInt + digit) * digit;
        currRootInt = 10 * currRootInt + digit;
        if (i > intRootDigits) order *= 10;
        
        if (i == intRootDigits) {
            num -= (unsigned long long int)num;
            intOrder = 100;
            pairCountr = 1;
        }

        pairCountr *= 10;
        i++;
    } while( (i <= (intRootDigits + precission + 1)) && ((currRemain != 0) || (nextPair != 0) || (i <= intRootDigits)) );

    return (currRootInt / (long double) order);
}
    

//Custom square root function (Babylonian method).
long double sqrtBabylonian(long double num, int precision = 5) {

    if (num < 0) num *= -1;

    long double error = 1;
    for(int i = 0; i < precision + 1; i++) {
        error /= 10;
    }
    
    long double currRoot = (num + 1) / 2;

    while ( (currRoot - num / currRoot) > error ) // loop until precision satisfied 
    {
        currRoot = ( (num / currRoot) + currRoot ) / 2;
    }
    return currRoot;
}

int main() {
    int precision = 8;
    long double num;
    
    std::cout << "Enter the desired number to get its square root : ";
    cin >> num;

    long double root;    
    root =  sqrtDivision(num, precision);

    cout << setprecision(precision + to_string((int)root).length());
    cout << root << endl;

    root = sqrtBabylonian(num, precision);
    cout << root << endl;

    return 0;
}.
