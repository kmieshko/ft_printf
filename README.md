# ft_printf

ft_printf is a project aims at rebuilding the printf library with basic functionality.

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
