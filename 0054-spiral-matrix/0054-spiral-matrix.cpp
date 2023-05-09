class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int visited = 101, rows = matrix.size(), cols = matrix[0].size();
        vector<pair<int, int>> directions {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int currentDirection = 0, changeDirection = 0, row = 0, col = 0;
        vector<int> ans{matrix[0][0]};
        matrix[0][0] = visited;
        
        while (changeDirection < 2){
            while (true){
                int nextRow = row + directions[currentDirection].first;
                int nextCol = col + directions[currentDirection].second;
                if (!((nextRow >= 0 && nextRow < rows) && (nextCol >= 0 && nextCol < cols))) break;
                if (matrix[nextRow][nextCol] == visited) break;
                changeDirection = 0;
                row = nextRow, col = nextCol;
                ans.push_back(matrix[row][col]);
                matrix[row][col] = visited;
            }
            currentDirection = (currentDirection + 1) % 4;
            ++changeDirection;
        }
        
        return ans;
    }
};