class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        const pair<int, int> direction[4]{{-1,0},{1,0},{0,-1},{0,1}};
        int rows = grid.size(), cols = grid[0].size();
        
        int visited[rows][cols];
        
        queue<pair<int, int>> q;
        
        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < cols; ++j){
                visited[i][j] = grid[i][j];
                if (grid[i][j]) q.push({i, j});
            }
        }
        
        int distance = -1;
        
        while(!q.empty()){
            int qSize = q.size();
            
            while(qSize--){
                pair<int, int> landCell = q.front();
                q.pop();
                
                for (const pair<int, int> dir: direction){
                    int x = landCell.first + dir.first;
                    int y = landCell.second + dir.second;
                    
                    if (x >= 0 && y >= 0 && x < rows && y < cols && visited[x][y] == 0){
                        visited[x][y] = 1;
                        q.push({x, y});
                    }
                }
            }
            
            ++distance;
        }
        
        return distance == 0? -1 : distance;
    }
};