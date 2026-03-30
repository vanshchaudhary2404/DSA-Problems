## 📊 Excel Sheet
👉 [![Excel Sheet](https://img.icons8.com/color/48/000000/ms-excel.png)](https://1drv.ms/x/c/d503fb3325128f00/EaT_c-NRD7dIhK3P6FEydPcBvAX-1hQKO4X5g1BYhTyVUg?e=h8Txb5)
[![Excel Link](https://img.shields.io/badge/Open%20Excel%20Sheet-217346?style=for-the-badge&logo=microsoft-excel&logoColor=white)](https://1drv.ms/x/c/d503fb3325128f00/EaT_c-NRD7dIhK3P6FEydPcBvAX-1hQKO4X5g1BYhTyVUg?e=nnOqiR)

# 🔁 Recursion & Backtracking Problems
---

## 📌 Problem List

| # | Problem | Level | Link |
|--|--------|-------|------|
| 1 | Print 1 to N / N to 1 | Easy | https://www.geeksforgeeks.org/print-1-to-n-without-loop/ |
| 2 | Sum of first N numbers | Easy | https://www.geeksforgeeks.org/sum-of-first-n-natural-numbers/ |
| 3 | Factorial of N | Easy | https://leetcode.com/problems/factorial-trailing-zeroes/ |
| 4 | Factorial Trailing Zeroes | Easy | https://leetcode.com/problems/factorial-trailing-zeroes/ |
| 5 | Reverse an array (Two Pointer) | Easy | https://leetcode.com/problems/reverse-string/ |
| 6 | Reverse an array (Single Pointer) | Easy | https://www.geeksforgeeks.org/reverse-an-array/ |
| 7 | Check Palindrome (String) | Easy | https://leetcode.com/problems/valid-palindrome/ |
| 8 | Fibonacci Number | Easy | https://leetcode.com/problems/fibonacci-number/ |
| 9 | Reverse String | Easy | https://leetcode.com/problems/reverse-string/ |
| 10 | Binary Search (Recursive) | Easy | https://leetcode.com/problems/binary-search/ |
| 11 | Merge Sort | Medium | https://leetcode.com/problems/sort-an-array/ |
| 12 | Quick Sort | Medium | https://www.geeksforgeeks.org/quick-sort/ |
| 13 | Subsets | Medium | https://leetcode.com/problems/subsets/ |
| 14 | Subsets II | Medium | https://leetcode.com/problems/subsets-ii/ |
| 15 | Subset Sums | Medium | https://www.geeksforgeeks.org/subset-sum-problem/ |
| 16 | Permutations | Medium | https://leetcode.com/problems/permutations/ |
| 17 | Permutations II | Medium | https://leetcode.com/problems/permutations-ii/ |
| 18 | N-Queens | Hard | https://leetcode.com/problems/n-queens/ |
| 19 | N-Queens II | Hard | https://leetcode.com/problems/n-queens-ii/ |
| 20 | Sudoku Solver | Hard | https://leetcode.com/problems/sudoku-solver/ |
| 21 | Combination Sum | Medium | https://leetcode.com/problems/combination-sum/ |
| 22 | Combination Sum II | Medium | https://leetcode.com/problems/combination-sum-ii/ |
| 23 | Rat in a Maze | Medium | https://www.geeksforgeeks.org/rat-in-a-maze/ |
| 24 | Palindrome Partitioning | Medium | https://leetcode.com/problems/palindrome-partitioning/ |
| 25 | Count Inversions | Hard | https://leetcode.com/problems/count-of-smaller-numbers-after-self/ |
| 26 | Knight Tour | Hard | https://www.geeksforgeeks.org/the-knights-tour-problem/ |
| 27 | M-Coloring Problem | Hard | https://www.geeksforgeeks.org/m-coloring-problem/ |
| 28 | Kth Permutation Sequence | Hard | https://leetcode.com/problems/permutation-sequence/ |

---

# 🧠 Recursion Patterns (VERY IMPORTANT)

### 1. 🔹 Basic Recursion (Linear)
- Print 1 to N
- Factorial
- Fibonacci

👉 Pattern:
```cpp
void solve(int n){
    if(n == 0) return;
    solve(n-1);
}
