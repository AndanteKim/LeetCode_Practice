class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> memo(n, vector<int>(m, std::numeric_limits<int>::max()));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        minHeap.push(vector<int>{0, 0, 0});

        while (!minHeap.empty()){
            auto curr = minHeap.top(); minHeap.pop();

            int time = curr[0], i = curr[1], j = curr[2];

            // If time is larger than the minimum time
            if (time >= memo[i][j]) continue;

            memo[i][j] = min(memo[i][j], time);

            // Top
            if (i > 0) minHeap.push({1 + max(time, moveTime[i - 1][j]), i - 1, j});
            
            // Bottom
            if (i < n - 1) minHeap.push({1 + max(time, moveTime[i + 1][j]), i + 1, j});
            
            // Left
            if (j > 0) minHeap.push({1 + max(time, moveTime[i][j - 1]), i, j - 1});
            
            // Right
            if (j < m - 1) minHeap.push({1 + max(time, moveTime[i][j + 1]), i, j + 1});
        }

        return memo[n - 1][m - 1];
    }
};