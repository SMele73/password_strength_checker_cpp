# Password Strength Checker – Test Cases

This document lists example passwords with their expected score and category.  
Use these to verify program correctness.


## Test Cases

| Password             | Length | Variety									 | Expected Score | Expected Category |
|----------------------|--------|--------------------------------------------|----------------|-------------------|
| `abc`                | 3      | Lower only								 | 0 (too short)  | Unacceptable      |
| `abcde`              | 5      | Lower only								 | 15             | Weak              |
| `Abc123`             | 6      | Lower + Upper + Digit						 | 45             | Weak              |
| `Abc123!`            | 7      | Lower + Upper + Digit + Symbol			 | 60			  | Moderate		  |
| `Abcdefgh`           | 8      | Lower + Upper								 | 40             | Weak              |
| `Abcdefgh!`          | 9      | Lower + Upper	+ Digit						 | 55             | Moderate          |
| `Pr3ttyg0od!`        | 11     | Lower + Upper	+ Digit + Symbol			 | 70             | Moderate          |
| `Le3t_C0des!!`       | 12     | Lower + Upper + Digit + Symbol			 | 80             | Strong            |
| `Le3t_C0de!!!`	   | 12		| Lower + Upper + Digit + Symbol - repeats	 | 70			  | Moderate		  |
| `ReallyLongPass123!` | 17     | Lower + Upper + Digit + Symbol			 | 100            | Strong            |
| `!1Lc`               | 4      | Lower + Upper + Digit + Symbol			 | 0 (too short)  | Unacceptable      |
| `1234567890`         | 10     | Digits only								 | 25             | Weak              |
| `11111`              | 5      | Digits - consecutive repeats				 | 0 (15 – 15)    | Unacceptable      |
| `P@ssword!!!`        | 11     | Lower + Upper + Digit - repeats			 | 45 (70 – 15)   | Weak			  |

## Notes
- Passwords shorter than 5 characters automatically fail (`score = 0`).
- Variety bonuses stack: lowercase, uppercase, digit, symbol (15 points each).
- Length bonus is mutually exclusive (only the highest length bracket applies).
