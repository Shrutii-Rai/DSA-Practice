Leetcode - Robot Collisions question
Difficulty - hard
https://leetcode.com/problems/robot-collisions/description/

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        
        // Sort indices by position
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });
        
        stack<int> st; // stack of indices of right-moving robots
        
        for (int i : idx) {
            if (directions[i] == 'R') {
                st.push(i);
            } else {
                // Left-moving robot, process collisions
                while (!st.empty() && healths[i] > 0) {
                    int top = st.top();
                    if (healths[top] > healths[i]) {
                        // Right robot wins
                        healths[top]--;
                        healths[i] = 0;
                    } else if (healths[top] < healths[i]) {
                        // Left robot wins
                        healths[i]--;
                        healths[top] = 0;
                        st.pop();
                    } else {
                        // Both die
                        healths[i] = 0;
                        healths[top] = 0;
                        st.pop();
                    }
                }
            }
        }
        
        // Collect survivors in original order
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (healths[i] > 0)
                result.push_back(healths[i]);
        }
        return result;
    }
};