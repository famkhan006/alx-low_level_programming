# BIT MANIPULSTION
## converting between numbers
**Decimal to Binary:**
To convert a decimal number to binary:

1. Start with the decimal number.
2. Divide the number by 2 and note down the remainder.
3. Continue dividing the quotient by 2 until you reach 0, noting down the remainders at each step.
4. Reverse the sequence of remainders to get the binary equivalent.

Example: Converting decimal 10 to binary:
```
10 ÷ 2 = 5 remainder 0
 5 ÷ 2 = 2 remainder 1
 2 ÷ 2 = 1 remainder 0
 1 ÷ 2 = 0 remainder 1
```
Reversing the remainders, we get the binary equivalent: **1010**.

**Hexadecimal to Binary:**
To convert a hexadecimal number to binary:

1. Write down the hexadecimal number.
2. Replace each hexadecimal digit with its 4-bit binary representation.
3. Combine the binary representations of each digit to get the binary equivalent.

Example: Converting hexadecimal A3 to binary:
```
A -> **1010**
3 -> **0011**
```
Combining the binary representations, we get the binary equivalent: **10100011**.

**Binary to Decimal:**
To convert a binary number to decimal:

1. Write down the binary number.
2. Start from the rightmost bit and assign powers of 2 to each bit, starting from 2^0.
3. Multiply each bit by its corresponding power of 2.
4. Sum up the results to get the decimal equivalent.

Example: Converting binary 1010 to decimal:
```
(1 * 2^3) + (0 * 2^2) + (1 * 2^1) + (0 * 2^0) = 8 + 0 + 2 + 0 = **10**
```
The decimal equivalent of binary 1010 is **10**.

**Binary to Hexadecimal:**
To convert a binary number to hexadecimal:

1. Group the binary digits into sets of 4, starting from the rightmost bit. Add leading zeros if needed.
2. Replace each group of 4 bits with its corresponding hexadecimal digit.

Example: Converting binary 10100011 to hexadecimal:
```
10 -> **A**
1000 -> **8**
11 -> **3**
```
The hexadecimal equivalent of binary 10100011 is **A38**.

-If we know how to convert then lets jump to  The Shift Operators

Apologies for the confusion. Here's the revised note with all the content written in Markdown:

**Motivation for Shift Operators**

Shift operators offer powerful capabilities for manipulating binary data and performing efficient bitwise operations in programming. Here are some key applications and reasons to explore their use:

1. **Efficient Multiplication/Division**: Shift operators can be used to perform multiplication or division operations by powers of two in a highly efficient manner. This is especially valuable in scenarios where performance optimization is critical.

2. **Bit Manipulation**: Shift operators enable precise control over individual bits within a binary number. They allow for setting, clearing, toggling, or extracting specific bits, which is useful in tasks such as bitmasking, flag manipulation, and data compression.

3. **Binary Encoding/Decoding**: When working with binary formats or protocols, shift operators can assist in encoding or decoding data structures by shifting and combining individual bits to form larger values or extract meaningful information.

4. **Bitwise Operations**: Shift operators serve as fundamental building blocks for bitwise operations like bitwise OR, AND, XOR, and NOT. These operations are widely used in cryptography, graphics programming, network protocols, and low-level system programming.

By understanding and utilizing shift operators effectively, you can unlock the full potential of bitwise operations and binary manipulation in your programming endeavors.

---

**Shift Operators in Brief**

- **Left Shift Operator (<<)**: The left shift operator shifts the bits of a number to the left, filling the vacant positions on the right with zeros. It is used to multiply a number by 2 raised to the power of the shift amount.

- **Right Shift Operator (>>)**: The right shift operator shifts the bits of a number to the right, filling the vacant positions on the left with zeros. It is used to divide a number by 2 raised to the power of the shift amount.

- Shift operators enable efficient manipulation of binary data, bitwise operations, and extraction of specific bits within a number.

- **Examples**:
  - Left shift: `5 << 2` shifts the bits of 5 (101 in binary) two positions to the left, resulting in 20 (10100 in binary).
  - Right shift: `16 >> 2` shifts the bits of 16 (10000 in binary) two positions to the right, resulting in 4 (100 in binary).

- Shift operators offer valuable capabilities for optimizing algorithms, performing bitwise operations, and working with binary data efficiently.

### bitwise Operators
| Operator | Description                | Usage         | Example  |
|----------|----------------------------|---------------|----------|
| `&`      | Bitwise AND                | `a & b`       | `13 & 7` = `5`   |
| `\|`     | Bitwise OR                 | `a \| b`      | `10 \| 6` = `14` |
| `^`      | Bitwise XOR (Exclusive OR) | `a ^ b`       | `11 ^ 6` = `13`  |
| `~`      | Bitwise NOT                | `~a`          | `~13` = `-14`    |

- **Bitwise NOT (`~`)**: The bitwise NOT operator inverts the bits of a number, resulting in the one's complement of the number. It flips each bit from 0 to 1 and from 1 to 0.

   Example: `~13` = `-14`

The bitwise NOT operator is a unary operator that operates on a single operand and is particularly useful for scenarios where you need to flip or negate the bits of a number.

<img src="https://s3.amazonaws.com/intranet-projects-files/holbertonschool-low_level_programming/232/bitwise.PNG" alt="Bitwize Operators" width="300">
