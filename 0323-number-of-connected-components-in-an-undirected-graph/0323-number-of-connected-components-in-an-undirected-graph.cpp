class UnionFind{
private:
    vector<int> parent, rank;
public:
    UnionFind(int size){
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i < size; ++i) parent[i] = i;
    }
    
    int find(int x){
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    int UnionSet(int x, int y){
        int xset = find(x), yset = find(y);
        if (xset == yset)
            return 0;
        else{
            if (rank[xset] > rank[yset]){
                rank[xset] += rank[yset];
                parent[yset] = xset;
            }
            else{
                rank[yset] += rank[xset];
                parent[xset] = yset;
            }
            
            return 1;
        }
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int components = n;
        UnionFind uf(n);
        
        for (const vector<int>& edge : edges){
            components -= uf.UnionSet(edge[0], edge[1]);
        }
        
        return components;
    }
};