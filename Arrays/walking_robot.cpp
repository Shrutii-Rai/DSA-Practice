Leetcode - Walking robot simulation
Difficulty - Medium
https://leetcode.com/problems/walking-robot-simulation/description/?envType=daily-question&envId=2026-04-06

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // Direction vectors: North, East, South, West
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        
        int x = 0, y = 0, dir = 0;
        int maxDist = 0;
        
        for (int cmd : commands) {
            if (cmd == -2) {
                dir = (dir + 3) % 4; // Turn left
            } else if (cmd == -1) {
                dir = (dir + 1) % 4; // Turn right
            } else {
                // Move forward k steps
                for (int i = 0; i < cmd; i++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    
                    // Brute force: check every obstacle one by one
                    bool blocked = false;
                    for (auto& obs : obstacles) {
                        if (obs[0] == nx && obs[1] == ny) {
                            blocked = true;
                            break;
                        }
                    }
                    
                    if (blocked) break;
                    x = nx;
                    y = ny;
                    maxDist = max(maxDist, x*x + y*y);
                }
            }
        }
        
        return maxDist;
    }
};