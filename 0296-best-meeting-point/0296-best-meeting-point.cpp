class Solution {
private:
    int minDistance1D(vector<int>& points, int origin){
        int dist = 0;
        
        for (int pt : points)
            dist += abs(pt - origin);
        
        return dist;
    }
    
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> rows, cols;
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (grid[i][j]){
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        
        // To find median of cols, we need to sort cols vector
        sort(cols.begin(), cols.end());
        int row = rows[rows.size() / 2], col = cols[cols.size() / 2];
        
        return minDistance1D(rows, row) + minDistance1D(cols, col);
    }
};