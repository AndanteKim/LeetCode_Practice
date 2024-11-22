class Solution {
public:
    vector<vector<int>> minScore(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        
        // Min-heap to store elements with their values and coordinates
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap;
        // Initialize rows and cols arrays to keep track of maximum values assigned
        vector<int> rows(row, 1), cols(col, 1);
        
        // Populate the min-heap with all elements of the grid
        for (int i = 0; i < row; ++i){
            for (int j = 0; j < col; ++j)
                minHeap.push({grid[i][j], i, j});
        }
        
        // Process elements in ascending order of their values
        while (!minHeap.empty()){
            auto [_, i, j] = minHeap.top();
            minHeap.pop();
            
            // Determine the smallest assignable value based on rows and cols constraints
            int val = max(rows[i], cols[j]);
            grid[i][j] = val;
            
            // Update rows and cols arrays with the next possible value for each row and column
            rows[i] = cols[j] = val + 1;
        }
        
        return grid;
    }
};