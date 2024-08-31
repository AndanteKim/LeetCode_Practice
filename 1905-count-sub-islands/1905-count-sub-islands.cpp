// Union-Find class
class UnionFind{
private:
    vector<int> parent;
    vector<int> rank;
    
public:
    // Initialize union-find object with 'n' elements.
    UnionFind(int n){
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        rank.resize(n, 0);
    }
    
    // Find the root of element 'u', using the path-compression techinique.
    int find(int u){
        if (parent[u] != u)
            parent[u] = find(parent[u]);
        return parent[u];
    }
    
    // Union two components of elements 'u' and 'v' respectively on the
    // basis of their ranks.
    void unionSet(int u, int v){
        int rootU = find(u), rootV = find(v);
        
        if (rootU != rootV){
            if (rank[rootU] > rank[rootV]){
                parent[rootV] = rootU;
            }
            else if (rank[rootU] < rank[rootV]){
                parent[rootU] = rootV;
            }
            else{
                parent[rootV] = rootU;
                ++rank[rootU];
            }
        }
    }
};

class Solution {
private:
    int rows, cols;
    
    // Directions in which we can traverse inside the grids
    vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    
    // Helper method to check if the cell at the position (x, y) in the 'grid'
    // is a land cell.
    int isCellLand(int x, int y, vector<vector<int>>& grid){
        return grid[x][y] == 1;
    }
    
    // Helper method to convert (x, y) position to 1-dimensional index
    int convertToIndex(int x, int y){
        return x * cols + y;
    }
    
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        this -> rows = grid2.size(), this -> cols = grid2[0].size();
        int subIslandCounts = 0;
        
        UnionFind uf = UnionFind(rows * cols);
        
        // Traverse on each land cell of 'grid2'.
        for (int x = 0; x < rows ; ++x){
            for (int y = 0; y < cols; ++y){
                if (isCellLand(x, y, grid2)){
                    // Union adjacent land cells with the current land cell.
                    for (const auto& [dx, dy] : directions){
                        int nextX = x + dx, nextY = y + dy;
                        if (0 <= nextX && nextX < rows && 0 <= nextY && nextY < cols && \
                            isCellLand(nextX, nextY, grid2))
                            uf.unionSet(convertToIndex(x, y), convertToIndex(nextX, nextY));
                    }
                }
            }
        }
        
        // Traverse on 'grid2' land cells and mark that cell's root not a 
        // sub-island if land cell not present at the respective position in 'grid1'.
        vector<bool> isSubIslands(rows * cols, true);
        for (int x = 0; x < rows; ++x){
            for (int y = 0; y < cols; ++y){
                if (isCellLand(x, y, grid2) && !isCellLand(x, y, grid1)){
                    int root = uf.find(convertToIndex(x, y));
                    isSubIslands[root] = false;
                }
            }
        }
        
        // Count all the sub-islands.
        for (int x = 0; x < rows; ++x){
            for (int y = 0; y < cols; ++y){
                if (isCellLand(x, y, grid2)){
                    int root = uf.find(convertToIndex(x, y));
                    if (isSubIslands[root]){
                        ++subIslandCounts;
                        // One cell can be the root of multiple land cells, so
                        // to avoid counting the same island multiple times and
                        // mark it as false.
                        isSubIslands[root] = false;
                    }
                }
            }
        }
        
        return subIslandCounts;
    }
};