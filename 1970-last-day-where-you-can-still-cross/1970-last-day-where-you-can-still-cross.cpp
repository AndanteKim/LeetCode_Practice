class Solution {
private:
    int r, c;
    bool valid(int x, int y, vector<vector<bool>>& visited){
        return 0 <= x && x < r && 0 <= y && y < c && !visited[x][y];
    }
    
    bool possible(int days, vector<vector<int>>& cells){
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        for (int i = 0; i <= days; ++i) visited[cells[i][0] - 1][cells[i][1] - 1] = true;
        
        queue<pair<int, int>> queue;
        for (int i = 0; i < c; ++i){
            if (!visited[0][i]) queue.push({0, i});   
        }
        
        while (!queue.empty()){
            auto [x, y] = queue.front();
            queue.pop();
            if (x == r - 1) return true;
            
            for (auto& [newX, newY] : vector<pair<int, int>>{{x + 1, y}, {x - 1, y}, {x, y + 1}, {x, y - 1}}){
                if (valid(newX, newY, visited)){
                    visited[newX][newY] = true;
                    queue.push({newX, newY});
                }
            }
        }
        
        return false;
    }
    
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        r = row, c = col;
        int left = 0, right = cells.size();
        
        while (left < right){
            int mid = left + ((right - left) >> 1);
            if (possible(mid, cells)) left = mid + 1;
            else right = mid;
        }
        
        return left;
    }
};