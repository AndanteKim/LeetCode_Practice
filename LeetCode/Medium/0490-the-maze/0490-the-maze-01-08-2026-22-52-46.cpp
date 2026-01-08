class Solution {
private:
    int m, n;
    bool isValid(int i, int j, vector<vector<int>>& maze) {
        return 0 <= i && i < m && 0 <= j && j < n && maze[i][j] == 0;
    }

public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        this -> m = maze.size(), this -> n = maze[0].size();
        queue<pair<int, int>> q;
        q.push({start[0], start[1]});
        vector<pair<int, int>> dirs{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        vector visited(m, vector<bool>(n, false));

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();

            if (x == destination[0] && y == destination[1]) return true;

            for (const auto& [dx, dy] : dirs) {
                int newX = x, newY = y;
                bool isMoved = false;
                while (isValid(newX, newY, maze)) {
                    newX += dx;
                    newY += dy;
                    isMoved = true;
                }

                if (isMoved) {
                    newX -= dx;
                    newY -= dy;
                }

                if (visited[newX][newY]) continue;
                visited[newX][newY] = true;
                q.push({newX, newY});
            }

        }

        return false;
    }
};