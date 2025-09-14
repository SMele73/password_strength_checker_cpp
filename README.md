# Password Strength Checker (C++)

A C++ application that evaluates the strength of a password based on length and character variety.  
The program assigns points for each rule met and categorizes the password as Weak, Moderate, or Strong.
Feedback will be given on the password to help develop stronger passwords.

---

## Features
- Scores based on:
  -Length
  -Lowercase letters
  -Uppercase letters
  -Digits
  -Symbols
  -Consecutive repeated characters

- Explains why points were awarded or deducted.
- Prints both a numerical score along with a strength category.

---

## Categories
- Unacceptable: score = 0
- Weak:         <= 45  
- Moderate:     46-70  
- Strong:       71+  

---

## Example Run
Enter a password: Le3t_C0de!!!

Passwords are categorized based on their value.
Weak, Moderate, or Strong.
How did your password rank?

+20: Good length (12-14 characters).
+15: Contains lowercase.
+15: Contains uppercase.
+15: Contains a number.
+15: Contains a symbol.
-10: Contains a set of 3+ consecutive repeated characters.

Final Score: 70/100
Password Strength: Moderate
Decent but could be stronger

## How to Compile & Run
Using g++:
`bash`
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o pwcheck
./pwcheck