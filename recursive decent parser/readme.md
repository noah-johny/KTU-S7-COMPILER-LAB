# Recursive Descent Parser for Arithmetic Expressions

This C program implements a recursive descent parser for parsing arithmetic expressions based on the given grammar rules:

```
E -> E+T | T
T -> T*F | F
F -> (E) | id
```

After removing left recursion::

```
E -> TE'
E' -> +TE' | #
T -> FT'
T' -> *FT' | #
F -> (E)
F -> id
```
