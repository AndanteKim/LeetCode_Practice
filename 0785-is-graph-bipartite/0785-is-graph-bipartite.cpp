class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int node = 0; node < n; ++node){
            if (color[node] == -1){
                stack<int> stack;
                stack.push(node);
                color[node] = 0;
                while (!stack.empty()){
                    int curr = stack.top();
                    stack.pop();
                    for (int neighbor : graph[curr]){
                        if (color[neighbor] == -1){
                            stack.push(neighbor);
                            color[neighbor] = color[curr] ^ 1;
                        }
                        else if (color[neighbor] == color[curr]) return false;
                    }
                }
            }
        }
        return true;
    }
};