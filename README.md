# DSA Assignment: Hash Table vs. Linear Search Implementation

## 1. Source Code
The C source code implementation is stored in [`main.c`](./main.c).

## 2. Input Data
- **Song IDs:** `105, 210, 315, 420, 525, 630, 735, 840`
- **Total Elements ($n$):** 8
- **Hash Table Size ($m$):** 11 (Prime number chosen to minimize collisions)
- **Hash Function:** Division Method $h(k) = k \pmod{11}$
- **Collision Resolution:** Linear Probing $h'(k, i) = (h(k) + i) \pmod{11}$

---

## 3. Insertion Trace Table

| Song ID ($k$) | Hash Calculation ($k \pmod{11}$) | Initial Index | Collision? | Probes | Final Index |
|---|---|---|---|---|---|
| 105 | $105 \pmod{11}$ | 6 | No | 0 | 6 |
| 210 | $210 \pmod{11}$ | 1 | No | 0 | 1 |
| 315 | $315 \pmod{11}$ | 7 | No | 0 | 7 |
| 420 | $420 \pmod{11}$ | 2 | No | 0 | 2 |
| 525 | $525 \pmod{11}$ | 8 | No | 0 | 8 |
| 630 | $630 \pmod{11}$ | 3 | No | 0 | 3 |
| 735 | $735 \pmod{11}$ | 9 | No | 0 | 9 |
| 840 | $840 \pmod{11}$ | 4 | No | 0 | 4 |

---

## 4. Search Operations Trace & Performance Comparison

| Target Song ID | Linear Search Result | Linear Search Comparisons | Hash Search Result | Hash Search Comparisons |
|---|---|---|---|---|
| **315** | Found (Index 2) | 3 | Found (Index 7) | 1 |
| **840** | Found (Index 7) | 8 | Found (Index 4) | 1 |
| **999** (Absent) | Not Found | 8 | Not Found | 1 |

---

## 5. Complexity Analysis

| Metric / Parameter | Linear Search | Hashing (Division Method) |
|---|---|---|
| **Best Case Time Complexity** | $O(1)$ | $O(1)$ |
| **Average Case Time Complexity** | $O(n)$ | $O(1)$ |
| **Worst Case Time Complexity** | $O(n)$ | $O(n)$ |
| **Space Complexity** | $O(n)$ | $O(m + n)$ |

### Load Factor Analysis
- **Load Factor ($\lambda$):** $\lambda = \frac{n}{m} = \frac{8}{11} \approx 0.727$ (72.7%)
- At a load factor of 0.727 with a prime table size ($m=11$), the division method distributes keys uniformly, avoiding initial collisions and keeping average search time at $O(1)$.

---

## 6. Final Conclusion & Recommendation
For real-time song retrieval in a music streaming application, **Hashing using the Division Method is far superior to Linear Search**. 

While Linear Search requires scanning through elements sequentially—taking up to $n$ comparisons for elements near the end of the array or missing entries—Hash Search locates elements in direct $O(1)$ average time regardless of dataset size. Therefore, Hashing is the optimal data structure for fast search operations in this application.
