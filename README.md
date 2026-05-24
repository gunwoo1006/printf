*This project has been created as part of the 42 curriculum by gkim*

## Description

ft_printf is a project that reimplements the C standard library function `printf`.

It uses variadic arguments to handle different format specifiers and returns the total number of characters printed.

Supported format specifiers:

- `%c` : Prints a single character.
  - Takes an `int` argument and prints it as a character.
  - Always returns `1` when printed successfully.

- `%s` : Prints a string.
  - Takes a `char *` argument.
  - Prints characters until the null terminator `\0`.
  - If the argument is `NULL`, it should print `(null)`.

- `%p` : Prints a pointer address.
  - Takes a `void *` argument.
  - Prints the address in hexadecimal format with the `0x` prefix.
  - If the pointer is `NULL`, it should print `(nil)`.

- `%d` : Prints a signed decimal integer.
  - Takes an `int` argument.
  - Handles negative numbers.
  - Must correctly handle `INT_MIN`.

- `%i` : Prints a signed integer.
  - Works the same way as `%d`.
  - Takes an `int` argument.
  - Handles negative numbers and `INT_MIN`.

- `%u` : Prints an unsigned decimal integer.
  - Takes an `unsigned int` argument.
  - Prints only non-negative values.
  - If a negative value is passed, it is interpreted as an unsigned integer.

- `%x` : Prints an unsigned integer in lowercase hexadecimal.
  - Takes an `unsigned int` argument.
  - Uses `0123456789abcdef` as the base.
  - Example: `255` is printed as `ff`.

- `%X` : Prints an unsigned integer in uppercase hexadecimal.
  - Takes an `unsigned int` argument.
  - Uses `0123456789ABCDEF` as the base.
  - Example: `255` is printed as `FF`.

- `%%` : Prints a percent sign.
  - Does not take any argument.
  - Prints `%`.

## Instructions

- ft_printf.c

- CC : cc

- flag : -Wall -Wextra -Werror

- make : make fclean clean re

## Resources

- stdarg.h 

https://ko.wikipedia.org/wiki/Stdarg.h

- printf 

https://en.wikipedia.org/wiki/Printf_format_string
https://www.freebsd.org/cgi/man.cgi?query=printf&apropos=0&sektion=3&manpath=FreeBSD+12.1-RELEASE+and+Ports&arch=default&format=html
https://modoocode.com/35#page-heading-4

- format specifier
https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=ruvendix&logNo=220891573114

## AI usage

- Understanding variadic arguments
- Understanding hexadecimal conversion
- Reviewing implementation ideas
- Debugging segmentation faults