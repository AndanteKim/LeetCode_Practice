class DSU {
private:
    vector<int> root, size;
public:
    DSU(int n) {
        root.resize(n);
        iota(root.begin(), root.end(), 0);
        size.resize(n, 1);
    }

    int find(int x) {
        if (root[x] != x) root[x] = find(root[x]);

        return root[x];
    }

    void merge(int x, int y) {
        int rootX = find(x), rootY = find(y);

        if (rootX == rootY) return;

        if (size[rootX] > size[rootY])
            swap(rootX, rootY);
        
        root[rootX] = rootY;
        size[rootY] += size[rootX];
    }

};


class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        DSU *dsu = new DSU(row * col + 2);
        vector<pair<int, int>> dirs{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        vector grid(row, vector<int>(col, 1));

        for (int i = cells.size() - 1; i >= 0; --i) {
            int r = cells[i][0] - 1, c = cells[i][1] - 1;
            int idx1 = r * col + c + 1;
            grid[r][c] = 0;

            for (const auto& [dr, dc] : dirs) {
                int newR = r + dr, newC = c + dc;
                int idx2 = newR * col + newC + 1;
                if (0 <= newR && newR < row && 0 <= newC && newC < col && grid[newR][newC] == 0)
                    dsu -> merge(idx1, idx2);
            }

            if (r == 0) dsu -> merge(0, idx1);
            if (r == row - 1) dsu -> merge(row * col + 1, idx1);

            if (dsu -> find(0) == dsu -> find(row * col + 1)) return i;
        }

        return -1;
    }
};