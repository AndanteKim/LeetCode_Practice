class UnionFind{
private:
    vector<int> parent, rank;
    int components;
public:
    UnionFind(int size){
        parent.resize(size + 1);
        iota(parent.begin(), parent.end(), 0);
        rank.resize(size + 1, 1);
        components = size;
    }
    
    int find(int x){
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    int UnionSet(int x, int y){
        int xset = find(x), yset = find(y);
        if (xset == yset) return 0;
        
        if (rank[xset] < rank[yset]) {
            rank[yset] += rank[xset];
            parent[xset] = yset;
        }
        else{
            rank[xset] += rank[yset];
            parent[yset] = xset;
        }
        --components;
        return 1;
    }
    
    bool isConnected(){
        return components == 1;
    }
};


class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind Alice = UnionFind(n), Bob = UnionFind(n);
        int edgesRequired = 0;
        for (vector<int>& edge : edges){
            if (edge[0] == 3) edgesRequired += (Alice.UnionSet(edge[1], edge[2]) |\
                                               Bob.UnionSet(edge[1], edge[2]));
        }
        
        for (vector<int>& edge: edges){
            if (edge[0] == 1) edgesRequired += Alice.UnionSet(edge[1], edge[2]);
            else if (edge[0] == 2) edgesRequired += Bob.UnionSet(edge[1], edge[2]);
        }
        
        if (Alice.isConnected() && Bob.isConnected())
            return edges.size() - edgesRequired;
        return -1;
    }
};