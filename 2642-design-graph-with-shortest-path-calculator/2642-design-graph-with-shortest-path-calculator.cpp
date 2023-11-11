class Graph {
private:
    vector<vector<pair<int, int>>> graph;
public:
    Graph(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        for (vector<int>& edge : edges){
            int start = edge[0], end = edge[1], cost = edge[2];
            graph[start].push_back({end, cost});
        }
    }
    
    void addEdge(vector<int> edge) {
        int start = edge[0], end = edge[1], cost = edge[2];
        graph[start].push_back({end, cost});
    }
    
    int shortestPath(int node1, int node2) {
        int n = graph.size();
        vector<int> costForNode(n, INT_MAX);
        costForNode[node1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, node1});
        
        while (!minHeap.empty()){
            auto [currCost, currNode] = minHeap.top();
            minHeap.pop();
            
            if (currCost > costForNode[currNode])
                continue;
            
            if (currNode == node2)
                return currCost;
            
            for (auto& [neighbor, cost] : graph[currNode]){
                int newCost = currCost + cost;
                if (newCost < costForNode[neighbor]){
                    costForNode[neighbor] = newCost;
                    minHeap.push({newCost, neighbor});
                }
            }
        }
        
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */