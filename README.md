# ft_printf

Custom implementation of the `printf` function from the C standard library, developed as part of the 42 curriculum.

## About

`ft_printf` is a simplified version of the original `printf` function.  
The goal of this project is to understand variadic functions, formatted output, parsing and low-level character printing in C.

The function receives a format string and a variable number of arguments, then prints the formatted result to the standard output.

## Supported Conversions

This implementation handles the main basic conversions used in the project:

| Conversion | Description |
|-----------|-------------|
| `%c` | Prints a single character |
| `%s` | Prints a string |
| `%d` | Prints a signed decimal integer |
| `%i` | Prints a signed integer |
| `%u` | Prints an unsigned decimal integer |
| `%%` | Prints a percent sign |

## Project Structure

```txt
.
├── ft_printf.c
├── ft_printf.h
├── ft_arg_c.c
├── ft_arg_s.c
├── ft_arg_d_i.c
├── ft_arg_u.c
└── ft_arg_perc.c
Compilation

Compile the source files with:

cc -Wall -Wextra -Werror *.c -o ft_printf_test

You can also compile it together with your own test file:

cc -Wall -Wextra -Werror main.c *.c -o test
Usage

Include the header:

#include "ft_printf.h"

Example:

#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s!\n", "world");
    ft_printf("Number: %d\n", 42);
    ft_printf("Unsigned: %u\n", 42);
    ft_printf("Character: %c\n", 'A');
    ft_printf("Percent: %%\n");
    return (0);
}

Run:

./test
What I Learned

Through this project I practiced:

Variadic functions with va_list, va_start, va_arg and va_end
Parsing format strings
Printing different data types
Handling signed and unsigned integers
Splitting logic into smaller helper functions
Writing reusable C code
Technologies
C
Variadic functions
Unix standard output
Manual parsing
Notes

This project is part of the 42 curriculum.
It is a useful introduction to how formatted output works internally in C.

If you are also a 42 student, use this repository only as a reference. The best way to learn ft_printf is to implement and debug each conversion yourself.

Author

Luis Ángel Álvarez Gil
42 Málaga
