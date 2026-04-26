class UnionFind {
private:
    int n, setCnt;
    vector<int> parents, size;

public:
    UnionFind(int n): n(n), setCnt(n) {
        parents.resize(n);
        iota(parents.begin(), parents.end(), 0);
        size.resize(n, 1);
    }

    int find(int x) {
        if (parents[x] == x) return x;

        parents[x] = find(parents[x]);
        return parents[x];
    }

    void unite(int x, int y) {
        if (size[x] < size[y]) {
            swap(x, y);
        }

        parents[y] = x;
        size[x] += size[y];
        --setCnt;
    }

    bool findAndUnite(int x, int y) {
        int parentX = find(x), parentY = find(y);
        if (parentX != parentY) {
            unite(parentX, parentY);
            return true;
        }
        return false;
    }

};


class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        UnionFind* uf = new UnionFind(m * n);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i > 0 && (grid[i][j] == grid[i - 1][j])){
                    if (!uf -> findAndUnite(i * n + j, (i - 1) * n + j)) return true;
                }

                if (j > 0 && (grid[i][j] == grid[i][j - 1])) {
                    if (!uf -> findAndUnite(i * n + j, i * n + j - 1)) return true;
                }
            }
        }

        return false;
    }
};