class Solution {
private:
    int m, n;

    bool isValid(int x, int y, vector<vector<int>>& maze) {
        return 0 <= x && x < m && 0 <= y && y < n && maze[x][y] == 0;
    }

    void dfs(int x, int y, vector<vector<int>>& minDists, vector<vector<int>>& maze) {
        for (const auto& [dx, dy] : vector<pair<int, int>>{{1, 0}, {-1, 0}, {0, -1}, {0, 1}}){
            int currX = x, currY = y, count = 0;

            while (isValid(currX + dx, currY + dy, maze)) {
                currX += dx;
                currY += dy;
                ++count;
            }

            if (minDists[currX][currY] > minDists[x][y] + count){
                minDists[currX][currY] = minDists[x][y] + count;
                dfs(currX, currY, minDists, maze);
            }
        }
    }

public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        this -> m = maze.size(), this -> n = maze[0].size();
        vector minDists(m, vector<int>(n, std::numeric_limits<int>::max()));
        minDists[start[0]][start[1]] = 0;

        dfs(start[0], start[1], minDists, maze);

        return minDists[destination[0]][destination[1]] == std::numeric_limits<int>::max()? -1 : minDists[destination[0]][destination[1]];
    }
};