#include <iostream>
#include <string.h>
#include <process.h> // for system
#include <limits> // for numeric_limits
#include "utils.h"

using namespace std;

void clear_screen(void) {
  system("cls");
}

void clear_input_buffer(void) {
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void printLine(const char* str) {
  int len = strlen(str);
  cout << endl;
  for(int i = 0; i < len; i++) {
    cout << "-";
  }
  cout << endl;
  cout << str << endl;
  for (int i = 0; i < len; i++) {
    cout << "-";
  }
  cout << endl;
}

void sayHello(void) {
  printLine("Hello World!");
}