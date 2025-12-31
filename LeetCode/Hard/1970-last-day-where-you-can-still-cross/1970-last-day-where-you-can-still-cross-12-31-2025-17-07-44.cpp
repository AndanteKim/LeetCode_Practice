class Solution {
private:
    int rows, cols;
    bool isValid(int row, int col, vector<vector<bool>>& visited) {
        return 0 <= row && row < rows && 0 <= col && col < cols && !visited[row][col];
    }

    bool available(int days, vector<vector<int>>& cells) {
        vector grid(rows, vector<int>(cols, 0));
        vector visited(rows, vector<bool>(cols, false));

        for (int i = 0; i < days; ++i) {
            int r = cells[i][0] - 1, c = cells[i][1] - 1;
            grid[r][c] = 1;
        }

        queue<pair<int, int>> q;
        for (int i = 0; i < cols; ++i) if (grid[0][i] == 0) q.push({0, i});

        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();

            if (visited[r][c] || grid[r][c] == 1) continue;

            visited[r][c] = true;

            if (r == rows - 1) return true;

            for (const auto& [dr, dc] : vector<pair<int, int>> {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}){
                int newRow = r + dr, newCol = c + dc;
                if (isValid(newRow, newCol, visited)) q.push({newRow, newCol});
            }
        }

        return false;
    }

public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left = 0, right = cells.size() - 1;
        rows = row, cols = col;

        while (left <= right) {
            int mid = left + ((right - left) >> 1);

            if (available(mid, cells))
                left = mid + 1;
            else
                right = mid - 1;
        }

        return right;
    }
};