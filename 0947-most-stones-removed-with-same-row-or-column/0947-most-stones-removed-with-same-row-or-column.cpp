// Union-Find data structure for tracking connected components
class UnionFind{
private:
    vector<int> parent;
    int count;
    
public:
    UnionFind(int n){
        // Initialize all nodes as their own parent
        parent.resize(n, -1);
        
        // Initially, each stone is its own connected component
        count = n;
    }
    
    // Find the root of a node with path compression
    int find(int node){
        if (parent[node] == -1)
            return node;
        
        return find(parent[node]);
    }
    
    // Union two nodes, reducing the number of connected components
    void disjoint(int n1, int n2){
        int root1 = find(n1), root2 = find(n2);
        
        // If they're already in the same component, do nothing.
        if (root1 == root2)
            return;
        
        // Merge the components and reduce the count of connected components
        parent[root1] = root2;
        --count;
    }
    
    int getNumberOfConnectedComponents(){
        return count;
    }
};

class Solution {
private:
    int n;
    
public:
    int removeStones(vector<vector<int>>& stones) {
        this -> n = stones.size();
        
        // Populate uf by connecting stones sharing the same row or column
        UnionFind uf = UnionFind(n);
        for (int i = 0; i < n; ++i){
            for (int j = i + 1; j < n; ++j){
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                    uf.disjoint(i, j);
            }
        }
        
        return n - uf.getNumberOfConnectedComponents();
    }
};