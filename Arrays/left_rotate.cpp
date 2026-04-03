Leetcode - left rotate array by k places
Difficulty - Medium 
https://leetcode.com/problems/rotate-array/description/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        // Save the LAST k elements
        vector<int> temp(nums.begin() + (n - k), nums.end());

        // Shift elements RIGHT by k
        for (int i = n - 1; i >= k; i--) {
            nums[i] = nums[i - k];
        }

        // Place saved elements at the beginning
        for (int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }
    }
};
