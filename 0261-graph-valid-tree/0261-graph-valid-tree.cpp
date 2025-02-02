class UnionFind{
private:
    // For efficiency, we aren't using makeset, but instead initializing
    // all the sets at the same time in the constructor.
    vector<int> parent, rootSize;

public:
    UnionFind(int n){
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        // We use this to keep track of the size of each set.
        rootSize.resize(n, 1);
    }

    // The find method, with path compression. There are ways of implementing
    // this elegantly with recursion, but the iterative version is easier ofr
    // most people to understand!
    int find(int node){
        // Step 1: Find the root.
        int root = parent[node];

        while (root != parent[root])
            root = find(parent[root]);

        // Step 2: Do a second traversal, this time setting each node to point
        // directly at node as we go.
        while (node != root){
            int oldNode = parent[node];
            parent[node] = root;
            node = parent[oldNode];
        }

        return root;
    }

    // The unite method, with optimization union by size. It returns true if a merge happend,
    // false if otherwise.
    bool unite(int u, int v){
        // Find the roots for u and v.
        int rootU = find(u), rootV = find(v);
        
        // Check if u and v already in the same set.
        if (rootU == rootV) return false;

        // We want to ensure the larger set remains the root.
        if (rootSize[rootU] < rootSize[rootV]){
            // Make rootV the overall root.
            parent[rootU] = rootV;
            // The size of the set rooted at v is the sum of the 2.
            rootSize[rootV] += rootSize[rootU];
        }
        else{
            // Make rootU the overall root.
            parent[rootV] = rootU;
            // The size of the set rooted at u is the sum of the 2.
            rootSize[rootU] += rootSize[rootV];
        }

        return true;
    }

};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // Base case: The graph must contain n - 1 edges
        if (edges.size() != n - 1) return false;

        // Create a new UnionFind object with n nodes.
        UnionFind *uf = new UnionFind(n);

        // Add each edge. Check if a merge happened because if it didn't
        //, there must be a cycle.
        for (const vector<int>& edge : edges){
            int u = edge[0], v = edge[1];
            if (!uf -> unite(u, v)) return false;
        }

        // If we got this far, there's no cycles!
        return true;
    }
};