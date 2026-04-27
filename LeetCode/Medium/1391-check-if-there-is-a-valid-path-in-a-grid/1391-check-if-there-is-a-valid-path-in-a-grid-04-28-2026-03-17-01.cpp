class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        unordered_map<int, vector<pair<int, int>>> dirs{
            {1, {{0, -1}, {0, 1}}},
            {2, {{-1, 0}, {1, 0}}},
            {3, {{0, -1}, {1, 0}}},
            {4, {{0, 1}, {1, 0}}},
            {5, {{0, -1}, {-1, 0}}},
            {6, {{0, 1}, {-1, 0}}}
        };

        vector<vector<bool>> visited(m, vector<bool>(n));
        auto notValid { [&] (int r, int c) -> bool {
            return r < 0 || r >= m || c < 0 || c >= n || visited[r][c];
        }
        };
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();

            if (r == m - 1 && c == n - 1) return true;

            for (const auto& [dr, dc] : dirs[grid[r][c]]){
                int newR = r + dr, newC = c + dc;

                if (notValid(newR, newC)) continue;
                
                for (const auto& [backR, backC] : dirs[grid[newR][newC]]) {
                    if (newR + backR == r && newC + backC == c){
                        visited[newR][newC] = true;
                        q.push({newR, newC});
                    }
                }

            }

        }

        return false;
    }
};