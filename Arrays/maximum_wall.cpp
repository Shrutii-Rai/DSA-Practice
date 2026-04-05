Leetcode - Maximum walls destroyed by robots
Difficulty - hard
https://leetcode.com/problems/maximum-walls-destroyed-by-robots/description/

class wall {
public:
    int n;
    vector<array<int,2>> arr;
    vector<int> walls;
    int f[100001][2];

    int lowerBound(int val) {
        return (int)(lower_bound(walls.begin(), walls.end(), val) - walls.begin());
    }

    // j = firing direction of the NEXT robot (0=left, 1=right)
    int dfs(int i, int j) {
        if (i < 0) return 0;
        if (f[i][j] != -1) return f[i][j];

        // Option 1: robot i fires LEFT
        int left = arr[i][0] - arr[i][1];
        if (i > 0) left = max(left, arr[i-1][0] + 1); // blocked by prev robot
        int l = lowerBound(left);
        int r = lowerBound(arr[i][0] + 1);
        int ans = dfs(i-1, 0) + (r - l); // prev robot can fire either way -> pass 0

        // Option 2: robot i fires RIGHT
        int right = arr[i][0] + arr[i][1];
        if (i + 1 < n) {
            if (j == 0)
                // next robot fires LEFT: its left range starts at arr[i+1][0] - arr[i+1][1]
                // so current robot's right is clamped to just before that
                right = min(right, arr[i+1][0] - arr[i+1][1] - 1);
            else
                // next robot fires RIGHT: bullet blocked by next robot's body
                right = min(right, arr[i+1][0] - 1);
        }
        l = lowerBound(arr[i][0]);
        r = lowerBound(right + 1);
        ans = max(ans, dfs(i-1, 1) + (r - l));

        return f[i][j] = ans;
    }

    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        n = robots.size();
        arr.resize(n);
        for (int i = 0; i < n; i++)
            arr[i] = {robots[i], distance[i]};
        sort(arr.begin(), arr.end());

        this->walls = walls;
        sort(this->walls.begin(), this->walls.end());

        memset(f, -1, sizeof(f));
        return dfs(n-1, 1);
    }
};
