# printf Project

This project is a custom implementation of the `printf` function in C. The goal is to reproduce the functionality of the standard `printf` function, handling a variety of format specifiers and adding custom specifiers. This project was completed by Daisy Mwambi and Kwame Amikhobu.

## Description

The `printf` function is an essential part of the C programming language, used to print formatted output to the standard output stream. This custom implementation, `_printf`, mimics the behavior of the standard `printf` and includes additional features and specifiers.

### Features Implemented

1. **Basic Format Specifiers**
   - `%c`: Print a single character
   - `%s`: Print a string
   - `%%`: Print a percent sign

2. **Integer Handling**
   - `%d` and `%i`: Print integers in decimal format

3. **Custom Format Specifier**
   - `%b`: Print an unsigned integer in binary format

4. **Additional Format Specifiers**
   - `%u`: Print unsigned integers
   - `%o`: Print unsigned integers in octal format
   - `%x` and `%X`: Print unsigned integers in hexadecimal format (lowercase and uppercase)

5. **Pointer Format Specifier**
   - `%p`: Print a pointer address

6. **Custom Conversion Specifier**
   - `%S`: Print a string, with non-printable characters formatted as `\x` followed by the ASCII code in hexadecimal

7. **Special Handling**
   - `%r`: Print a string in reverse
   - `%R`: Print a string in ROT13 encoding

8. **Flag Characters**
   - `+`, `space`, `#`: Handle plus sign, space, and hash flag characters

9. **Length Modifiers**
   - `l`, `h`: Handle length modifiers for `d`, `i`, `u`, `o`, `x`, `X`

10. **Field Width and Precision**
   - Handle field width and precision for non-custom conversion specifiers

11. **Zero Flag Character**
   - Handle the `0` flag character for non-custom conversion specifiers

12. **Minus Flag Character**
   - Handle the `-` flag character for non-custom conversion specifiers

13. **Local Buffer**
   - Use a local buffer of 1024 characters to minimize calls to `write`

## Compilation

To compile the project, use the following command:
```sh
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c
Ensure that no main functions are pushed to the root directory of your project. Test files with main functions should be placed in a separate test folder.

Usage
Include the main header file in your test files:e
#include "main.h"
Example usage of _printf:


int main(void)
{
    _printf("Character: [%c]\n", 'H');
    _printf("String: [%s]\n", "Hello, World!");
    _printf("Integer: [%d]\n", 42);
    _printf("Binary: [%b]\n", 98);
    _printf("Percent: [%%]\n");
    return 0;
}

Authors
Daisy Mwambi
Kwame Amikhobu
