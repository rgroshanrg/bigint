/*
    bigint class.h

    bigint Library for C++

    MIT License

    Created by Roshan Gupta on 16-10-2020
    Copyright (c) 2020 Roshan Gupta

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

#pragma once

#include <string>
#include <sstream>
#include <vector>
#include <math.h>
#include <limits>

class bigint {
    private: 
        std::string str; // only data memeber for strong Big Integer as String. [For signed int, str[0] = '-']
        

        // Function Definitions for Internal Uses

        static std::string trim(std::string);
        static std::string add(std::string, std::string);
        static std::string subtract(std::string, std::string);
        static std::string multiply(std::string, std::string);
        static std::string divide(std::string, std::string);

        static std::string mod(std::string, std::string);
        static std::string shortDivide(std::string, unsigned long long int);
        static std::string maximum(std::string, std::string);
        static bool is_maximum(std::string, std::string);
        static bool is_strictlyMaximum(std::string, std::string);
        static std::string minimum(std::string, std::string);
        static bool is_minimum(std::string, std::string);
        static bool is_strictlyMinimum(std::string, std::string);
        static bool is_bigint(std::string);

        // Public Property

        static std::string abs(std::string);
        static std::string pow(std::string, std::string);
        static std::string sqrt(std::string);
        static std::string log2(std::string);
        static std::string log10(std::string);
        static std::string logwithbase(std::string, std::string);
        static std::string antilog2(std::string);
        static std::string antilog10(std::string);
        static void swap(std::string&, std::string&);
        static std::string reverse(std::string);
        static std::string gcd(std::string, std::string);
        static std::string lcm(std::string, std::string);
        static std::string fact(std::string);
        static bool isPalindrome(std::string);
        static bool isPrime(std::string);        


    public: 
        // Constructors for big int.
        bigint() {
            str = '0';  //default value
        }
        bigint(std::string s) {
            if(!is_bigint(s))
                throw std::runtime_error("Invalid Big Integer has been fed.");   // if the input string is not valid number.
            str = s;
        }
        bigint(long long int n) {
            str = std::to_string(n);
        }
        bigint(int n) {
            str = std::to_string(n);
        }
        bigint(long int n) {
            str = std::to_string(n);
        }
        bigint(const bigint &n) {
            str = n.str;
        }

        // operator overloading for output stream {<<}
        friend std::ostream &operator << (std::ostream& stream, const bigint &n) {
            stream << n.str;
            return stream;
        }

        // operator overloading for input stream {>>}
        friend std::istream &operator >> (std::istream& stream, bigint &n) {
            stream >> n.str;
            return stream;
        }

        /* Operator {+} Overloadings, for different kind of 
        parameter for the programmer's convinience  */

        bigint operator + (bigint const &n) {
            bigint ans;
            ans.str = add(str, n.str);
            return ans;
        }        
        friend bigint operator + (bigint const &n1, int n2) {
            bigint ans;
            ans.str = add(n1.str, std::to_string(n2));
            return ans;
        }
        friend bigint operator + (int n1, bigint const &n2) {
            bigint ans;
            ans.str = add(n2.str, std::to_string(n1));
            return ans;
        }
        friend bigint operator + (bigint const &n1, long int n2) {
            bigint ans;
            ans.str = add(n1.str, std::to_string(n2));
            return ans;
        }
        friend bigint operator + (long int n1, bigint const &n2) {
            bigint ans;
            ans.str = add(n2.str, std::to_string(n1));
            return ans;
        }
        friend bigint operator + (bigint const &n1, long long int n2) {
            bigint ans;
            ans.str = add(n1.str, std::to_string(n2));
            return ans;
        }
        friend bigint operator + (long long int n1, bigint const &n2) {
            bigint ans;
            ans.str = add(n2.str, std::to_string(n1));
            return ans;
        }

        // Extra shortcut feature

        bigint& operator += (bigint const n) {
            (*this).str = add((*this).str, n.str);
            return (*this);
        }
        
        

        /* Operator {-} Overloadings, for different kind of 
        parameter for the programmer's convinience  */

        bigint operator - (bigint const &n) {
            bigint ans;
            ans.str = subtract(str, n.str);
            return ans;
        }

        friend bigint operator - (bigint const &n1, int n2) {
            bigint ans;
            ans.str = subtract(n1.str, std::to_string(n2));
            return ans;
        }
        friend bigint operator - (int n1, bigint const &n2) {
            bigint ans;
            ans.str = subtract(std::to_string(n1), n2.str);
            return ans;
        }
        friend bigint operator - (bigint const &n1, long int n2) {
            bigint ans;
            ans.str = subtract(n1.str, std::to_string(n2));
            return ans;
        }
        friend bigint operator - (long int n1, bigint const &n2) {
            bigint ans;
            ans.str = subtract(std::to_string(n1), n2.str);
            return ans;
        }
        friend bigint operator - (bigint const &n1, long long int n2) {
            bigint ans;
            ans.str = subtract(n1.str, std::to_string(n2));
            return ans;
        }
        friend bigint operator - (long long int n1, bigint const &n2) {
            bigint ans;
            ans.str = subtract(std::to_string(n1), n2.str);
            return ans;
        }

        // Extra shortcut feature

        bigint& operator -= (bigint const n) {
            (*this).str = subtract((*this).str, n.str);
            return (*this);
        }

        /* Operator {*} Overloadings, for different kind of 
        parameter for the programmer's convinience  */

        bigint operator * (bigint const &n) {
            bigint ans;
            ans.str = multiply(str, n.str);
            return ans;
        }
        friend bigint operator * (bigint const &n1, int n2) {
            bigint ans;
            ans.str = multiply(n1.str, std::to_string(n2));
            return ans;
        }
        friend bigint operator * (int n1, bigint const &n2) {
            bigint ans;
            ans.str = multiply(std::to_string(n1), n2.str);
            return ans;
        }
        friend bigint operator * (bigint const &n1, long int n2) {
            bigint ans;
            ans.str = multiply(n1.str, std::to_string(n2));
            return ans;
        }
        friend bigint operator * (long int n1, bigint const &n2) {
            bigint ans;
            ans.str = multiply(std::to_string(n1), n2.str);
            return ans;
        }
        friend bigint operator * (bigint const &n1, long long int n2) {
            bigint ans;
            ans.str = multiply(n1.str, std::to_string(n2));
            return ans;
        }
        friend bigint operator * (long long int n1, bigint const &n2) {
            bigint ans;
            ans.str = multiply(std::to_string(n1), n2.str);
            return ans;
        }
        // Extra shortcut feature

        bigint& operator *= (bigint const n) {
            (*this).str = multiply((*this).str, n.str);
            return (*this);
        }

        /* Operator {/} Overloadings, for different kind of 
        parameter for the programmer's convinience  */

        bigint operator / (bigint const &n) {
            bigint ans;
            ans.str = divide(str, n.str);
            return ans;
        }
        friend bigint operator / (bigint const &n1, int n2) {
            bigint ans;
            ans.str = divide(n1.str, std::to_string(n2));
            return ans;
        }
        friend bigint operator / (int n1, bigint const &n2) {
            bigint ans;
            ans.str = divide(std::to_string(n1), n2.str);
            return ans;
        }
        friend bigint operator / (bigint const &n1, long int n2) {
            bigint ans;
            ans.str = divide(n1.str, std::to_string(n2));
            return ans;
        }
        friend bigint operator / (long int n1, bigint const &n2) {
            bigint ans;
            ans.str = divide(std::to_string(n1), n2.str);
            return ans;
        }
        friend bigint operator / (bigint const &n1, long long int n2) {
            bigint ans;
            ans.str = divide(n1.str, std::to_string(n2));
            return ans;
        }
        friend bigint operator / (long long int n1, bigint const &n2) {
            bigint ans;
            ans.str = divide(std::to_string(n1), n2.str);
            return ans;
        }

        // Extra shortcut feature

        bigint& operator /= (bigint const n) {
            (*this).str = divide((*this).str, n.str);
            return (*this);
        }

        /* Operator {%} Overloadings, for different kind of 
        parameter for the programmer's convinience  */

        bigint operator % (bigint const &n) {
            bigint ans;
            ans.str = mod(str, n.str);
            return ans;
        }
        friend bigint operator % (bigint const &n1, int n2) {
            bigint ans;
            ans.str = mod(n1.str, std::to_string(n2));
            return ans;
        }
        friend bigint operator % (int n1, bigint const &n2) {
            bigint ans;
            ans.str = mod(std::to_string(n1), n2.str);
            return ans;
        }
        friend bigint operator % (bigint const &n1, long int n2) {
            bigint ans;
            ans.str = mod(n1.str, std::to_string(n2));
            return ans;
        }
        friend bigint operator % (long int n1, bigint const &n2) {
            bigint ans;
            ans.str = mod(std::to_string(n1), n2.str);
            return ans;
        }
        friend bigint operator % (bigint const &n1, long long int n2) {
            bigint ans;
            ans.str = mod(n1.str, std::to_string(n2));
            return ans;
        }
        friend bigint operator % (long long int n1, bigint const &n2) {
            bigint ans;
            ans.str = mod(std::to_string(n1), n2.str);
            return ans;
        }
        
        // Extra shortcut feature
        
        bigint& operator %= (bigint const n) {
            (*this).str = mod((*this).str, n.str);
            return (*this);
        }

        //-------------------------------------------------
        //------------Increment and Decrement--------------
        //-------------------------------------------------

        /* Operator {++} Overloadings
        for the pre incremention  */
        bigint& operator ++ () {
            (*this).str = add((*this).str, "1"); 
            return (*this);
        }
        /* Operator {++} Overloadings
        for the post incremention  */
        bigint operator ++ (int) {
            (*this).str = add((*this).str, "1"); 
            return (*this);
        }

        /* Operator {--} Overloadings
        for the pre decremention  */
        bigint& operator -- () {
            (*this).str = subtract((*this).str, "1");
            return (*this);
        }

        /* Operator {--} Overloadings
        for the post incremention  */
        bigint operator -- (int) {
            (*this).str = subtract((*this).str, "1"); 
            return (*this);
        }

        //-------------------------------------------------
        //------------Conditional Operators----------------
        //-------------------------------------------------

        /* Operator {>} Overloadings, for different kind of 
        parameter for the programmer's convinience  */

        bool operator > (bigint const &n) {
            return is_strictlyMaximum(str, n.str);
        }
        friend bool operator > (bigint const &n1, int n2) {
            return is_strictlyMaximum(n1.str, std::to_string(n2));
        }
        friend bool operator > (int n1, bigint const &n2) {
            return is_strictlyMaximum(std::to_string(n1), n2.str);
        }
        friend bool operator > (bigint const &n1, long int n2) {
            return is_strictlyMaximum(n1.str, std::to_string(n2));
        }
        friend bool operator > (long int n1, bigint const &n2) {
            return is_strictlyMaximum(std::to_string(n1), n2.str);
        }
        friend bool operator > (bigint const &n1, long long int n2) {
            return is_strictlyMaximum(n1.str, std::to_string(n2));
        }
        friend bool operator > (long long int n1, bigint const &n2) {
            return is_strictlyMaximum(std::to_string(n1), n2.str);
        }

        /* Operator {<} Overloadings, for different kind of 
        parameter for the programmer's convinience  */

        bool operator < (bigint const &n) {
            return is_strictlyMinimum(str, n.str);
        }
        friend bool operator < (bigint const &n1, int n2) {
            return is_strictlyMinimum(n1.str, std::to_string(n2));
        }
        friend bool operator < (int n1, bigint const &n2) {
            return is_strictlyMinimum(std::to_string(n1), n2.str);
        }
        friend bool operator < (bigint const &n1, long int n2) {
            return is_strictlyMinimum(n1.str, std::to_string(n2));
        }
        friend bool operator < (long int n1, bigint const &n2) {
            return is_strictlyMinimum(std::to_string(n1), n2.str);
        }
        friend bool operator < (bigint const &n1, long long int n2) {
            return is_strictlyMinimum(n1.str, std::to_string(n2));
        }
        friend bool operator < (long long int n1, bigint const &n2) {
            return is_strictlyMinimum(std::to_string(n1), n2.str);
        }

        /* Operator {>=} Overloadings, for different kind of 
        parameter for the programmer's convinience  */

        bool operator >= (bigint const &n) {
            return is_maximum(str, n.str);
        }
        friend bool operator >= (bigint const &n1, int n2) {
            return is_maximum(n1.str, std::to_string(n2));
        }
        friend bool operator >= (int n1, bigint const &n2) {
            return is_maximum(std::to_string(n1), n2.str);
        }
        friend bool operator >= (bigint const &n1, long int n2) {
            return is_maximum(n1.str, std::to_string(n2));
        }
        friend bool operator >= (long int n1, bigint const &n2) {
            return is_maximum(std::to_string(n1), n2.str);
        }
        friend bool operator >= (bigint const &n1, long long int n2) {
            return is_maximum(n1.str, std::to_string(n2));
        }
        friend bool operator >= (long long int n1, bigint const &n2) {
            return is_maximum(std::to_string(n1), n2.str);
        }

        /* Operator {<=} Overloadings, for different kind of 
        parameter for the programmer's convinience  */

        bool operator <= (bigint const &n) {
            return is_minimum(str, n.str);
        }
        friend bool operator <= (bigint const &n1, int n2) {
            return is_minimum(n1.str, std::to_string(n2));
        }
        friend bool operator <= (int n1, bigint const &n2) {
            return is_minimum(std::to_string(n1), n2.str);
        }
        friend bool operator <= (bigint const &n1, long int n2) {
            return is_minimum(n1.str, std::to_string(n2));
        }
        friend bool operator <= (long int n1, bigint const &n2) {
            return is_minimum(std::to_string(n1), n2.str);
        }
        friend bool operator <= (bigint const &n1, long long int n2) {
            return is_minimum(n1.str, std::to_string(n2));
        }
        friend bool operator <= (long long int n1, bigint const &n2) {
            return is_minimum(std::to_string(n1), n2.str);
        }


        /* Operator {==} Overloadings, for different kind of 
        parameter for the programmer's convinience  */

        bool operator ==(bigint const &n) {
            return (*this).str == n.str;
        }
        friend bool operator == (bigint const &n1, int n2) {
            return n1.str == std::to_string(n2);
        }
        friend bool operator == (int n1, bigint const &n2) {
            return std::to_string(n1) == n2.str;
        }
        friend bool operator == (bigint const &n1, long int n2) {
            return n1.str == std::to_string(n2);
        }
        friend bool operator == (long int n1, bigint const &n2) {
            return std::to_string(n1) == n2.str;
        }
        friend bool operator == (bigint const &n1, long long int n2) {
            return n1.str == std::to_string(n2);
        }
        friend bool operator == (long long int n1, bigint const &n2) {
            return std::to_string(n1) == n2.str;
        }


        /* Operator {!=} Overloadings, for different kind of 
        parameter for the programmer's convinience  */

        bool operator !=(bigint const &n) {
            return (*this).str != n.str;
        }
        friend bool operator != (bigint const &n1, int n2) {
            return n1.str != std::to_string(n2);
        }
        friend bool operator != (int n1, bigint const &n2) {
            return std::to_string(n1) != n2.str;
        }
        friend bool operator != (bigint const &n1, long int n2) {
            return n1.str != std::to_string(n2);
        }
        friend bool operator != (long int n1, bigint const &n2) {
            return std::to_string(n1) != n2.str;
        }
        friend bool operator != (bigint const &n1, long long int n2) {
            return n1.str != std::to_string(n2);
        }
        friend bool operator != (long long int n1, bigint const &n2) {
            return std::to_string(n1) != n2.str;
        }

        //-----------------------------------------------------------
        //--------Function Definitions for External Uses-------------
        //-----------------------------------------------------------

        
        static bigint _big_max(bigint &a, bigint &b) {     // returns the maximum value between two Big Integers.
            bigint ans;
            ans.str = maximum(a.str, b.str);
            return ans;
        }
        static bigint _big_min(bigint &a, bigint &b) {      // returns the minimum value between two Big Integers.
            bigint ans;
            ans.str = minimum(a.str, b.str);
            return ans;
        }        
        static bigint _big_abs(bigint &a) {                 // returns the absolute value of Big Integer.
            bigint ans;
            ans.str = abs(a.str);
            return ans;
        }
        static bigint _big_pow(bigint &a, bigint &b) {      // returns the power value between two Big Integers i.e., a^b, ^ -> power
            bigint ans;
            ans.str = pow(a.str, b.str);
            return ans;
        }
        static bigint _big_sqrt(bigint &a) {                // returns the square root value of Big Integer.
            bigint ans;
            ans.str = sqrt(a.str);
            return ans;
        }
        static bigint _big_log2(bigint &a) {                // returns the log of Big Integer to the base of 2.
            bigint ans;
            ans.str = log2(a.str);
            return ans;
        }
        static bigint _big_log10(bigint &a) {               // returns the log of Big Integer to the base of 10.
            bigint ans;
            ans.str = log10(a.str);
            return ans;
        }
        static bigint _big_logwithbase(bigint &a, bigint &b) {  // returns the log of Big Integer(a) to the base of (b).
            bigint ans;
            ans.str = logwithbase(a.str, b.str);
            return ans;
        }
        static bigint _big_antilog2(bigint &a) {        // returns the antilog of Big Integer to the base of 2.
            bigint ans;
            ans.str = antilog2(a.str);
            return ans;
        }
        static bigint _big_antilog10(bigint &a) {       // returns the antilog of Big Integer to the base of 10.
            bigint ans;
            ans.str = antilog10(a.str);
            return ans;
        }
        static void _big_swap(bigint &a, bigint &b) {     // swaps the two Big Integers.
            swap(a.str, b.str);
        }
        static bigint _big_reverse(bigint &a) {             //Reverses the Big Integer.
            bigint ans;
            ans.str = reverse(a.str);
            return ans;
        }
        static bigint _big_gcd(bigint &a, bigint &b) {         // returns the gcd of Big Integers a and b.
            bigint ans;
            ans.str = gcd(a.str, b.str);
            return ans;
        }
        static bigint _big_lcm(bigint &a, bigint &b) {          // returns the lcm of Big Integers a and b.
            bigint ans;
            ans.str = lcm(a.str, b.str);
            return ans;
        }
        static bigint _big_fact(bigint &a) {                    // returns the factorial of Big Integer.
            bigint ans;
            ans.str = fact(a.str);
            return ans;
        }
        static bool _big_isPalindrome(bigint &a) {              // Check if the Big Integer is Palindromic Integer.
            return isPalindrome(a.str);
        }
        static bool _big_isPrime(bigint &a) {                   // Check if the Big Integer is Prime Integer.
            return isPrime(a.str);
        }


        // to biginteger functions

        static bigint _to_bigint(std::string s) {
            bigint ans;
            ans.str = s;
            return ans;
        }
        static bigint _to_bigint(int n) {
            bigint ans;
            ans.str = std::to_string(n);
            return ans;
        }
        static bigint _to_bigint(long int n) {
            bigint ans;
            ans.str = std::to_string(n);
            return ans;
        }
        static bigint _to_bigint(long long int n) {
            bigint ans;
            ans.str = std::to_string(n);
            return ans;
        }
};