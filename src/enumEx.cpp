#include <iostream>
#include "utils.h"
#include "enumEx.h"

using namespace std;

// 1. Unscoped Enum (traditional enum)
// The enumerator names (RED, GREEN, BLUE) are in the same scope as the enum itself.
// This can lead to name clashes.
enum Color {
    RED,    // 0
    GREEN,  // 1
    BLUE    // 2
};

// Another unscoped enum. Name clash would occur if we used RED, GREEN, BLUE again.
enum class TrafficLight {
    RED,     // 0
    YELLOW,  // 1
    GREEN    // 2
};


// 2. Scoped Enum (enum class) - Recommended in modern C++
// The enumerator names are scoped within the enum's name.
// This prevents name clashes and provides stronger type safety.
enum class Planet {
    MERCURY,
    VENUS,
    EARTH,
    MARS
};

// You can also specify the underlying type for an enum class.
enum class ErrorCode : unsigned int {
    NONE = 0,
    WARNING = 1,
    CRITICAL = 2,
    FATAL = 3
};

void useUnscopedEnum() {
    cout << "--- Unscoped Enum Example ---" << endl;
    Color myColor = BLUE;

    // Unscoped enums implicitly convert to integers.
    int colorValue = myColor;
    cout << "My color is: " << myColor << " (integer value: " << colorValue << ")" << endl;

    if (myColor == BLUE) {
        cout << "The color is BLUE." << endl;
    }
    cout << endl;
}

void useScopedEnum() {
    cout << "--- Scoped Enum (enum class) Example ---" << endl;
    Planet myPlanet = Planet::EARTH;

    // Scoped enums do NOT implicitly convert to integers.
    // int planetValue = myPlanet; // This would cause a compile error!

    // You must use an explicit cast if you need the integer value.
    int planetValue = static_cast<int>(myPlanet);
    cout << "My planet is Earth (integer value: " << planetValue << ")" << endl;

    // Comparisons are type-safe.
    if (myPlanet == Planet::EARTH) {
        cout << "We are on Earth." << endl;
    }

    // You can't compare against an integer directly.
    // if (myPlanet == 2) { // This would also cause a compile error!
    //     cout << "This won't compile." << endl;
    // }
    cout << endl;
}


void enumEx(void) {
    printLine("Enums (열거형) Start");

    useUnscopedEnum();
    useScopedEnum();

    printLine("Enums (열거형) End");
}