<h1 align="center">BigDecimalInt</h1>
<h3 align="center">Integer with arbitrary size class in C++</h3>

---
**Made by:** ***[Mina Albert](https://github.com/minaalbert33) - [Rania Khlaed](https://github.com/raniakhaled15) - [Adham Adel](https://github.com/AdhamAD02)***

## Overview
* Class for handling big decimal Integers in C++.
* **Supervised by** :Dr: Mohammed El-Ramly in Object Oreinted Programming (CS213)
---
## Usage

1. Download the [Header File][header-link] to a directory within
    your include path. Then `#include` it in your code:

    ```c++
    #include "BigDecimalInt.h"   // Actual include path may differ
    ```
2. Add the [Implementation file (BigDecimalInt.cpp)][implementation-link] to the same directory of header file
1. Create objects of the `BigDecimalInt` class, and here you go!

    ```c++
    BigDecimalInt num1("123456789012345678901234567890");
    BigDecimalInt num2("113456789011345678901134567890");
    BigDecimalInt num3 = num2_t1 + num1_t1;
    //236913578023691357802369135780
    cout << "num2 + num1 = " << num3 << endl;
    ```
---
## Features

### Operators

[//]: # (* #### Assignment: `=`)

[//]: # ()
[//]: # (  The second operand can either be a `BigInt`, an integer &#40;up to `long long`&#41;)

[//]: # (  or a string &#40;`std::string` or a string literal&#41;.)

[//]: # ()
[//]: # (  ```c++)

[//]: # (  big1 = 1234567890;)

[//]: # (  big1 = "123456789012345678901234567890";)

[//]: # (  big1 = big2;)

[//]: # (  ```)

[//]: # (* #### Unary arithmetic: `+`, `-`)

[//]: # ()
[//]: # (  ```c++)

[//]: # (  big1 = +big2;   // doesn't return the absolute value)

[//]: # (  big1 = -big2;)

[//]: # (  ```)

[//]: # (* #### Binary arithmetic: `+`, `-`, `*`, `/`, `%`)

[//]: # ()
[//]: # (  One of the operands has to be a `BigInt` and the other can be a `BigInt`, an)

[//]: # (  integer &#40;up to `long long`&#41; or a string &#40;`std::string` or a string literal&#41;.)

[//]: # ()
[//]: # (  ```c++)

[//]: # (  big1 = big2 + 1234567890;)

[//]: # (  big1 = big2 - "123456789012345678901234567890";)

[//]: # (  big1 = big2 * big3;)

[//]: # (  big1 = 1234567890 / big2;)

[//]: # (  big1 = "123456789012345678901234567890" % big2;)

[//]: # (  ```)
[//]: # ()
[//]: # (* #### Arithmetic-assignment: `+=`, `-=`, `*=`, `/=`, `%=`)

[//]: # ()
[//]: # (  The second operand can either be a `BigInt`, an integer &#40;up to `long long`&#41;)

[//]: # (  or a string &#40;`std::string` or a string literal&#41;.)

[//]: # ()
[//]: # (  ```c++)

[//]: # (  big1 += big2;)

[//]: # (  big1 -= 1234567890;)

[//]: # (  big1 *= "123456789012345678901234567890";)

[//]: # (  big1 /= big2;)

[//]: # (  big1 %= 1234567890;)

[//]: # (  ```)

[//]: # ()
[//]: # (* #### Increment and decrement: `++`, `--`)

[//]: # ()
[//]: # (  ```c++)

[//]: # (  big1 = ++big2;   // pre-increment)

[//]: # (  big1 = --big2;   // pre-decrement)

[//]: # ()
[//]: # (  big1 = big2++;   // post-increment)

[//]: # (  big1 = big2--;   // post-decrement)

[//]: # (  ```)

[//]: # ()
* #### Relational: `<`, `>`, `==`, `!=`

[//]: # (  One of the operands has to be a `BigInt` and the other can be a `BigInt`, an)

[//]: # (  integer &#40;up to `long long`&#41; or a string &#40;`std::string` or a string literal&#41;.)

  ```c++
  if ( num1 > num2
      || num1 < num2
      || num1 == num3) {
      ...
  }
  ```

* #### I/O stream: `<<`, `>>`

  ```c++
  std::cin >> num1 >> num1;
  std::cout << num1 << ", " << num1 << '\n';
  ```

[//]: # (### Functions)

[//]: # ()
[//]: # (* #### Conversion: `to_string`, `to_int`, `to_long`, `to_long_long`)

[//]: # ()
[//]: # (  Convert a `BigInt` to either a `string`, `int`, `long`, or `long long`.)

[//]: # ()
[//]: # (  **Note**: If the `BigInt` is beyond the range of the target type, an)

[//]: # (  [out_of_range exception][out_of_range-exception] is thrown.)

[//]: # ()
[//]: # (  ```c++)

[//]: # (  some_str = big1.to_string&#40;&#41;;)

[//]: # ()
[//]: # (  some_int = big1.to_int&#40;&#41;;)

[//]: # ()
[//]: # (  some_long = big1.to_long&#40;&#41;;)

[//]: # ()
[//]: # (  some_long_long = big1.to_long_long&#40;&#41;;)

[//]: # (  ```)



[implementation-link]: https://github.com/faheel/BigInt/blob/master/.github/CONTRIBUTING.md
[header-link]: https://github.com/faheel/BigInt/releases/download/v0.5.0-dev/BigInt.hpp
