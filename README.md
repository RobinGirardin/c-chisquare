# Chi-Square Test in C

This project is a beginner-friendly implementation of the **Chi-Square test**
written in C.
The goal is to practice reading data from a file, storing it in a matrix,
computing expected values, and calculating the Chi-Square test statistic.

It was not designed as a full statistical package, but rather as a learning exercise to understand:

- File I/O in C
- Matrix operations
- Basic statistical computation

---

## ⚙️ What the Program Does

1. **Reads input data** from a text file (`test_data.txt`), which contains only numbers (no headers, labels, or formatting).
2. **Stores the data** in a 2D array (`data`).
3. **Prints the data** back to the console to verify correct input handling.
4. **Computes expected values** for each cell using row and column totals.
5. **Calculates the Chi-Square test statistic** by summing the contributions of each cell.
6. **Prints the final Chi-Square statistic**.

---

## Current 'Features'

- Reads numerical data from a text file into a matrix.
- Calculates expected frequencies based on totals.
- Computes and outputs the Chi-Square test statistic.

---

## Limitations

This implementation is intentionally simplified and has several limitations:

- **Hardcoded dimensions**:
  - `data` is declared as `int data[4][5]`, which restricts the program to exactly 4 rows and 5 columns.
  - `expect` and `stat` arrays are also hardcoded for 3x3 or 3x4 use.
  This makes the program unusable for different table sizes without code changes.

- **Logic assumptions**:
  - The program assumes the last row and last column contain **marginal totals** (row and column sums).
  - `total` is taken as `data[3][4]` (bottom-right cell), meaning the input must already include the grand total. No error checking ensures this is true.

- **No error handling**:
  - If the file cannot be opened, the program silently does nothing beyond the initial `if (fp != NULL)`. There is no error message or exit behavior.  
  - No checks for invalid data or division by zero.

- **No statistical decision**:
  - The program does not compute degrees of freedom, critical values, or p-values, meaning the test cannot actually be interpreted.
