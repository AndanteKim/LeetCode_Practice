#define ll long long
class UnionFind {
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
    
    void UnionSet(int x, int y){
        int xset = find(x), yset = find(y);
        if (xset == yset) return;
        else if (rank[xset] > rank[yset]) parent[xset] = yset;
        else if (rank[xset] < rank[yset]) parent[xset] = yset;
        else{
            parent[yset] = xset;
            ++rank[xset];
        }
    }
};

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        UnionFind dsu = UnionFind(n);
        for (vector<int>& edge : edges){
            dsu.UnionSet(edge[0], edge[1]);
        }
        
        unordered_map<int, int> sizeOfComponent;
        ll numberOfPairs = 0, remainingNodes = n;
        for (int node = 0; node < n; ++node) ++sizeOfComponent[dsu.find(node)];
        
        for (int node = 0; node < n; ++node){
            int componentSize = sizeOfComponent[node];
            numberOfPairs += componentSize * (remainingNodes - componentSize);
            remainingNodes -= componentSize;
        }
        return numberOfPairs;
    }
};