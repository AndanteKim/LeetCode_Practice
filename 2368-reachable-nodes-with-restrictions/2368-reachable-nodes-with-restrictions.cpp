class UnionFind{
private:
    vector<int> parent, rank;
    
public:
    UnionFind(int size) : parent(size), rank(size, 1){
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x){
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void UnionSet(int x, int y){
        int xset = find(x), yset = find(y);
        if (xset == yset) return;
        else{
            if (rank[xset] > rank[yset]) swap(xset, yset);
            rank[yset] += rank[xset];
            parent[xset] = yset;
        }
    }
    
    int getSize(int x){
        return rank[find(x)];
    }
};

class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        UnionFind uf(n);
        unordered_set<int> rest_set(restricted.begin(), restricted.end());
        
        for (const vector<int>& edge: edges){
            if (rest_set.find(edge[0]) == rest_set.end() && rest_set.find(edge[1]) == \
                rest_set.end())
                uf.UnionSet(edge[0], edge[1]);
        }
        
        return uf.getSize(0);
    }
};