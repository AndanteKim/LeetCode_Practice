class Solution {
private:
    int m, n;
    bool isValid(int x, int y, vector<vector<int>>& maze) {
        return 0 <= x && x < m && 0 <= y && y < n && maze[x][y] == 0;
    }

public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        this -> m = maze.size(), this -> n = maze[0].size();
        vector minDists(m, vector<int>(n, std::numeric_limits<int>::max()));
        minDists[start[0]][start[1]] = 0;

        // Dijkstra & priority queue
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap;
        minHeap.push({0, start[0], start[1]});

        while (!minHeap.empty()) {
            const auto [dist, x, y] = minHeap.top(); minHeap.pop();

            for (const auto [dx, dy] : vector<pair<int, int>>{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
                int currX = x, currY = y, count = 0;

                while (isValid(currX + dx, currY + dy, maze)) {
                    currX += dx;
                    currY += dy;
                    ++count;
                }

                if (minDists[currX][currY] > minDists[x][y] + count) {
                    minDists[currX][currY] = minDists[x][y] + count;
                    minHeap.push({minDists[currX][currY], currX, currY});
                }
            }
        }

        return minDists[destination[0]][destination[1]] == std::numeric_limits<int>::max()? -1 : minDists[destination[0]][destination[1]];
    }
};