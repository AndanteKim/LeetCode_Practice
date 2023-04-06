struct pathObj{
    int row, col, g, remain, f;
};

class Compare{
    public:
        bool operator()(pathObj& lhs, pathObj& rhs){
            return lhs.f > rhs.f;
        }
};

class Solution {
    int rows, cols;
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        rows = grid.size(), cols = grid[0].size();
        priority_queue<pathObj, vector<pathObj>, Compare> *pathQ = new priority_queue<pathObj, vector<pathObj>, Compare>;
        vector<vector<int>> visited(rows, vector<int>(cols, -1));
        pathObj start {0, 0, 0, k, 0};
        pathQ -> push(start);
        visited[0][0] = k;
        
        while (!pathQ -> empty()){
            pathObj curr = pathQ -> top();
            pathQ -> pop();
            
            if (curr.row == rows - 1 && curr.col == cols - 1) return curr.g;
            vector<pair<int, int>> directions{{curr.row + 1, curr.col}, {curr.row, curr.col + 1},\
                                              {curr.row - 1, curr.col}, {curr.row, curr.col - 1}};
            for (auto& [new_row, new_col] : directions){
                if (new_row < 0 || new_row >= rows || new_col < 0 || new_col >= cols) continue;
                    
                int f = curr.g + 1 + (rows - new_row) + (cols - new_col);
                pathObj next {new_row, new_col, curr.g + 1, curr.remain - grid[new_row][new_col], f};
                
                if (next.remain >= 0 && visited[next.row][next.col] < next.remain){
                    pathQ -> push(next);
                    visited[next.row][next.col] = next.remain;
                }
            }
        }
        
        return -1;
    }
};