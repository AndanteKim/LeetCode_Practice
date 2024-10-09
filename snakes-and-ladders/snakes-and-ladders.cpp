class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(), label = 1;
        vector<pair<int, int>> cells(n * n + 1);
        vector<int> columns(n);
        iota(columns.begin(), columns.end(), 0);
        for (int row = n - 1; row >= 0; --row){
            for (int col : columns){
                cells[label++] = {row, col};
            }
            reverse(columns.begin(), columns.end());
        }
        
        vector<int> dist(n * n + 1, -1);
        dist[1] = 0;
        queue<int> queue;
        queue.push(1);
        
        while (!queue.empty()){
            int curr = queue.front(); queue.pop();
            
            for (int next = curr + 1; next <= min(curr + 6, n * n); ++next){
                auto [row, col] = cells[next];
                int dest = (board[row][col] != -1)? board[row][col] : next;
                
                if (dist[dest] == -1){
                    dist[dest] = dist[curr] + 1;
                    queue.push(dest);
                }
            }
        }
        
        return dist[n * n];
    }
};