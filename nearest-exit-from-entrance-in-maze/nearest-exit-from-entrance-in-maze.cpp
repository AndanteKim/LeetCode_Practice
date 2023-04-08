class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = maze.size(), cols = maze[0].size();
        queue<vector<int>> *q = new queue<vector<int>>;
        q -> push({entrance[0], entrance[1], 0});
        maze[entrance[0]][entrance[1]] = '+';
        
        while (!q -> empty()){
            int x = q -> front()[0], y = q -> front()[1], steps = q -> front()[2];
            q -> pop();
            
            for (auto& [new_row, new_col] : {make_pair(x - 1, y), make_pair(x + 1, y), make_pair(x, y + 1), make_pair(x, y - 1)}){
                if ((new_row >= 0 && new_row < rows) && (new_col >= 0 && new_col < cols) && maze[new_row][new_col] == '.'){
                    if (new_row == 0 || new_row == rows - 1 || new_col == 0 || new_col == cols - 1) return steps + 1;
                    maze[new_row][new_col] = '+';
                    q -> push({new_row, new_col, steps + 1});
                }
            }
        }
        
        return -1;
    }
};