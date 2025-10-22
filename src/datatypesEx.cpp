#include <iostream>
#include <limits>
#include "utils.h"
#include "datatypesEx.h"

using namespace std;

void datatypesEx(void) {
    printLine("Data Types (데이터 타입) Start");

    // --- Integer Types ---
    cout << "--- Integer Types ---" << endl;
    cout << "Size of short: " << sizeof(short) << " bytes" << endl;
    cout << "Min value for short: " << numeric_limits<short>::min() << endl;
    cout << "Max value for short: " << numeric_limits<short>::max() << endl << endl;

    cout << "Size of int: " << sizeof(int) << " bytes" << endl;
    cout << "Min value for int: " << numeric_limits<int>::min() << endl;
    cout << "Max value for int: " << numeric_limits<int>::max() << endl << endl;

    cout << "Size of long: " << sizeof(long) << " bytes" << endl;
    cout << "Min value for long: " << numeric_limits<long>::min() << endl;
    cout << "Max value for long: " << numeric_limits<long>::max() << endl << endl;

    cout << "Size of long long: " << sizeof(long long) << " bytes" << endl;
    cout << "Min value for long long: " << numeric_limits<long long>::min() << endl;
    cout << "Max value for long long: " << numeric_limits<long long>::max() << endl << endl;

    cout << "Size of unsigned int: " << sizeof(unsigned int) << " bytes" << endl;
    cout << "Min value for unsigned int: " << numeric_limits<unsigned int>::min() << endl;
    cout << "Max value for unsigned int: " << numeric_limits<unsigned int>::max() << endl << endl;

    // --- Floating-Point Types ---
    cout << "--- Floating-Point Types ---" << endl;
    cout << "Size of float: " << sizeof(float) << " bytes" << endl;
    cout << "Min value for float: " << numeric_limits<float>::lowest() << endl;
    cout << "Max value for float: " << numeric_limits<float>::max() << endl << endl;

    cout << "Size of double: " << sizeof(double) << " bytes" << endl;
    cout << "Min value for double: " << numeric_limits<double>::lowest() << endl;
    cout << "Max value for double: " << numeric_limits<double>::max() << endl << endl;

    // --- Character Type ---
    cout << "--- Character Type ---" << endl;
    char myChar = 'A';
    cout << "Size of char: " << sizeof(char) << " byte" << endl;
    cout << "Value of myChar: " << myChar << endl << endl;

    // --- Boolean Type ---
    cout << "--- Boolean Type ---" << endl;
    bool myBool = true;
    cout << "Size of bool: " << sizeof(bool) << " byte" << endl;
    cout << "Value of myBool (true): " << myBool << endl;
    myBool = false;
    cout << "Value of myBool (false): " << myBool << endl << endl;

    printLine("Data Types (데이터 타입) End");
}