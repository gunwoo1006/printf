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

### Algorithm and Data Structure

This project uses a simple parsing approach.

The format string is read character by character.  
When a normal character is found, it is printed directly using `write`.  
When a `%` character is found, the next character is checked to determine the conversion specifier.

Each specifier is handled by a separate helper function.  
Numbers are printed recursively by dividing the value by the base until the most significant digit is reached.

No complex data structure is used in this project.  
The implementation mainly relies on strings, integer values, pointers, and `va_list` for handling variadic arguments.

### Variadic Arguments

ft_printf uses variadic functions to accept a variable number of arguments.

The implementation relies on the macros provided by `stdarg.h`:

- `va_list` stores the list of arguments.
- `va_start` initializes the argument list.
- `va_arg` retrieves the next argument of a specified type.
- `va_end` cleans up the argument list.

When a format specifier is encountered in the format string, `va_arg` is used to extract the corresponding argument and pass it to the appropriate printing function.

This mechanism allows ft_printf to handle different argument types while using a single function prototype:

```c
int ft_printf(const char *format, ...);
```

## Instructions

- ft_printf.c

- CC : cc

- flag : -Wall -Wextra -Werror

### Make
- Build: `make`
- Clean object files: `make clean`
- Remove all generated files: `make fclean`
- Rebuild: `make re`

### Allowed Functions
- malloc
- free
- write
- va_start
- va_arg
- va_end
- va_copy

### Allowed Libraries
- libft

### Authorized Headers
- unistd.h
- stdarg.h
- stdlib.h
- stdint.h

### Requirements
- Do not implement the buffer management of the original printf().
- Your function has to handle the following conversions: cspdiuxX%
- Your function will be compared against the original printf().
- You must use the command ar to create your library.
- Using the libtool command is forbidden.
- Your libftprintf.a has to be created at the root of your repository.
- Your header file must be named ft_printf.h and must contain the prototype of
your ft_printf() function.

## Resources

- stdarg.h 
https://ko.wikipedia.org/wiki/Stdarg.h

- printf 
https://en.wikipedia.org/wiki/Printf_format_string
https://www.freebsd.org/cgi/man.cgi?query=printf&apropos=0&sektion=3&manpath=FreeBSD+12.1-RELEASE+and+Ports&arch=default&format=html
https://modoocode.com/35#page-heading-4

- variable arguments
https://velog.io/@octo__/C-%EC%96%B8%EC%96%B4-%EA%B0%80%EB%B3%80%EC%9D%B8%EC%9E%90


- format specifier
https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=ruvendix&logNo=220891573114

- hexadecimal 
https://www.ibm.com/docs/en/ste/11.0.0?topic=maps-hex-decimal-symbol-values

### AI usage

- Translating printf-related technical documentation into English
- Improving the readability and naturalness of project documentation
- Translating hexadecimal and number system references
- Proofreading project files and correcting spelling or grammar errors