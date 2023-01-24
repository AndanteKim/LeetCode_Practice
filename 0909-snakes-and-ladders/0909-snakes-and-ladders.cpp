class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(), label = 1;
        vector<pair<int, int>> cells(n*n + 1);
        vector<int> columns(n);
        iota(columns.begin(), columns.end(), 0);
        for(int row = n-1; row >= 0; --row){
            for(int col : columns){
                cells[label++] = {row, col};
            }
            reverse(columns.begin(), columns.end());
        }
        vector<int> dist(n*n + 1, -1);
        queue<int> q;
        dist[1] = 0;
        q.push(1);
        
        while (!q.empty()){
            int curr = q.front();
            q.pop();
            for (int next = curr + 1; next <= min(curr + 6, n * n); ++next){
                auto [row, col] = cells[next];
                int destination = board[row][col] != -1 ? board[row][col] : next;
                
                if (dist[destination] == -1){
                    dist[destination] = dist[curr] + 1;
                    q.push(destination);
                }
            }
        }
        
        return dist[n * n];
    }
};