class UnionFind{
private:
    vector<int> rank, group;

public:
    UnionFind(int size){
        rank.resize(size, 0);
        group.resize(size);
        iota(group.begin(), group.end(), 0);
    }
    
    int find(int node){
        if (group[node] != node) group[node] = find(group[node]);
        return group[node];
    }
    
    bool unite(int node1, int node2){
        int group1 = find(node1), group2 = find(node2);
        
        if (group1 == group2) return false;
        
        if (rank[group1] > rank[group2]) group[group2] = group1;
        else if (rank[group1] < rank[group2]) group[group1] = group2;
        else{
            group[group1] = group2;
            ++rank[group2];
        }
        
        return true;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<pair<int, pair<int, int>>> allEdges;
        int n = points.size();
        
        // store all edges of our complete graph
        for (int currNode = 0; currNode < n; ++currNode){
            for (int nextNode = currNode + 1; nextNode < n; ++nextNode){
                int weight = abs(points[currNode][0] - points[nextNode][0]) + abs(points[currNode][1] - points[nextNode][1]);
                allEdges.push_back({weight, {currNode, nextNode}});
            }
        }
        
        // sort all edges in increasing order
        sort(allEdges.begin(), allEdges.end());
        
        UnionFind *uf = new UnionFind(n);
        int mstCost = 0, edgesUsed = 0;
        for (int i = 0; i < allEdges.size() && edgesUsed < n - 1; ++i){
            int weight = allEdges[i].first, node1 = allEdges[i].second.first, node2 = allEdges[i].second.second;
            
            if (uf -> unite(node1, node2)){
                mstCost += weight;
                ++edgesUsed;
                
                if (edgesUsed == n - 1) break;
            }
        }
        
        return mstCost;
    }
};