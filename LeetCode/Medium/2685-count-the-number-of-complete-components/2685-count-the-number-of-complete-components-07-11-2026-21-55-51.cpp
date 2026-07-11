class UnionFind {
private:
    vector<int> parents, sizes;

public:
    UnionFind(int n) {
        parents.resize(n, -1);
        sizes.resize(n, 1);
    }

    int find(int node) {
        if (parents[node] == -1) return node;

        parents[node] = find(parents[node]);
        return parents[node];
    }

    void merge(int n1, int n2) {
        if (n1 == n2) return;

        int r1 = find(n1), r2 = find(n2);
        if (r1 == r2) return;

        if (sizes[r1] > sizes[r2]) {
            parents[r2] = r1;
            sizes[r1] += sizes[r2];
        }
        else {
            parents[r1] = r2;
            sizes[r2] += sizes[r1];
        }
    }

    int getSizes(int node) {
        return sizes[node];
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        UnionFind* dsu = new UnionFind(n);
        vector<int> edgesCnt(n);

        for (const auto& edge : edges) {
            dsu -> merge(edge[0], edge[1]);
        }

        for (const auto& edge : edges) {
            int root = dsu -> find(edge[0]);
            ++edgesCnt[root];
        }

        int completeCnt = 0;
        for (int node = 0; node < n; ++node) {
            if (dsu -> find(node) == node) {
                int nodeCnt = dsu -> getSizes(node);
                int expected = ((long long)nodeCnt * (nodeCnt - 1)) >> 1;

                if (edgesCnt[node] == expected) ++completeCnt;
            }
        }

        return completeCnt;
    }
};