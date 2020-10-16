#include <iostream>
#include "bigint_function_definitions.h"
using namespace std;


int main() {
    bigint a("56654250564056135415631554531554513813");     // big integer initialization with String
    bigint b("60820564691661355463515465564664568");        // big integer initialization with String
    bigint d(956486133);                                    // big integer intialization with Integer
    
    //-----------------------------------------------------
    //-----------------Addition----------------------------
    //-----------------------------------------------------


    bigint c = a + b;                         // Addition, with both operand as bigint
    cout << c << std::endl;     // Output : 56715071128747796771095069997119178381

    c = a + 56242;                            // Addition, with one operand as bigint and other as integer
    cout << c << std::endl;     // Output : 56654250564056135415631554531554570055

    c = 52 + 98;                              // Addition, with both operand as integers.
    cout << c << std::endl;     // Ouput : 150

    c = c + a + b;                            // Addition, with multiple operands
    cout << c << std::endl;     // Output : 56715071128747796771095069997119178531

    //------------------------------------------------------
    //------------------Subtraction-------------------------
    //------------------------------------------------------


    c = a - b;                                 // Subtraction, with both operand as bigint
    cout << c << std::endl;     // Ouput : 56593429999364474060168039065989849245

    c = a - 56242;                            // Subtraction, with one operand as bigint and other as integer
    cout << c << std::endl;     // Output : 56654250564056135415631554531554457571

    c = 52 - 98;                              // Subtraction, with both operand as integers.
    cout << c << std::endl;     // Output : -46

    c = c - a - b;                            // Subtraction, with multiple operands
    cout << c << std::endl;     // Output : -56715071128747796771095069997119178427


    //------------------------------------------------------
    //------------------Multiplication----------------------
    //------------------------------------------------------

    c = a * b;                                 // Multiplication, with both operand as bigint
    cout << c << std::endl;     // Output : 3445743511488768021543787806860750328299778111849236444610289955667677784

    c = a * 56242;                            // Multiplication, with one operand as bigint and other as integer
    cout << c << std::endl;     // Output : 3186348360223645168045949889963688965870746

    c = 52 * 98;                              // Multiplication, with both operand as integers.
    cout << c << std::endl;     // Output : 5096

    c = c * a * b;                            // Multiplication, with multiple operands
    cout << c << std::endl;     // Output : 17559508934546761837787142663762383673015669257983708921734037614082485987264

    //------------------------------------------------------
    //---------------------Division-------------------------
    //------------------------------------------------------

    c = a / b;                                 // Divison, with both operand as bigint
    cout << c << std::endl;     // Output : 931

    c = a / 56242;                            // Divison, with one operand as bigint and other as integer
    cout << c << std::endl;     // Output : 1007329941397107773827949833426167

    c = 98 / 56;                              // Divison, with both operand as integers.
    cout << c << std::endl;     // Output : 1

    c = a / b / c;                            // Divison, with multiple operands
    cout << c << std::endl;     // Output : 931

    //------------------------------------------------------
    //---------------------Modulus--------------------------
    //------------------------------------------------------

    c = a % b;                                 // mod, with both operand as bigint
    cout << c << std::endl;     // Output : 56654250564056135415631554531554513813

    c = a % 56242;                            // mod, with one operand as bigint and other as integer
    cout << c << std::endl;     // Output : 29399

    c = 98 % 56;                              // mod, with both operand as integers.
    cout << c << std::endl;        // output : 42

    c = a % b % c;                            // mod, with multiple operands
    cout << c << std::endl;     // Output : 41

    //------------------------------------------------------
    //-----------------Conditional Statements---------------
    //---Supports:  > , < ,  >= , <= , == , != -------------

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
    

    //-----------------------------------------------------
    //---------------In-built Functions--------------------
    //-----------------------------------------------------


    // Absolute function

    cout << big_abs(b) << std::endl;    // Output : 60820564691661355463515465564664568
    b = to_bigint("-60820564691661355463515465564664568");
    cout << big_abs(b) << std::endl;        // Output : 60820564691661355463515465564664568
    b = big_abs(b);
    cout << b << std::endl;             // Output : 60820564691661355463515465564664568


    // Maximum fuction

    cout << big_max(a, b) << std::endl;          // returns maximum of both bigints
    // Output : 56654250564056135415631554531554513813


    // Minumum function

    cout << big_min(a, b) << std::endl;          // returns minimum of both bigints
    // Output : 60820564691661355463515465564664568


    // Power function

    b = to_bigint("2");
    cout << big_pow(a, b) << std::endl;            // return a to the power b bigint
    // Output : 3209704106974854937901411896655926267350648828646359016173511958974807798969
    b = to_bigint("60820564691661355463515465564664568");


    // Square root function

    cout << big_sqrt(a) << std::endl;               // returns sqrt of bigint
    // Output : 7526901790514881921


    // Logarithmic Functions

    cout << big_log2(a) << std::endl;               // returns log to the base 2 bigint
    // Output : 125

    cout << big_log10(a) << std::endl;              // returns log to the base 10 bigint
    // Output : 37

    cout << big_logwithbase(a, b) << std::endl;         // returns log of 'a' to the base 'b' bigint
    // Output : 1

    b = to_bigint("56");
    cout << big_antilog2(b) << std::endl;           // returns antilog to the base 2 bigint
    // Output : 72057594037927936

    cout << big_antilog10(b) << std::endl;          // returns antilog to the base 10 bigint
    // Output : 100000000000000000000000000000000000000000000000000000000


    // Swapping two bigints

    big_swap(a, b);
    cout << a << "\t" << b << std::endl;    // Output : 56      56654250564056135415631554531554513813

    // Greatest Common Divisor (GCD) or Highest Common factor(HCF) function

    cout << big_gcd(a, b) << std::endl;      // Output : 1


    // Lowest Common Multiple (LCM)

    cout << big_lcm(a, b) << std::endl;     // Output : 3172638031587143583275367053767052773528


    // Factorial Function

    a = to_bigint("15");
    cout << big_fact(a) << std::endl;       // Output : 1307674368000


    // isPrime Function

    a = to_bigint("67");
    b = to_bigint("33");
    cout << big_isPrime(a) << std::endl;      // Output : 1   (true)
    cout << big_isPrime(b) << std::endl;      // Output : 0   (false)


    // Reverse function, which reverses the Number

    a = to_bigint("65894");
    cout << big_reverse(a) << std::endl;            // Output : 49856


    // isPalindrome Function

    cout << big_isPalindrome(a) << std::endl;        // Output : 0  (false)
    a = to_bigint("654456");
    cout << big_isPalindrome(a) << std::endl;        // Output : 1   (true)


    // Increment and Decrement
    
    cout << a << "\t" << ++a << std::endl;              // Output : 654456  654457
    cout << a << "\t" << --a << std::endl;              // Output : 654457  654456

    return 0;
}
