class Solution {
    void dfs(int node, int colored, vector<int>& color, vector<vector<int>>& graph){
        if (color[node] == -1){
            color[node] = colored;
            for (int neighbor : graph[node]) dfs(neighbor, colored, color, graph);
        }
    }
    
public:
    bool equationsPossible(vector<string>& equations) {
        vector graph(26, vector<int>());
        for (string& equation : equations){
            if (equation[1] == '='){
                int x = equation[0] - 'a';
                int y = equation[3] - 'a';
                graph[x].push_back(y);
                graph[y].push_back(x);
            }
        }
        vector<int> color(26, -1);
        for (int i = 0; i < 26; ++i){
            if (color[i] == -1) dfs(i, i, color, graph);
        }
        
        for (string& equation : equations){
            if (equation[1] == '!'){
                int x = equation[0] - 'a';
                int y = equation[3] - 'a';
                if (color[x] == color[y]) return false;
            }
        }
        
        return true;
    }
};