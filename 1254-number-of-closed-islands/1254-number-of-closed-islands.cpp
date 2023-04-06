class UnionFind {
    vector<int> parents, ranks;
public:
    UnionFind(int size){
        parents.resize(size);
        iota(parents.begin(), parents.end(), 0);
        ranks.resize(size, 0);
    }
    
    int find(int x){
        if (parents[x] != x) parents[x] = find(parents[x]);
        return parents[x];
    }
    
    void UnionSet(int x, int y){
        int xset = find(x), yset = find(y);
        if (xset == yset) return;
        if (ranks[xset] < ranks[yset]) parents[xset] = yset;
        else if (ranks[xset] > ranks[yset]) parents[yset] = xset;
        else{
            parents[yset] = xset;
            ++ranks[xset];
        }
    }
};

class Solution {
    int m, n;
    vector<pair<int, int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int islands = 0;
        
        UnionFind uf(m * n);
        for (int y = 0; y < m; ++y){
            for (int x = 0; x < n; ++x){
                if (grid[y][x] == 0){
                    ++islands;
                    for (auto& [dy, dx] : directions){
                        int new_row = y + dy, new_col = x + dx;
                        if (0 <= new_row && new_row < m && 0 <= new_col && new_col < n && grid[new_row][new_col] == 0){
                            if (uf.find(y * n + x) != uf.find(new_row * n + new_col)){
                                --islands;
                                uf.UnionSet(y * n + x, new_row * n + new_col);
                            }
                        }
                    }
                }
            }
        }
        
        unordered_set<int> open_islands;
        for (int y = 0; y < m; ++y){
            if (grid[y][0] == 0) open_islands.insert(uf.find(y * n));
            if (grid[y][n - 1] == 0) open_islands.insert(uf.find(y * n + n - 1));
        }
        
        for (int x = 0; x < n; ++x){
            if (grid[0][x] == 0) open_islands.insert(uf.find(x));
            if (grid[m - 1][x] == 0) open_islands.insert(uf.find((m - 1) * n + x));
        }
        
        return islands - open_islands.size();
    }
};