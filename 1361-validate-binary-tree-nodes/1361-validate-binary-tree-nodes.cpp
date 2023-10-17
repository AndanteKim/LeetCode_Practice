class UnionFind{
public:
    int components;
    vector<int> parents;
    UnionFind(int n){
        components = n;
        parents.resize(n);
        iota(parents.begin(), parents.end(), 0);
    }
    
    int find(int node){
        if (parents[node] != node)
            parents[node] = find(parents[node]);
        return parents[node];
    }
    
    bool join(int parent, int child){
        int grandParent = find(parent), childParent = find(child);
        
        if (childParent != child || grandParent == childParent)
            return false;
        --components;
        parents[childParent] = grandParent;
        return true;
    }
};


class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        UnionFind *uf = new UnionFind(n);
        
        for (int node = 0; node < n; ++node){
            int children [] = {leftChild[node], rightChild[node]};
            for (int child : children){
                if (child == -1)
                    continue;
                if (!uf -> join(node, child))
                    return false;
            }
        }
        
        return uf -> components == 1;
    }
};