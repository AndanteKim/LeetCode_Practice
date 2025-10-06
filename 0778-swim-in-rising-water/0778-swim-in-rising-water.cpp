class Solution {
private:
    int n;

    bool isValid(int x, int y, vector<vector<bool>>& visited){
        return x >= 0 && x < n && y >= 0 && y < n && !visited[x][y];
    }

    bool isPossible(int t, vector<vector<int>>& grid){
        queue<pair<int, int>> q;
        q.push({0, 0});
        vector visited(n, vector<bool>(n, false));
        visited[0][0] = true;

        while (!q.empty()){
            auto [x, y] = q.front(); q.pop();

            if (x == n - 1 && y == n - 1) return true;

            for (auto [dx, dy] : vector<pair<int, int>>{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}){
                int newX = x + dx, newY = y + dy;

                if (isValid(newX, newY, visited) && grid[newX][newY] <= t){
                    visited[newX][newY] = true;
                    q.push({newX, newY});
                }
            }
        }

        return false;
    }

public:
    int swimInWater(vector<vector<int>>& grid) {
        this -> n = grid.size();

        int ans = -1, left = grid[0][0], right = n * n + 1, mid;

        while (left <= right){
            mid = left + ((right - left) >> 1);

            if (isPossible(mid, grid)){
                ans = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }

        return ans;
    }
};