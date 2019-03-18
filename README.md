# ft_printf

*ft_printf* is a project aims at rebuilding the printf library with basic functionality.

**Basics**, requested from subject:

1. Parsing for *flags*, *field_width*, *precision*, *length_modifier*.
2. Parsing for conversion specifier.
3. Displaying UTF-8 characters. (`%C` and `%S`).
4. Computing unsigned numbers in base 2 (`%b`), 8 (`%o`), 10 (`%u`) and 16 (`%x`).
5. Displaying signed numbers (`%d`, `%D`, `%i`).
6. Displaying pointer address (`%p`).

**Bonuses**:

1. Wildcard_length_modifier (`%*`): replaces precision and field_width with parameter in *va_list ap*.

# Usage

Edit the Makefile to point to libft. Run make to compile the library. Use it like you would use the printf function

# Disclaimer

This project is written according to 42's "The Norm" which specifies special rules for code like less then 25 lines in each function, 85 symbols in line, forbidden most of libraries and functions that wasn't written by you, also "for", "switch case" and others are forbidden (you can read more at https://ncoden.fr/datas/42/norm.pdf)
