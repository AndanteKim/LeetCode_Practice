class Solution {
private:
    int m, n;
    vector<pair<int, int>> singleMove {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1},       // Straight Move
        {-1, 1}, {1, -1}, {1, 1}, {-1, -1},     // Diagonal Move
        {2, -1}, {2, 1}, {1, -2}, {1, 2},       // Extended Move
        {-2, -1}, {-2, 1}, {-1, 2}, {-1, -2}     
    };

    vector<pair<int, int>> skipDotMove {
        {2, 0}, {-2, 0}, {0, 2}, {0, -2},       // Straight skip
        {2, 2}, {-2, 2}, {2, -2}, {-2, -2}      // Diagonal skip
    };

    int isValid(int r, int c, vector<vector<bool>>& visited) {
        return 0 <= r && r < 3 && 0 <= c && c < 3 && !visited[r][c];
    }

    int countPatterns(int currLen, int currRow, int currCol, vector<vector<bool>>& visited) {
        // Base case
        if (currLen > n) return 0;

        int valid = 0;
        if (currLen >= m) ++valid;

        visited[currRow][currCol] = true;
        for (const auto& [dr, dc] : singleMove) {
            int newRow = currRow + dr, newCol = currCol + dc;
            if (isValid(newRow, newCol, visited)) {
                valid += countPatterns(currLen + 1, newRow, newCol, visited);
            }
        }


        for (const auto& [dr, dc] : skipDotMove) {
            int newRow = currRow + dr, newCol = currCol + dc;
            if (isValid(newRow, newCol, visited)) {
                int midRow = currRow + (dr >> 1), midCol = currCol + (dc >> 1);
                
                if (visited[midRow][midCol])
                    valid += countPatterns(currLen + 1, newRow, newCol, visited);
            }
        }
        visited[currRow][currCol] = false;

        return valid;
    }

public:
    int numberOfPatterns(int m, int n) {
        this -> m = m, this -> n = n;
        vector visited(3, vector<bool>(3, false));

        int ans = 0;
        for (int r = 0; r < 3; ++r) {
            for (int c = 0; c < 3; ++c){
                ans += countPatterns(1, r, c, visited);
            }
        }

        return ans;
    }
};