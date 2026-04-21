class UnionFind {
private:
    vector<int> parents;
    vector<int> rank;

public:
    UnionFind(int n) {
        parents.resize(n, 0);
        iota(parents.begin(), parents.end(), 0);
        rank.resize(n, 0);
    }

    int find(int x) {
        if (parents[x] != x) parents[x] = find(parents[x]);
        return parents[x];
    }

    void unite(int x, int y) {
        x = find(x), y = find(y);
        
        if (x == y) return;

        if (rank[x] < rank[y]) swap(x, y);
        parents[y] = x;

        if (rank[x] == rank[y]) ++rank[x];
    }
};


class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        UnionFind *uf = new UnionFind(n);
        unordered_map<int, unordered_map<int, int>> freq;

        for (const auto& v : allowedSwaps) {
            int a = v[0], b = v[1];
            uf -> unite(a, b);
        }
        
        for (int i = 0; i < n; ++i) {
            int f = uf -> find(i);
            ++freq[f][source[i]];
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int f = uf -> find(i);
            if (freq[f][target[i]] > 0) --freq[f][target[i]];
            else ++ans;
        }

        return ans;
    }
};