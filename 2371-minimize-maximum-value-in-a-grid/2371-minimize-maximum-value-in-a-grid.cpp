class Solution {
public:
    vector<vector<int>> minScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        // Create a vector nums storing the values of the matrix and their
        // indices.
        vector<tuple<int, int, int>> nums;
        
        // Create rows and cols to store the minimum values for every row and
        // column.
        vector<int> rows(m, 1), cols(n, 1);
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j)
                nums.push_back({grid[i][j], i, j});
        }
        
        sort(nums.begin(), nums.end(), [](auto& a, auto& b){return get<0>(a) < get<0>(b);});
        
        for (auto tup : nums){
            int val, i, j;
            tie(val, i, j) = tup;
            
            // Find the maximum value of rows[x] and cols[y] till now and assign
            // it to val.
            val = max(rows[i], cols[j]);
            grid[i][j] = val;
            
            // Update the new maximum value in rows[x] and cols[y].
            rows[i] = cols[j] = val + 1;
        }
        
        return grid;
    }
};