class UnionFind{
    public:
    UnionFind(vector<vector<char>>& grid){
        count = 0;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (grid[i][j] == '1'){
                    parent.push_back(i * n + j);
                    ++count;
                }
                else parent.push_back(-1);
                rank.push_back(0);
            }
        }
    }
    
    int find(int x){
        if(parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void UnionSet(int x, int y){
        int xset = find(x), yset = find(y);
        if (xset != yset){
            if (rank[xset] > rank[yset]) parent[yset] = xset;
            else if (rank[xset] < rank[yset]) parent[xset] = yset;
            else {
                parent[yset] = xset;
                ++rank[xset];
            }
            --count;
        }
    }
    
    int getCount() const{
        return count;
    }
    private:
    vector<int> parent, rank;
    int count;
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        int nr = grid.size(), nc = grid[0].size();
        
        UnionFind unf(grid);
        for (int r = 0; r < nr; ++r){
            for (int c = 0; c < nc; ++c){
                if (grid[r][c] == '1'){
                    grid[r][c] = '0';
                    if (r >= 1 && grid[r-1][c] == '1') unf.UnionSet(r * nc + c, (r-1) * nc + c);
                    if (r < nr - 1 && grid[r+1][c] == '1') unf.UnionSet(r * nc + c, (r+1) * nc + c);
                    if (c >= 1 && grid[r][c-1] == '1') unf.UnionSet(r * nc + c, r * nc + c - 1);
                    if (c < nc - 1 && grid[r][c+1] == '1') unf.UnionSet(r * nc + c, r * nc + c + 1);
                }
            }
        }
        
        return unf.getCount();
    }
};