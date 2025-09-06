# Sparse Matrix using Compressed Sparse Row (CSR)

This project implements a **sparse matrix** using the **Compressed Sparse Row (CSR)** format in C++.  
The program converts a dense 2D matrix into three arrays (`valArray`, `colPos`, and `rowStart`) to store only the non-zero values, which saves memory and improves efficiency.

---

## Features
- Converts a dense matrix to CSR format.
- Displays the CSR representation:
  - `valArray` → stores non-zero values
  - `colPos` → stores column indices of non-zero values
  - `rowStart` → row starting positions
- Performs **matrix-vector multiplication**.
- Includes a helper function `countNonZero()` to report the number of non-zero elements.
- A commented debug print is left in the code to show row boundaries during testing.

---

## Files
- `main.cpp` — Contains the full CSR implementation and test example.

---

## How to Compile & Run
1. Open a terminal in the project folder.
2. Compile the program:
   ```bash
   g++ -std=c++11 main.cpp -o sparse
