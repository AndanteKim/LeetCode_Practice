class Cell{
public:
    int x, y;
    int diff;
    Cell(int x, int y, int diff){
        this -> x = x;
        this -> y = y;
        this -> diff = diff;
    }
};

struct Comparator{
    bool operator()(Cell const &p1, Cell const &p2){
        return p2.diff < p1.diff;
    }
};

class Solution {
private:
    bool isValidCell(int x, int y, int row, int col){
        return x >= 0 && x < row && y >= 0 && y < col;
    }
    
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size(), col = heights[0].size();
        vector<vector<int>> diffMat(row, vector<int>(col, INT_MAX));
        diffMat[0][0] = 0;
        vector<vector<bool>> visited(row, vector<bool>(col));
        priority_queue<Cell, vector<Cell>, Comparator> queue;
        queue.push(Cell(0, 0, diffMat[0][0]));
        
        while (!queue.empty()){
            Cell curr = queue.top();
            queue.pop();
            visited[curr.x][curr.y] = true;
            if (curr.x == row - 1 && curr.y == col - 1) return curr.diff;
            for (auto& [dx, dy] : vector<pair<int, int>>{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}){
                int adjX = curr.x + dx, adjY = curr.y + dy;
                if (isValidCell(adjX, adjY, row, col) && !visited[adjX][adjY]){
                    int currDiff = abs(heights[adjX][adjY] - heights[curr.x][curr.y]);
                    int maxDiff = max(currDiff, diffMat[curr.x][curr.y]);
                    
                    if (diffMat[adjX][adjY] > maxDiff){
                        diffMat[adjX][adjY] = maxDiff;
                        queue.push(Cell(adjX, adjY, maxDiff));
                    }
                }
            }
        }
        
        return diffMat[row - 1][col - 1];
    }
};

