class UnionFind{
private:
    vector<int> rank, root;
    
public:
    UnionFind(int n){
        root.resize(n);
        iota(root.begin(), root.end(), 0);
        rank.resize(n, 0);
    }
    
    int find(int x){
        if (root[x] != x)
            root[x] = find(root[x]);
        return root[x];
    }
    
    bool disjoint(int a, int b){
        int groupA = find(a), groupB = find(b);
        
        // Already united
        if (groupA == groupB)
            return false;
        
        // Merge the lower-rank group into the higher-rank group.
        if (rank[groupA] > rank[groupB])
            root[groupB] = groupA;
        else if (rank[groupA] < rank[groupB])
            root[groupA] = groupB;
        else{
            root[groupB] = groupA;
            ++rank[groupA];
        }
        
        return true;
    }
    
};



class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        // First, we need to sort the events in chronological order.
        sort(logs.begin(), logs.end());
        
        UnionFind uf = UnionFind(n);
        // Initially, we treat each individual as a separate group.
        int groupCnt = n;
        
        // We merge the groups along the way.
        for (vector<int>& log : logs){
            int timestamp = log[0], a = log[1], b = log[2];
            if (uf.disjoint(a, b))
                --groupCnt;
            
            // The moment when all individuals are connected to each other.
            if (groupCnt == 1)
                return timestamp;
        }
        
        // There are still more than one groups left,
        // i.e not everyone is connected.
        return -1;
    }
};