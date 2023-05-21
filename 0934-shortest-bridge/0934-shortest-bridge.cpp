class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int firstX = -1, firstY = -1;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                if (grid[i][j] == 1){
                    firstX = i, firstY = j;
                    break;
                }
            }
        }
        
        vector<pair<int, int>> bfsQ{{firstX, firstY}}, secondBFSQ{{firstX, firstY}};
        grid[firstX][firstY] = 2;
        
        while (!bfsQ.empty()){
            vector<pair<int, int>> newBFS;
            for (auto& [x, y] : bfsQ){
                for (auto& [curX, curY] : vector<pair<int, int>>{{x + 1, y}, {x - 1, y}, {x, y + 1}, {x, y - 1}}){
                    if ((curX >= 0 && curX < n) && (curY >= 0 && curY < n) && grid[curX][curY] == 1){
                        newBFS.push_back({curX, curY});
                        secondBFSQ.push_back({curX, curY});
                        grid[curX][curY] = 2;
                    }
                }
            }
            bfsQ = newBFS;
        }
        
        int dist = 0;
        while (!secondBFSQ.empty()){
            vector<pair<int, int>> newBFS;
            for (auto& [x, y] : secondBFSQ){
                for (auto& [curX, curY] : vector<pair<int, int>>{{x + 1, y}, {x - 1, y}, {x, y - 1}, {x, y + 1}}){
                    if ((0 <= curX && curX < n) && (0 <= curY && curY < n)){
                        if (grid[curX][curY] == 1) return dist;
                        else if (grid[curX][curY] == 0){
                            newBFS.push_back({curX, curY});
                            grid[curX][curY] = -1;
                        }
                    }
                }
            }
            secondBFSQ = newBFS;
            ++dist;
        }
        return dist;
    }
};