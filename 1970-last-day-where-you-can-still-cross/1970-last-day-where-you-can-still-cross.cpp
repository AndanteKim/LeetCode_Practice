class DSU{
private:
    vector<int> parents, rank;
    
public:
    DSU(int n){
        parents.resize(n);
        iota(parents.begin(), parents.end(), 0);
        rank.resize(n, 1);
    }
    
    int find(int x){
        if (parents[x] != x) parents[x] = find(parents[x]);
        return parents[x];
    }
    
    void UnionSet(int x, int y){
        int xset = find(x), yset = find(y);
        if (xset == yset) return;
        if (rank[xset] > rank[yset]) swap(xset, yset);
        parents[xset] = yset;
        rank[yset] = rank[xset];
    }
};

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        DSU dsu = DSU(row * col + 2);
        vector<vector<int>> grid(row, vector<int>(col, 1));
        vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = cells.size() - 1; i >= 0; --i){
            int r = cells[i][0] - 1, c = cells[i][1] - 1;
            grid[r][c] = 0;
            int idx1 = r * col + c + 1;
            for (auto& [dr, dc] : directions){
                int newR = r + dr, newC = c + dc;
                int idx2 = newR * col + newC + 1;
                if (0 <= newR && newR < row && 0 <= newC && newC < col && grid[newR][newC] == 0) dsu.UnionSet(idx1, idx2);
            }
            if (r == 0) dsu.UnionSet(0, idx1);
            if (r == row - 1) dsu.UnionSet(row * col + 1, idx1);
            if (dsu.find(0) == dsu.find(row * col + 1)) return i;
        }
        
        return -1;
    }
};