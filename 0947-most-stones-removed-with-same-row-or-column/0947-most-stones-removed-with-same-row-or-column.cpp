// Union-Find data structure for tracking connected components
class UnionFind{
private:
    vector<int> parent;
    
    // Initialize the set to track unique nodes
    unordered_set<int> uniqueNodes;
    int componentCount;
    
public:
    UnionFind(int n){
        // Initialize all nodes as their own parent
        parent.resize(n, -1);
        
        // Initialize the count of connected components
        componentCount = 0;
    }
    
    // Find the root of a node with path compression
    int find(int node){
        // If node isn't marked, increase the component count
        if (!uniqueNodes.count(node)){
            uniqueNodes.insert(node);
            ++componentCount;
        }
        
        if (parent[node] == -1)
            return node;
        
        return parent[node] = find(parent[node]);
    }
    
    // Union two nodes, reducing the number of connected components
    void disjoint(int n1, int n2){
        int root1 = find(n1), root2 = find(n2);
        
        // If they're already in the same component, do nothing.
        if (root1 == root2)
            return;
        
        // Merge the components and reduce the component count
        parent[root1] = root2;
        --componentCount;
    }
    
    int getComponentCount(){
        return componentCount;
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        
        // Initialize UnionFind with a large enough range to handle coordinates
        UnionFind uf = UnionFind(20002);
        
        // Union stones sharing the same row or column
        for (vector<int>& stone : stones){
            int x = stone[0], y = stone[1];
            // Offset y-coordinates to avoid conflict with x-coordinates
            uf.disjoint(x, y + 10001);
        }
        
        return n - uf.getComponentCount();
    }
};