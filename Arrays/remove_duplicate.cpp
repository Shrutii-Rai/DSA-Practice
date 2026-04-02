Leetcode - Remove duplicate elements from sorted array
Difficulty - Easy
https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0; 

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != nums[j]) {  
                j++;                   
                nums[j] = nums[i];    
            }
        }

        return j + 1;  // k = number of unique elements
    }
};