class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> total(rows, vector<int>(cols, 0));
        int emptyLandValue = 0, minDist = INT_MAX;
        
        for (int row = 0; row < rows; ++row){
            for (int col = 0; col < cols; ++col){
                if (grid[row][col] == 1){
                    minDist = INT_MAX;
                    queue<pair<int, int>> *q = new queue<pair<int, int>>;
                    int steps = 0;
                    q -> push({row, col});
                    
                    while (!q -> empty()){
                        ++steps;
                        for (int level = q -> size(); level > 0; --level){
                            int x = q -> front().first, y = q -> front().second;
                            q -> pop();
                            for (auto& [NextRow, NextCol] : {make_pair(x - 1, y), make_pair(x + 1, y), make_pair(x, y - 1),\
                                                           make_pair(x, y + 1)}){
                                if (NextRow >= 0 && NextRow < rows && NextCol >= 0 && NextCol < cols && \
                                   grid[NextRow][NextCol] == emptyLandValue){
                                    --grid[NextRow][NextCol];
                                    total[NextRow][NextCol] += steps;
                                    q -> push({NextRow, NextCol});
                                    minDist = min(minDist, total[NextRow][NextCol]);
                                }
                            }
                        }
                    }
                    --emptyLandValue;
                }
            }
        }
        return minDist == INT_MAX? -1 : minDist;
    }
};