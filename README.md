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

Addition can be done as it is done with general integer types of variables.
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
---
# Subtraction 

Subtraction can be done as it is done with general integer types variables.

```c++
c = a - b;                                 // Subtraction, with both operand as bigint
cout << c << std::endl;     // Ouput : 56593429999364474060168039065989849245

c = a - 56242;                            // Subtraction, with one operand as bigint and other as integer
cout << c << std::endl;     // Output : 56654250564056135415631554531554457571

c = 52 - 98;                              // Subtraction, with both operand as integers.
cout << c << std::endl;     // Output : -46

c = c - a - b;                            // Subtraction, with multiple operands
cout << c << std::endl;     // Output : -56715071128747796771095069997119178427
```

---

# Multiplication

Multiplication can be done as it is done with general integer types variables.

```c++
c = a * b;                                 // Multiplication, with both operand as bigint
cout << c << std::endl;     // Output : 3445743511488768021543787806860750328299778111849236444610289955667677784

c = a * 56242;                            // Multiplication, with one operand as bigint and other as integer
cout << c << std::endl;     // Output : 3186348360223645168045949889963688965870746

c = 52 * 98;                              // Multiplication, with both operand as integers.
cout << c << std::endl;     // Output : 5096

c = c * a * b;                            // Multiplication, with multiple operands
cout << c << std::endl;     // Output : 17559508934546761837787142663762383673015669257983708921734037614082485987264
```
---

# Division

Division can be done as it is done with general integer types variables.

```c++
c = a / b;                                 // Divison, with both operand as bigint
cout << c << std::endl;     // Output : 931

c = a / 56242;                            // Divison, with one operand as bigint and other as integer
cout << c << std::endl;     // Output : 1007329941397107773827949833426167

c = 98 / 56;                              // Divison, with both operand as integers.
cout << c << std::endl;     // Output : 1

c = a / b / c;                            // Divison, with multiple operands
cout << c << std::endl;     // Output : 931
```

---

# Mod

Mod can be done as it is done with general integer types variables.

```c++
c = a % b;                                 // mod, with both operand as bigint
cout << c << std::endl;     // Output : 56654250564056135415631554531554513813

c = a % 56242;                            // mod, with one operand as bigint and other as integer
cout << c << std::endl;     // Output : 29399

c = 98 % 56;                              // mod, with both operand as integers.
cout << c << std::endl;        // output : 42

c = a % b % c;                            // mod, with multiple operands
cout << c << std::endl;     // Output : 41
```
---

# Conditional Statements

Conditionals can be used as it is done with general integer types variables.
Supports :  *>* , *<* ,  *>=* , *<=* , *==* , *!=*

```c++
if(a > b) {
    cout << "a is greater than b" << std::endl;     // It executes
} else {
    cout << "a is smaller than b" << std::endl;     // It does not executes
}

if(a != b) {
    cout << "a is not equal to b" << std::endl;     // It executes
} else {
    cout << "a is equal to b" << std::endl;         // It does not executes
}
```

---

# In-built Functions

## big_abs(bigint)  -   absolute function

It takes bigint as argument and return type is also *bigint*.

```c++
cout << big_abs(b) << std::endl;    // Output : 60820564691661355463515465564664568
b = to_bigint("-60820564691661355463515465564664568");
cout << big_abs(b) << std::endl;        // Output : 60820564691661355463515465564664568
b = big_abs(b);
cout << b << std::endl;             // Output : 60820564691661355463515465564664568
```

---

## big_max(bigint, bigint)  -   maximum funtion

It takes two bigint as arguments and return type is also *bigint*, returns the maximum of both bigints.

```c++
cout << big_max(a, b) << std::endl;          // returns maximum of both bigints
// Output : 56654250564056135415631554531554513813
```

---



