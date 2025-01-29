class DSU{
private:
    vector<int> size, representatives;

    // Return the ultimate representative of the node.
    int find(int node){
        if (representatives[node] == node)
            return node;
        return representatives[node] = find(representatives[node]);
    }

public:
    // Initialize DSU class, size of each component will be one and each node
    // will be representative of it's own.
    DSU(int n){
        size.resize(n, 1);
        representatives.resize(n);
        iota(representatives.begin(), representatives.end(), 0);
    }
    
    // Return true if node1 and 2 belong to different component and update the representatives accordingly,
    // otherwise returns false.
    bool doUnion(int node1, int node2){
        node1 = find(node1), node2 = find(node2);

        if (node1 == node2)
            return false;

        else{
            if (size[node1] > size[node2]){
                representatives[node2] = node1;
                size[node1] += size[node2];
            }
            else{
                representatives[node1] = node2;
                size[node2] += size[node1];
            }
            return true;
        }
    }
};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU* dsu = new DSU(n);

        for (const vector<int>& edge : edges){
            // If union returns false, we know the nodes are already connected
            // and hence we can return this edge.
            if (!dsu -> doUnion(edge[0] - 1, edge[1] - 1))
                return edge;
        }

        return vector<int>{};
    }
};