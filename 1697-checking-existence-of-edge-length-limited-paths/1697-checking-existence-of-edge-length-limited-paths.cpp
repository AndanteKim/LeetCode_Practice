class UnionFind{
public:
    vector<int> parents, ranks;

    UnionFind(int size){
        parents.resize(size);
        iota(parents.begin(), parents.end(), 0);
        ranks.resize(size, 0);
    }
    
    int find(int x){
        if (parents[x] != x) parents[x] = find(parents[x]);
        return parents[x];
    }
    
    void unionSet(int x, int y){
        int xset = find(x), yset = find(y);
        if (xset == yset) return;
        if (ranks[xset] > ranks[yset]) parents[yset] = xset;
        else if (ranks[xset] < ranks[yset]) parents[xset] = yset;
        else{
            parents[xset] = yset;
            ++ranks[xset];
        }
    }
    
    bool areConnected(int x, int y) {
        return find(x) == find(y);
    }
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        UnionFind uf = UnionFind(n);
        int queriesCount = queries.size();
        vector<bool> ans(queriesCount, false);
        vector<vector<int>> queriesWithIndex(queriesCount, vector<int>());
        for (int i = 0; i < queriesCount; ++i){
            queriesWithIndex[i] = queries[i];
            queriesWithIndex[i].push_back(i);
        }
        sort(edgeList.begin(), edgeList.end(), [](vector<int>& a, vector<int>& b){return a[2] < b[2];});
        sort(queriesWithIndex.begin(), queriesWithIndex.end(), [](vector<int>& a, vector<int>& b) {return a[2] < b[2];});
        int edgesIndex = 0;
        
        for (vector<int>& queryWithIndex : queriesWithIndex){
            int p = queryWithIndex[0], q = queryWithIndex[1], limit = queryWithIndex[2], queryOriginalIndex = queryWithIndex[3];
            while (edgesIndex < edgeList.size() && edgeList[edgesIndex][2] < limit){
                int node1 = edgeList[edgesIndex][0], node2 = edgeList[edgesIndex][1];
                uf.unionSet(node1, node2);
                ++edgesIndex;
            }
            ans[queryOriginalIndex] = uf.areConnected(p, q);
        }
        
        return ans;
    }
};