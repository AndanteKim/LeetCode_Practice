class UnionFind{
    private:
    vector<int> parent, rank;
    public:
    UnionFind(int size){
        parent.resize(size);
        rank.resize(size, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x){
        if(parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void UnionSet(int x, int y){
        int xset = find(x), yset = find(y);
        if (parent[x] != parent[y]){
            if (rank[xset] > rank[yset]) swap(parent[xset], parent[yset]);
            parent[xset] = parent[yset];
            rank[yset] += rank[xset];
        }
    }
    
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        UnionFind uf(n);
        
        for (vector<int>& edge: edges){
            uf.UnionSet(edge[0], edge[1]);
        }
        
        return uf.find(source) == uf.find(destination);
    }
};