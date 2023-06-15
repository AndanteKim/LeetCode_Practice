class UnionFind{
private:
    vector<int> parents;
    vector<int> rank;
    
public:
    UnionFind(int n){
        parents.resize(n * n);
        iota(parents.begin(), parents.end(), 0);
        rank.resize(n * n, 0);
    }
    
    int find(int x){
        if (x != parents[x]) parents[x] = find(parents[x]);
        return parents[x];
    }
    
    void unionSet(int x, int y){
        int xset = find(x), yset = find(y);
        
        if (xset == yset) return;
        if (rank[xset] > rank[yset]) parents[yset] = xset;
        else if (rank[xset] == rank[yset]) {
            parents[yset] = xset;
            ++rank[xset];
        }
        else parents[xset] = yset;
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<pair<int, int>> positions;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j)
                positions.push_back(make_pair(i, j));
        }
        sort(positions.begin(), positions.end(), [grid](pair<int, int> &p1, pair<int, int> &p2){return grid[p1.first][p1.second] < grid[p2.first][p2.second];});
        UnionFind uf = UnionFind(n);
        
        for (auto& [i, j] : positions){
            for (auto& [x, y] : vector<pair<int, int>>{make_pair(i + 1, j), make_pair(i - 1, j), make_pair(i, j + 1), make_pair(i, j - 1)}){
                if (0 <= x && x < n && 0 <= y && y < n && visited[x][y]) uf.unionSet(i * n + j, x * n + y);
            }
            if (uf.find(0) == uf.find(n * n - 1)) return grid[i][j];
            visited[i][j] = true;
        }
        return -1;
    }
};