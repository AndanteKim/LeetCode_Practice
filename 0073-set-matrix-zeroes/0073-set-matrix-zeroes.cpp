class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        queue<pair<int, int>> q;
        int m = matrix.size(), n = matrix[0].size();

        for (int i = 0; i < m; ++ i){
            for (int j = 0; j < n; ++j)
                if (matrix[i][j] == 0) q.push({i, j});
        }

        while (!q.empty()){
            auto [currRow, currCol] = q.front(); q.pop();

            for (int i = 0; i < n; ++i) matrix[currRow][i] = 0;

            for (int i = 0; i < m; ++i) matrix[i][currCol] = 0;
        }
    }
};