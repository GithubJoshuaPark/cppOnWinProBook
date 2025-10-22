#include <iostream>
#include "utils.h"
#include "preProcessEx.h"

// --- #define ---
// 1. Object-like macro for a constant
#define PI 3.14159
#define MESSAGE "Hello, World!"

// 2. Function-like macro
// Note the extra parentheses to avoid operator precedence issues.
#define SQUARE(x) ((x) * (x))

// --- Conditional Compilation ---
// We can define a macro to control which code gets compiled.
// Try commenting this out to see the difference.
#define DEBUG_MODE

// We can also set a value to it
#define VERSION 2

using namespace std;

void preProcessEx(void) {
    printLine("Preprocessor Directives Start");

    // --- Using #define ---
    cout << "--- #define examples ---" << endl;
    cout << "Value of PI: " << PI << endl;
    cout << "Message: " << MESSAGE << endl;
    cout << "Square of 5: " << SQUARE(5) << endl;
    // Be careful with function-like macros!
    // SQUARE(2+3) becomes ((2+3) * (2+3)) which is correct.
    // Without outer parentheses, it would be 2+3*2+3 = 11, which is wrong.
    cout << "Square of (2+3): " << SQUARE(2 + 3) << endl << endl;


    // --- Using Conditional Compilation ---
    cout << "--- Conditional Compilation examples ---" << endl;

    // 1. #ifdef / #endif
    // This block is included only if DEBUG_MODE is defined.
#ifdef DEBUG_MODE
    cout << "DEBUG_MODE is defined. This is a debug message." << endl;
#endif

    // 2. #ifndef / #endif
    // This block is included only if RELEASE_MODE is NOT defined.
#ifndef RELEASE_MODE
    cout << "RELEASE_MODE is not defined." << endl;
#endif

    // 3. #if / #elif / #else / #endif
    // This allows for more complex conditions.
#if VERSION == 1
    cout << "Compiling for Version 1." << endl;
#elif VERSION == 2
    cout << "Compiling for Version 2." << endl;
#else
    cout << "Compiling for an unknown version." << endl;
#endif
    cout << endl;


    // --- Using Predefined Macros ---
    cout << "--- Predefined Macros ---" << endl;
    cout << "This code is in file: " << __FILE__ << endl;
    cout << "This is line number: " << __LINE__ << endl;
    cout << "Compiled on: " << __DATE__ << " at " << __TIME__ << endl;


    printLine("Preprocessor Directives End");
}