Difficulty - Easy
https://leetcode.com/problems/fibonacci-number/description/

class Solution {
public:
    int fib(int n) {
        if (n <= 1) {
            return n;
        }
        int Last = fib(n - 1);
        int sLast = fib(n - 2);
        return Last + sLast;
    }
};