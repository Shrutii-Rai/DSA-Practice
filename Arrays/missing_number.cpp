Leetcode - find missing number in an arrayy
Difficulty - easy
https://leetcode.com/problems/missing-number/description/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int xor1 = 0;
        int xor2 = 0;

        for (int i = 0; i < n; i++) {
            xor1 ^= i;
            xor2 ^= nums[i];
        }
        xor1 ^= n;

        return xor1 ^ xor2;
    }
};