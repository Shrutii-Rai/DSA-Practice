GeeksForGeeks - Largest element in array
Difficulty - Easy
https://www.geeksforgeeks.org/problems/largest-element-in-array4009/1

class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int n = arr.size();
        int largest = arr[0];
        for (int i=0; i<n; i++){
            if (arr[i] > largest){
                largest = arr[i];
            }
        }
         }
        
        return largest;
    };
    