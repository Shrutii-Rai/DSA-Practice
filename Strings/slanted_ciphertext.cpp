Leetcode - Decode the Slanted Ciphertext
Difficulty - Medium
https://leetcode.com/problems/decode-the-slanted-ciphertext/description/?envType=daily-question&envId=2026-04-04

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        int cols = n / rows;
        
        // Build the matrix
        vector<vector<char>> matrix(rows, vector<char>(cols));
        int idx = 0;
        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++)
                matrix[r][c] = encodedText[idx++];
        
        string result = "";
        for (int startCol = 0; startCol < cols; startCol++) {
            int r = 0, c = startCol;
            while (r < rows && c < cols) {
                result += matrix[r][c];
                r++;
                c++;
            }
        }
        
        // Strip trailing spaces
        while (!result.empty() && result.back() == ' ')
            result.pop_back();
        
        return result;
    }
};