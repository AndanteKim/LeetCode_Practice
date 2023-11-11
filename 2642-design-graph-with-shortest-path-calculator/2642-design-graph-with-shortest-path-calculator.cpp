class Graph {
private:
    vector<vector<int>> adjMatrix;
public:
    Graph(int n, vector<vector<int>>& edges) {
        adjMatrix.resize(n, vector<int>(n, 1e9));
        
        for (vector<int>& edge : edges)
            adjMatrix[edge[0]][edge[1]] = edge[2];
        
        for (int i = 0; i < n; ++i) adjMatrix[i][i] = 0;
        
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                for (int k = 0; k < n; ++k)
                    adjMatrix[j][k] = min(adjMatrix[j][k], adjMatrix[j][i] + adjMatrix[i][k]);
            }
        }
    }
    
    void addEdge(vector<int> edge) {
        int n = adjMatrix.size();
        
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][edge[0]] + adjMatrix[edge[1]][j] + edge[2]);
            }
        }
    }
    
    int shortestPath(int node1, int node2) {
        return adjMatrix[node1][node2] == 1e9? -1 : adjMatrix[node1][node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */