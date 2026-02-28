# Libft

A custom **C utility library** built as a single static archive:
**`libft.a`**, developed as part of the 42 curriculum.

This project consists of reimplementing a core subset of the C standard
library (`libc`) from scratch.\
All functions strictly follow the original prototypes and behaviors as
documented in their respective man pages, with the only modification
being the `ft_` prefix (e.g. `strlen` → `ft_strlen`).

The implementation avoids forbidden keywords such as `restrict`, does
not rely on C99-specific features, and is written entirely without using
the original libc implementations.

This library integrates:

-   Core libft utilities (strings, memory, characters, conversions, fd
    output)
-   Linked list utilities (bonus)
-   `get_next_line`
-   `ft_printf`
-   Additional helpers (e.g. `ft_swap`)
-   A dedicated unit testing framework under `tests/`

The project is designed as a reusable, self-contained base library for
further C projects, with emphasis on correctness, standards compliance,
and automated validation.

Author: Pedro Lima (github.com/TheForestGiraffe)

------------------------------------------------------------------------

## Table of Contents

-   [Design goals](#design-goals)
-   [Project layout](#project-layout)
-   [Build](#build)
-   [Using libft in another project](#using-libft-in-another-project)
-   [API overview](#api-overview)
-   [Testing framework](#testing-framework)
    -   [Configuring get_next_line buffer size](#configuring-get_next_line-buffer-size)
    -   [42 Norm compliance](#42-norm-compliance)
    -   [Test artifacts cleanup](#test-artifacts-cleanup)
-   [List of Functions](#list-of-functions)

------------------------------------------------------------------------

## Design goals

-   Single unified static library
-   Modular internal structure
-   Strict compilation (`-Wall -Wextra -Werror`)
-   Function-level testing
-   Automated rebuild + test execution
-   42 norm compliance

------------------------------------------------------------------------

## Project layout

``` text
.
├── include/
│   └── libft.h
│
├── srcs/
│   ├── get_next_line/
│   │   ├── get_next_line.c
│   │   ├── get_next_line_utils.c
│   │   └── get_next_line.h
│   │
│   ├── ft_printf/
│   │   ├── ft_printf.c
│   │   ├── print_*.c
│   │   └── ft_printf.h
│   │
│   └── ft_*.c
│
├── tests/
│   ├── srcs/
│   │   └── test_*.c
│   └── Makefile
│
├── objs/      # generated
├── libft.a    # generated
└── Makefile
```

------------------------------------------------------------------------

## Build

Build the library:

``` bash
make
```

This generates:

-   `libft.a` --- static archive
-   `objs/` --- object files

Clean objects, full clean, and rebuild:

``` bash
make clean
make fclean
make re
```

------------------------------------------------------------------------

## Using libft in another project

``` bash
cc -I/path/to/libft/include main.c /path/to/libft/libft.a -o app
```

Include the main header:

``` c
#include "libft.h"
```

------------------------------------------------------------------------

## API overview

This library provides:

-   Core utilities (`ft_is*`, `ft_to*`)
-   Memory utilities (`ft_mem*`, `ft_bzero`, `ft_calloc`)
-   String utilities (`ft_str*`, `ft_split`, `ft_trim`, etc.)
-   Numeric conversion (`ft_atoi`, `ft_itoa`)
-   File descriptor output (`ft_put*_fd`)
-   Linked lists (bonus)
-   `get_next_line`
-   `ft_printf`
-   Extra helpers (`ft_swap`)

------------------------------------------------------------------------

## Testing framework

From the `tests/` directory:

``` bash
make
```

This will:

-   Build `libft.a` automatically
-   Compile all test sources
-   Link them into `test_libft`
-   Run the test suite

Run manually:

``` bash
make test
./test_libft
```

------------------------------------------------------------------------

### Configuring get_next_line buffer size

Edit in `tests/Makefile`:

``` makefile
GNL_BUFFER_SIZE = 100
```

Passed as:

``` makefile
-D BUFFER_SIZE=<value>
```

------------------------------------------------------------------------

### 42 Norm compliance

``` bash
make norm
```

Uses:

``` bash
norminette -R CheckForbiddenHeaderSource
```

------------------------------------------------------------------------

### Test artifacts cleanup

``` bash
make clean
```

Removes temporary test files.

------------------------------------------------------------------------

## List of Functions

-   ft_atoi
-   ft_bzero
-   ft_calloc
-   ft_isalnum
-   ft_isalpha
-   ft_isascii
-   ft_isdigit
-   ft_isprint
-   ft_itoa
-   ft_memchr
-   ft_memcmp
-   ft_memcpy
-   ft_memmove
-   ft_memset
-   ft_printf
-   ft_putchar_fd
-   ft_putendl_fd
-   ft_putnbr_fd
-   ft_putstr_fd
-   ft_split
-   ft_strchr
-   ft_strdup
-   ft_striteri
-   ft_strjoin
-   ft_strlcat
-   ft_strlcpy
-   ft_strlen
-   ft_strmapi
-   ft_strncmp
-   ft_strnstr
-   ft_strtol
-   ft_strrchr
-   ft_strtrim
-   ft_substr
-   ft_tolower
-   ft_toupper
-   ft_lstadd_back
-   ft_lstadd_front
-   ft_lstclear
-   ft_lstdelone
-   ft_lstiter
-   ft_lstlast
-   ft_lstmap
-   ft_lstnew
-   ft_lstsize
-   get_next_line
