# Divide_conquer
- Main problem is sort, the sub problems are also sort and not other tasks.
- It is basically a recursion
- There should be a way to fuse solutions of sub-problems

# example:
- Binary search
- Finding max and min
- Merge sort
- Strassens matrix multiplication
```
DAC(P)
{
 split into subproblems p1, p2, p3,..,pn
 for each p in subproblems:
 if(solvable(p))
   solve(p)
 else
   DAC(p)


}
```
- Time complexity of recursion  - atomic task at each recursion * number of
    recursions
- If the atomic task is of constant time-complexity, then the time complexity of
    recursion is O(n)
- If the atomic task is of time complexity O(m), then the time complexity of
    recursion is O(mn)
- If the atomic task if of time complexity O(logn), then the time complexity of
    recurusion is O(log(n!)) which is a subset of O(nlogn).
- For a recursion, which is done multiple times, for the recurrence relation
 T(n) = 2*T(n-1) + 1, The constant time is multipled with powers of 2.
 1 + 2 + 4 + 8 + .... + 2^n = 2^(n+1) - 1, so the time complexity is O(2^n)
- T(n) = 2*T(n-1) + n -> O(n*2^n)

- Master's therem for decreasing functions
 T(n) = aT(n-b) + f(n)
 f(n) = O(n^k)
