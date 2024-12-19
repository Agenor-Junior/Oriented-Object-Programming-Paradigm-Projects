#include "utils.h"
#include <iostream>

namespace seneca{

// flushes the keyboard
void flushkeys() {
   while (std::cin.get() != '\n');
}

// returns true if user enter y or Y
bool yes() {
   char ch = std::cin.get();
   flushkeys();
   return ch == 'y' || ch == 'Y';
}

// copies src Cstring to des and converts all characters to lowercase
// at the same time.
void toLowerCase(char* des, const char* src) {
   int i = 0;
   while (src[i]) {
      des[i] = src[i];
      if (des[i] >= 'A' && des[i] <= 'Z') {
         des[i] += ('a' - 'A');
      }
      i++;
   }
   des[i] = 0;
}

    
}