class UnionFind{
    vector<int> parent, rank;
    
public:
    UnionFind(int size){
        parent.resize(size);
        rank.resize(size, 0);
        for(int i = 0; i < size; ++i) parent[i] = i;
    }
    
    int find(int x){
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void union_set(int x, int y){
        int xset = find(x), yset = find(y);
        
        if (rank[xset] < rank[yset]) parent[xset] = yset;
        else if (rank[xset] > rank[yset]) parent[yset] = xset;
        else{
            parent[yset] = xset;
            ++rank[xset];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;
        int connected = n;
        UnionFind dsu = UnionFind(n);
        
        for (const vector<int>& connection : connections){
            if (dsu.find(connection[0]) != dsu.find(connection[1])){
                --connected;
                dsu.union_set(connection[0], connection[1]);
            }
        }
        
        return connected - 1;
    }
};