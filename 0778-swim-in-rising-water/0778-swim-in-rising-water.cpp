class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), ans = INT_MIN;
        set<pair<int, int>> seen;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});
        while (!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int dist = it[0], row = it[1], col = it[2];
            ans = max(ans, dist);
            if (row == n - 1 && col == n - 1) return ans;
            for (auto& [cr, cc] : {make_pair(row - 1, col), make_pair(row + 1, col), make_pair(row, col - 1), make_pair(row, col + 1)}){
                if (0 <= cr && cr < n && 0 <= cc && cc < n && seen.find(make_pair(cr, cc)) == seen.end()){
                    pq.push({grid[cr][cc], cr, cc});
                    seen.insert(make_pair(cr, cc));
                }
            }
        
        }
        
        return -1;
    }
};