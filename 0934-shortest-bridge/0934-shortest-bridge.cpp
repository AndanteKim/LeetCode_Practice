class Solution {
private:
    int n;
    
    void dfs(int x, int y, vector<pair<int, int>>& bfsQueue, vector<vector<int>>& grid){
        grid[x][y] = 2;
        bfsQueue.push_back({x, y});
        for (auto& [curX, curY] : vector<pair<int, int>>{{x + 1, y}, {x - 1, y}, {x, y + 1}, {x, y - 1}}){
            if ((curX >= 0 && curX < n) && (curY >= 0 && curY < n) && grid[curX][curY] == 1)
                dfs(curX, curY, bfsQueue, grid);
        }
    }
    
public:
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        int firstX = -1, firstY = -1;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                if (grid[i][j]){
                    firstX = i, firstY = j;
                    break;
                }
            } 
        }
        
        vector<pair<int, int>> bfsQueue;
        dfs(firstX, firstY, bfsQueue, grid);
        int dist = 0;
        
        while (!bfsQueue.empty()){
            vector<pair<int, int>> newBFS;
            for (auto& [x, y] : bfsQueue){
                for (auto& [curX, curY] : vector<pair<int, int>>{{x + 1, y}, {x - 1, y}, {x, y + 1}, {x, y - 1}}){
                    if ((curX >= 0 && curX < n) && (curY >= 0 && curY < n)){
                        if (grid[curX][curY] == 1) return dist;
                        else if (grid[curX][curY] == 0){
                            newBFS.push_back({curX, curY});
                            grid[curX][curY] = -1;
                        }
                    }
                }
            }
            bfsQueue = newBFS;
            ++dist;
        }
        return dist;
    }
};