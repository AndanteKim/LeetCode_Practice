class Solution {
public:
    int minKnightMoves(int x, int y) {
        vector<pair<int, int>> directions {{2, 1}, {1, 2}, {-1, 2}, {-2, 1},\
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
        
        queue<pair<pair<int, int>, int>> queue;
        queue.push({{0, 0}, 0});
        vector visited(607, vector<bool>(607));
        
        while (!queue.empty()){
            auto[coordinate, steps] = queue.front();
            auto[currX, currY] = coordinate;
            queue.pop();
            
            if (currX == x && currY == y)
                return steps;
            
            for (auto& [dx, dy] : directions){
                int nextX = currX + dx, nextY = currY + dy;
                if (!visited[nextX + 302][nextY + 302]){
                    visited[nextX + 302][nextY + 302] = true;
                    queue.push({{nextX, nextY}, steps + 1});
                }
            }
        }
        
        return -1;
    }
};