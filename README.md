<h1 align="center">BigDecimalInt</h1>
<h3 align="center">Integer with arbitrary size class in C++</h3>

---
**Made by:** ***[Mina Albert](https://github.com/minaalbert33) - [Rania Khlaed](https://github.com/raniakhaled15) - [Adham Adel](https://github.com/AdhamAD02)***

## Overview
* Class for handling big decimal Integers in C++.
* **Supervised by** :Dr: Mohammed El-Ramly in Object Oreinted Programming course (CS213)
---
## Features

### Operators

* #### Assignment: `=`
    Right-hand-side operand can be `BigDecimalInt`,
    `int` up to `long long ` or `string`

  ```c++
  BigDecimalInt num1, num2;
  num1 = 1234567890;
  num1 = "123456789012345678901234567890";
  num1 = num2;

  ```


* #### Binary arithmetic: `+`, `-`
  ```c++
  BigDecimalInt num1, num2;
  num1 = num2 + num2;
  num1 = num2 - "123456789012345678901234567890";
  num1 = num1 - 1231345;

  ```

* #### Arithmetic-assignment: `+=`, `-=`

  ```c++
  BigDecimalInt num1, num2;
  num1 += num2;
  num1 -= 1234567890;
  num1 -= "1234567890";

  ```


* #### Increment & Decrement : `++`, `--`
* 
  ```c++
  BigDecimalInt num1, num2;
  num1 = ++num2;   // pre-increment
  num1 = --num2;   // pre-decrement
  num1 = num2++;   // post-increment
  num1 = num2--;   // post-decrement

  ```


* #### Comparison: `<`, `>`, `==`, `!=`, `<=`,`>=`

  ```c++
  if ( num1 > num2
      || num1 < num2
      || num1 <= num3
      || num1 >= num2
      || num1 == num3
      || num1 != num3
      ...            ) {
      
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

[//]: # ()
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