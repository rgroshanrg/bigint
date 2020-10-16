# bigint
## Big Integer Library for C++
### 1 Million digits? 1 Billion? 1 Trillion? No Worries. This Library can handle any Integer of any Length.
<img src="https://github.com/rgroshanrg/bigint/blob/main/bigint_image.jpg" alt="drawing" width="500"/>

### bigint is a C++ library which can handle Very very __Big Integers__. It can calculate *factorial* of __1000000...__ it can go any big. It may be useful in *Competitive Coding* and *Scientific Calculations* which deals with very very large Integers. It can also be used in *Decryption* process. It has many *inbuilt functions* which can be very useful.

---

# How to use it?

Download [bigint](https://github.com/rgroshanrg/bigint/blob/main/Big%20Integer%20Library%20in%20Single%20file/bigint.h) header and include in your C++ program.

```c++
#include "bigint.h"     // with proper file path 
```
---

# Declaring and Intializing Variables.

Declartion is done like making object of bigint class.
Intialization can be done by passing *String* or *Integer* or *Long* type at Object creation.

```c++
bigint a("56654250564056135415631554531554513813");     // big integer initialization with String
bigint b("60820564691661355463515465564664568");        // big integer initialization with String
bigint d(956486133);                                    // big integer intialization with Integer
```
---
# Addition

Addition can be done as it is done with general integer types of data.
(*Note : variable's value and declaration will be followed as it goes.*)

```c++
bigint c = a + b;                         // Addition, with both operand as bigint
cout << c << std::endl;     // Output : 56715071128747796771095069997119178381

c = a + 56242;                            // Addition, with one operand as bigint and other as integer
cout << c << std::endl;     // Output : 56654250564056135415631554531554570055

c = 52 + 98;                              // Addition, with both operand as integers.
cout << c << std::endl;     // Ouput : 150

c = c + a + b;                            // Addition, with multiple operands
cout << c << std::endl;     // Output : 56715071128747796771095069997119178531
```

