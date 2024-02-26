# big_int

This project is a C++ library for handling arbitrarily large integers, commonly known as big integers.
It provides functionality to perform arithmetic operations, comparison operations, and other operations on integers that exceed the size limits of built-in integer types.

## Usage

### Example of usage

      #include <iostream>
      #include "bigint.h"
      
      int main() {
          bigint num1("12345678901234567890");
          bigint num2("-98765432109876543210");
      
          bigint sum = num1 + num2;
          std::cout << "Sum: " << sum << std::endl;
      
          return 0;
      }
      
