GFG - Finding second largest element in array
Difficulty - Easy
https://www.geeksforgeeks.org/problems/second-largest3735/1

class Solution {
public:
    int getSecondLargest(vector<int> &arr) {
        int n = arr.size();
        int largest = arr[n-1];
        int SecondL = -1;  
        for (int i = n-2; i >= 0; i--) {
            if (arr[i] != largest) {
                SecondL = arr[i]; 
                break;
            }
        }
        return SecondL; 
    }
};