Leetcode - XOR range multiplication
Difficulty - Medium
https://leetcode.com/problems/xor-after-range-multiplication-queries-i/submissions/1972857927/?envType=daily-question&envId=2026-04-08

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        
        for (auto& q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            for (int idx = l; idx <= r; idx += k) {
                nums[idx] = (1LL * nums[idx] * v) % MOD;
            }
        }
        
        int result = 0;
        for (int x : nums) {
            result ^= x;
        }
        return result;
    }
};