class Solution {
private:
    int r, c;
    bool isValid(int x, int y){
        return 0 <= x && x < r && 0 <= y && y < c;
    }
    
    bool isPossible(int threshold, vector<vector<int>>& heights){
        vector<vector<bool>> visited(r, vector<bool>(c));
        queue<pair<int, int>> queue;
        queue.push(make_pair(0, 0));
        visited[0][0] = true;
        
        while (!queue.empty()){
            auto [x, y] = queue.front();
            queue.pop();
            
            if (x == r - 1 && y == c - 1) return true;
            
            for (auto& [dx, dy] : vector<pair<int, int>>{make_pair(1, 0), make_pair(-1, 0), make_pair(0, 1), make_pair(0, -1)}){
                int newX = x + dx, newY = y + dy;
                if (isValid(newX, newY) && !visited[newX][newY] && abs(heights[newX][newY] - heights[x][y]) <= threshold){
                    visited[newX][newY] = true;
                    queue.push({newX, newY});
                }
            }
        }
        
        return false;
    }
    
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        this -> r = heights.size(), this -> c = heights[0].size();
        int left = 0, right = 0;
        for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) right = max(right, abs(heights[i][j] - heights[0][0]));
        
        while (left <= right){
            int mid = left + ((right - left) >> 1);
            
            if (isPossible(mid, heights))
                right = mid - 1;
            else left = mid + 1;
        }
        
        return left;
    }
};