class Solution {
private:
    int m, n;
    bool valid(int x, int y){
        return 0 <= x && x < m && 0 <= y && y < n;
    }
    
    bool dfs(int k, vector<vector<int>>& heights){
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        stack<pair<int, int>> stack;
        stack.push({0, 0});
        
        
        while (!stack.empty()){
            auto [r, c] = stack.top();
            stack.pop();
            if (r == m - 1 && c == n - 1) return true;
            
            for (auto& [dr, dc] : vector<pair<int, int>>{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}){
                int new_r = r + dr, new_c = c + dc;
                if (valid(new_r, new_c) && !visited[new_r][new_c]){
                    if (abs(heights[new_r][new_c] - heights[r][c]) <= k){
                        visited[new_r][new_c] = true;
                        stack.push({new_r, new_c});
                    }
                }
            }
        }
        
        return false;
    }
    
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();
        
        int left = 0, right = 0;
        for (int i = 0; i < m; ++i) for(int j = 0; j < n; ++j) right = max(right, heights[i][j]);
        
        
        while (left <= right){
            int mid = left + (right - left) / 2;
    
            if (dfs(mid, heights)) right = mid - 1;
            else left = mid + 1;
        }
        
        return left;
    }
};