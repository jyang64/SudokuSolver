# SudokuSolver
Uses recursive backtracking to solve sudoku puzzles.

The puzzle must be a .txt file. All unknown values must be represented as 0's. Numbers can be separated with any character, but there must be 81 numbers in the file (9x9 sudoku grid).

To run the program, download all the files, and type ./sudoku into the terminal at the location of the files followed by the name of the .txt file containing the puzzle.

Example:
in the file sudoku.txt:

  0,3,0,0,5,0,0,4,0
  0,0,8,0,1,0,5,0,0
  4,6,0,0,0,0,0,1,2
  0,7,0,5,0,2,0,8,0
  0,0,0,6,0,3,0,0,0
  0,4,0,1,0,9,0,3,0
  2,5,0,0,0,0,0,9,8
  0,0,1,0,2,0,6,0,0
  0,8,0,0,6,0,0,0,0

To solve the puzzle, use ./sudoku sudoku.txt.
