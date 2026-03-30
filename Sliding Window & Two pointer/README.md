# 🚀 Sliding Window & Two Pointer Patterns

This repository contains curated problems, patterns, and templates for mastering **Sliding Window** and **Two Pointer** techniques — essential for coding interviews.

---

## 📌 Problem  set :

| S.No | Problem Name                                         | Level  | Link                                                                                |
| ---- | ---------------------------------------------------- | ------ | ----------------------------------------------------------------------------------- |
| 1    | Maximum Points You Can Obtain from Cards             | Medium | https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/             |
| 2    | Number of Substrings Containing All Three Characters | Medium | https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/ |
| 3    | Count Number of Nice Subarrays                       | Medium | https://leetcode.com/problems/count-number-of-nice-subarrays/                       |
| 4    | Binary Subarrays With Sum                            | Medium | https://leetcode.com/problems/binary-subarrays-with-sum/                            |
| 5    | Longest Repeating Character Replacement              | Medium | https://leetcode.com/problems/longest-repeating-character-replacement/              |
| 6    | Max Consecutive Ones III                             | Medium | https://leetcode.com/problems/max-consecutive-ones-iii/                             |
| 7    | Longest Substring Without Repeating Characters       | Medium | https://leetcode.com/problems/longest-substring-without-repeating-characters/       |

---
## 📌 More Sliding Window & Two Pointer Problems (Practice Set)

| S.No | Problem Name                                       | Level  | Pattern                 | Link                                                                             |
| ---- | -------------------------------------------------- | ------ | ----------------------- | -------------------------------------------------------------------------------- |
| 1    | Minimum Size Subarray Sum                          | Medium | Variable Window         | https://leetcode.com/problems/minimum-size-subarray-sum/                         |
| 2    | Longest Subarray of 1's After Deleting One Element | Medium | Variable Window         | https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/ |
| 3    | Fruit Into Baskets                                 | Medium | At Most K               | https://leetcode.com/problems/fruit-into-baskets/                                |
| 4    | Subarrays with K Different Integers                | Hard   | Exactly K               | https://leetcode.com/problems/subarrays-with-k-different-integers/               |
| 5    | Minimum Window Substring                           | Hard   | Variable Window         | https://leetcode.com/problems/minimum-window-substring/                          |
| 6    | Permutation in String                              | Medium | Fixed + Frequency       | https://leetcode.com/problems/permutation-in-string/                             |
| 7    | Find All Anagrams in a String                      | Medium | Fixed Window            | https://leetcode.com/problems/find-all-anagrams-in-a-string/                     |
| 8    | Sliding Window Maximum                             | Hard   | Deque                   | https://leetcode.com/problems/sliding-window-maximum/                            |
| 9    | Container With Most Water                          | Medium | Two Pointer (Opposite)  | https://leetcode.com/problems/container-with-most-water/                         |
| 10   | 3Sum                                               | Medium | Two Pointer (Sorted)    | https://leetcode.com/problems/3sum/                                              |
| 11   | 4Sum                                               | Medium | Two Pointer + Sorting   | https://leetcode.com/problems/4sum/                                              |
| 12   | Remove Duplicates from Sorted Array                | Easy   | Two Pointer (Fast/Slow) | https://leetcode.com/problems/remove-duplicates-from-sorted-array/               |
| 13   | Move Zeroes                                        | Easy   | Two Pointer             | https://leetcode.com/problems/move-zeroes/                                       |
| 14   | Valid Palindrome                                   | Easy   | Two Pointer             | https://leetcode.com/problems/valid-palindrome/                                  |
| 15   | Trapping Rain Water                                | Hard   | Two Pointer             | https://leetcode.com/problems/trapping-rain-water/                               |

---

### 🧠 How to Use This Table

* Start from **Easy → Medium → Hard**
* Focus on **pattern recognition (VERY IMPORTANT)**
* Solve at least:

  * 5 Variable Window
  * 3 AtMost/Exactly
  * 5 Two Pointer

---

# 🧠 Core Concepts

## 🔹 Sliding Window

Used when:

* Subarray / substring problems
* Contiguous elements
* Optimize brute force O(n²) → O(n)

👉 Types:

* Fixed Window
* Variable Window

---

## 🔹 Two Pointer

Used when:

* Sorted arrays
* Pair problems
* Opposite direction traversal

---

# ⚡ Patterns You Must Know

## 🪟 Sliding Window Patterns

### 1. Fixed Size Window

```cpp
int windowSum = 0;
for(int i = 0; i < k; i++) windowSum += arr[i];

int maxSum = windowSum;

for(int i = k; i < n; i++){
    windowSum += arr[i] - arr[i-k];
    maxSum = max(maxSum, windowSum);
}
```

---

### 2. Variable Size Window (Most Important 🔥)

```cpp
int left = 0;
for(int right = 0; right < n; right++){
    
    while(condition_not_valid){
        left++;
    }
    
    // update answer
}
```

---

### 3. Count Subarrays Trick

```cpp
count += (right - left + 1);
```

---

### 4. At Most / Exactly K Pattern

```cpp
exactly(k) = atMost(k) - atMost(k-1);
```

---

## 🔁 Two Pointer Patterns

### 1. Opposite Direction

```cpp
int left = 0, right = n-1;
while(left < right){
    if(condition) left++;
    else right--;
}
```

---

### 2. Fast & Slow Pointer

```cpp
int slow = 0;
for(int fast = 0; fast < n; fast++){
    if(condition){
        swap(arr[slow], arr[fast]);
        slow++;
    }
}
```

---

### 3. Merge Pattern

```cpp
while(i < n && j < m){
    if(a[i] < b[j]) i++;
    else j++;
}
```

---

# 🧩 Template Code

## ⭐ Universal Sliding Window

```cpp
int left = 0;
int ans = 0;

for(int right = 0; right < n; right++){
    
    while(window_invalid){
        left++;
    }
    
    ans = max(ans, right - left + 1);
}
```

---

## ⭐ Count Subarrays Template

```cpp
int left = 0, count = 0;

for(int right = 0; right < n; right++){
    
    while(condition_invalid){
        left++;
    }
    
    count += (right - left + 1);
}
```

---

# 🎯 Interview Tips

### ✅ Recognition

* Subarray / substring → Sliding Window
* Sorted array / pairs → Two Pointer

---

### ✅ Always Start with Brute Force

* Think O(n²)
* Optimize to O(n)

---

### ✅ Key Questions to Ask

* When to expand window?
* When to shrink window?

---

### ❌ Common Mistakes

* Wrong shrinking condition
* Missing answer update
* Infinite loops

---

### 🔥 Pattern Mapping

| Pattern         | Problems                         |
| --------------- | -------------------------------- |
| Fixed Window    | Max Points from Cards            |
| Variable Window | Longest Substring Without Repeat |
| At Most K       | Max Consecutive Ones III         |
| Exactly K       | Binary Subarrays With Sum        |
| Frequency Map   | Longest Repeating Character      |

---

# 🚀 Pro Tips

* Master **AtMost(K)** pattern deeply
* Practice **frequency map sliding window**
* Combine **prefix sum + sliding window**
* Learn **deque-based window problems**

---

# 📈 Roadmap

1. Fixed Window
2. Variable Window
3. AtMost / Exactly K
4. Practice 15+ problems
5. Revise patterns

---

# ⭐ Final Advice

Sliding Window + Two Pointer =
🔥 High-frequency interview topic

Master this → You unlock **30% of DSA interview questions easily**

---
