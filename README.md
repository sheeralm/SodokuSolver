# SodokuSolver
Will automatically solve any unsolved and possible 9x9 sodoku puzzle

Uncomment any one of the puzzles at the top of solver.cpp, and it will automatically solve. The program will return a 9x9 board with all 0s replaced by the correct solution:

### BEFORE:
```
{5, 3, 0, 0, 7, 0, 0, 0, 0},
{6, 0, 0, 1, 9, 5, 0, 0, 0},
{0, 9, 8, 0, 0, 0, 0, 6, 0},
{8, 0, 0, 0, 6, 0, 0, 0, 3},
{4, 0, 0, 8, 0, 3, 0, 0, 1}, 
{7, 0, 0, 0, 2, 0, 0, 0, 6},
{0, 6, 0, 0, 0, 0, 2, 8, 0},
{0, 0, 0, 4, 1, 9, 0, 0, 5},
{0, 0, 0, 0, 8, 0, 0, 7, 9}
```

### AFTER:
```
- - - - - - - - - - - - - - - -
| 5  6  1 | 8  4  7 | 9  2  3 |
| 3  7  9 | 5  2  1 | 6  8  4 |
| 4  2  8 | 9  6  3 | 1  7  5 |
- - - - - - - - - - - - - - - -
| 6  1  3 | 7  8  9 | 5  4  2 |
| 7  9  4 | 6  5  2 | 3  1  8 |
| 8  5  2 | 1  3  4 | 7  9  6 |
- - - - - - - - - - - - - - - -
| 9  3  5 | 4  7  8 | 2  6  1 |
| 1  4  6 | 2  9  5 | 8  3  7 |
| 2  8  7 | 3  1  6 | 4  5  9 |
- - - - - - - - - - - - - - - -
```
