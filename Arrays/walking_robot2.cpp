Leetcode - Walking robot simulation
Difficulty - Medium
https://leetcode.com/problems/walking-robot-simulation-ii/submissions/1971874645/?envType=daily-question&envId=2026-04-07

class Robot {
public:
    int W, H, perimeter;
    long long totalSteps = 0;
    
    Robot(int width, int height) {
        W = width; H = height;
        perimeter = 2*(W-1) + 2*(H-1);
    }
    
    void step(int num) {
        totalSteps += num;
    }
    
    pair<int,int> getSegment() {
        if (totalSteps == 0) return {0, 0};
        int pos = totalSteps % perimeter;
        if (pos == 0) return {3, H-1}; // origin after full loop → South
        
        if (pos <= W-1) return {0, pos};        // East: (0,0) exclusive to (W-1,0) inclusive
        int p = pos - (W-1);
        if (p <= H-1) return {1, p};            // North: up to (W-1,H-1) inclusive
        p -= (H-1);
        if (p <= W-1) return {2, p};            // West: up to (0,H-1) inclusive
        p -= (W-1);
        return {3, p};                           // South
    }
    
    vector<int> getPos() {
        auto [seg, off] = getSegment();
        if (seg == 0) return {off, 0};
        if (seg == 1) return {W-1, off};
        if (seg == 2) return {W-1-off, H-1};
                      return {0, H-1-off};
    }
    
    string getDir() {
        auto [seg, off] = getSegment();
        if (seg == 0) return "East";
        if (seg == 1) return "North";
        if (seg == 2) return "West";
                      return "South";
    }
};