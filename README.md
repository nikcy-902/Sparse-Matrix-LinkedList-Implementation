# Sparse-Matrix-LinkedList-Implementation
# Sparse Matrix (Linked List) — C++

## 📌 Description
This project implements a **Sparse Matrix** using a **Linked List** in C++.  
Only non-zero elements are stored as nodes in a singly linked list, each node containing:
(row, column, value)
This saves memory compared to storing every element in a dense 2D array.

## ✅ Features
- Stores only non-zero elements
- Triplet representation: `(row, col, value)`
- Prints both the triplet form and the reconstructed dense matrix
- Clean, beginner-friendly implementation

## 🧠 How it works
1. Read a dense matrix from input.
2. Convert to a linked list by appending a node for each non-zero.
3. Print:
   - Header: `rows cols nonzeros`
   - Each non-zero as `r c v`
4. Reconstruct and print the dense matrix for verification.

## ▶️ Build & Run
```bash
g++ main.cpp -o sparse
./sparse
📝 Example

Input

3 3
0 0 3
4 0 0
0 5 0


Output (triplets)

rows cols nonzeros: 3 3 3
r c v
0 2 3
1 0 4
2 1 5


Reconstructed dense

0 0 3
4 0 0
0 5 0

📂 Files

main.cpp — C++ source

README.md — this file

.gitignore — optional, ignores build outputs
