# Project Title: 2048 (single line) - Amateur

## Description
This project aims to replicate the mechanics of the 2048 game on a single horizontal line. Given an array of integers, the objective is to slide and merge it either to the left or to the right. Identical numbers, whether contiguous or separated by zeros, should merge.


## Requirements
### General
- Allowed editors: vi, vim, emacs
- All files will be compiled on Ubuntu 14.04 LTS
- Programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
- All files should end with a new line
- Code should follow the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- Global variables are not allowed
- No more than 5 functions per file
- Prototypes of all functions should be included in the header file "slide_line.h"
- Don’t forget to push your header file
- All header files should be include guarded

## Tasks
### Slide line (mandatory)
The goal of this task is to reproduce the 2048 game mechanics on a single horizontal line.

Write a function that slides and merges an array of integers.

**Prototype:** `int slide_line(int *line, size_t size, int direction);`

- `line`: Points to an array of integers containing size elements, to be slid & merged to the direction represented by direction.
- `size`: Number of elements in the array.
- `direction`: Represents the direction of sliding and merging, which can be either SLIDE_LEFT or SLIDE_RIGHT.
  - `SLIDE_LEFT`
  - `SLIDE_RIGHT`

Your function must return 1 upon success, or 0 upon failure. You are not allowed to allocate memory dynamically (malloc, calloc, …).

### Examples
```
$ ./0-slide_line L 2 2 0 0
Line: 2, 2, 0, 0
Slide to the left
Line: 4, 0, 0, 0

$ ./0-slide_line L 2 2 0 0 0 0 0 2 0 0 0 2 0 4
Line: 2, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 4
Slide to the left
Line: 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0

$ ./0-slide_line R 2 2 2 2
Line: 2, 2, 2, 2
Slide to the right
Line: 0, 0, 4, 4

$ ./0-slide_line R 2 2 2 2 2
Line: 2, 2, 2, 2, 2
Slide to the right
Line: 0, 0, 2, 4, 4

$ ./0-slide_line L 2 4 8 16
Line: 2, 4, 8, 16
Slide to the left
Line: 2, 4, 8, 16

$ ./0-slide_line R 2 4 8 16
Line: 2, 4, 8, 16
Slide to the right
Line: 2, 4, 8, 16

$ ./0-slide_line R 4 4 8 16
Line: 4, 4, 8, 16
Slide to the right
Line: 0, 8, 8, 16
```

## How to Use
Compile using the command:
gcc -Wall -Wextra -Werror -pedantic -o 0-slide_line 0-main.c 0-slide_line.c

