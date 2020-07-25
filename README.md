# ft_printf
>Copy of real **printf** function in **C** (it doesn't do the buffer management like the real printf)

### Function prototype:
**`ft_printf(const char *, ...);`**
  
  
#### This ft_printf library can handle:
- flags : **`-, 0, +, ' '(space), #`**
- types : **`c s d i u n p x X f %`**
-  modifiers : **`l ll h hh`**
- width and precision (can be used instead `*` and `.*` also)

### Function call example:
##### `ft_printf("%d", 42);`

### Instruction:
- `make all` will create **libftprintf.a** library
- compile with **libftprintf.a** (also you need to include a header file):  
  >- gcc -I/includes libftprintf.a program_name.c

### Return values:
- -1 if error happened
- n length of **ft_printf** output
