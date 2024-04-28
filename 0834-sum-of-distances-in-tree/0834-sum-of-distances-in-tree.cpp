class Solution {
private:
    vector<int> count, ans;
    int n;
    void dfs(unordered_map<int, unordered_set<int>>& graph, int node = 0, int parent = -1){
        
        for (int child : graph[node]){
            if (child != parent){
                dfs(graph, child, node);
                count[node] += count[child];
                ans[node] += ans[child] + count[child];
            }
        }
    }
    
    void dfs2(unordered_map<int, unordered_set<int>>& graph, int node = 0, int parent = -1){
        for (int child : graph[node]){
            if (child != parent){
                ans[child] = ans[node] - count[child] + n - count[child];
                dfs2(graph, child, node);
            }
        }
    }
    
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        this -> n = n;
        unordered_map<int, unordered_set<int>> graph;
        
        for (vector<int>& edge: edges){
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        
        count.resize(n, 1);
        ans.resize(n, 0);
        dfs(graph);
        dfs2(graph);
        
        return ans;
    }
};