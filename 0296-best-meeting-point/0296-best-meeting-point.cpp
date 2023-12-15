class Solution {
private:
    int minDistance1D(vector<int>& points, int origin){
        int dist = 0, i = 0, j = points.size() - 1;
        
        while (i < j){
            dist += points[j] - points[i];
            ++i;
            --j;
        }
        
        return dist;
    }
    
    vector<int> collectCols(vector<vector<int>>& grid){
        vector<int> cols;
        
        for (int col = 0; col < grid[0].size(); ++col){
            for (int row = 0; row < grid.size(); ++row){
                if (grid[row][col])
                    cols.push_back(col);
            }
        }
        
        return cols;
    }
    
    vector<int> collectRows(vector<vector<int>>& grid){
        vector<int> rows;
        
        for (int row = 0; row < grid.size(); ++row){
            for (int col = 0; col < grid[0].size(); ++col){
                if (grid[row][col]){
                    rows.push_back(row);
                }
            }
        }
        return rows;
    }
    
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> rows{collectRows(grid)}, cols{collectCols(grid)};
        int medianRow = rows[rows.size() / 2], medianCol = cols[cols.size() / 2];
        
        return minDistance1D(rows, medianRow) + minDistance1D(cols, medianCol);
    }
};