class UnionFind{
private:
    vector<int> parent, rank;

public:
    UnionFind(int size){
        parent.resize(size);
        iota(parent.begin(), parent.end(), 0);
        rank.resize(size, 0);
    }
    
    int find(int x){
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void unionSet(int x, int y){
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
    bool isSimilar(string& a, string& b){
        int diff = 0;
        for (int i = 0; i < a.size(); ++i){
            if (a[i] != b[i]) ++diff;
        }
        
        return diff == 0 || diff == 2;
    }
    
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        UnionFind dsu = UnionFind(n);
        int ans = n;
        for (int i = 0; i < n; ++i){
            for (int j = i + 1; j < n; ++j){
                if (isSimilar(strs[i], strs[j]) && dsu.find(i) != dsu.find(j)){
                    --ans;
                    dsu.unionSet(i, j);
                }
            }
        }
        
        return ans;
    }
};