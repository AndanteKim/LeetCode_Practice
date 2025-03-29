class Solution {
private:
    // Directions for movement (right, down, left, up)
    vector<pair<int, int>> directions{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int m, n;
    bool isValid(int row, int col, vector<vector<bool>>& visited){
        return 0 <= row && row < m && 0 <= col && col < n && !visited[row][col];
    }

public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        this -> m = grid.size(), this -> n = grid[0].size();

        // Store queries along with their original indices to restore order later
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < queries.size(); ++i)
            sortedQueries.push_back({queries[i], i});

        // Sort queries by value in ascending order
        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> ans(queries.size(), 0);
        // Keep track of the number of cells processed
        int count = 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        // Min-heap (priority queue) to process cells in increasing order of value
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

        // Start from the top-left cell
        minHeap.push({grid[0][0], 0, 0});
        visited[0][0] = true;

        // Process queries in sorted order
        for (const auto& [val, i] : sortedQueries){
            // Expand the cells that are smaller than the current query value
            while (!minHeap.empty() && val > minHeap.top()[0]){
                const auto it = minHeap.top();
                minHeap.pop();
                int currVal = it[0], currRow = it[1], currCol = it[2];
                // Increment count of valid cells
                ++count;

                // Explore all four possible directions
                for (auto& [dr, dc] : directions){
                    int newRow = currRow + dr, newCol = currCol + dc;

                    // Check if the new cell is within bounds and not visited
                    if (isValid(newRow, newCol, visited)){
                        // Mark as visited
                        visited[newRow][newCol] = true;
                        minHeap.push({grid[newRow][newCol], newRow, newCol});
                    }
                }
            }

            // Store the result for this query
            ans[i] = count;
        }

        return ans;
    }
};