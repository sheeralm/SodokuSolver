# SodokuSolver
Will automatically solve any unsolved and possible 9x9 sodoku puzzle.

This is accomplished by:

#### INITIAL:
1. Finding an empty tile. (if no tile is found, board is already solved)
2. starting from 1, iterate 1-9, testing each digit in the space. In order for a pass, the following conditions must be met:
- the number is not present in the row
- the number is not present in the column
- the number is not present in the corresponding 3x3 box

#### PASSED:
1. Replace current digit with the digit being tested. (for example, if testing 1, and it passes, 0 --> 1)
2. Recurse solveBoard(). This will recurse the INITIAL process.
3. If no empty tile is found, solveBoard() will return true all the way down until true is returned to main
4. The completed board will be printed.

#### FAILED:
1. Undo the current change and return false to the previous iteration
2. This will cause the previous iteration to also undo its change, and attempt the next possible digit
3. If another digit works, return true and reattempt the INITIAL process again.
3. If no other digits work, repeat the FAILED process another level down
4. If the board reaches the root level, and no other digits pass, the entire solveBoard() will fail, which means the board is impossible
5. "impossible" will be printed.

## HOW TO RUN:
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
