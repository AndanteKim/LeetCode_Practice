class Solution {
private:
    double backtrackEvaluate(string currNode, string& targetNode, double accProduct, unordered_set<string>& visited, unordered_map<\
                             string, unordered_map<string, double>>& graph){
        visited.insert(currNode);
        double ret = -1.0;
        unordered_map<string, double> neighbors = graph[currNode];
        
        if (neighbors.find(targetNode) != neighbors.end())
            ret = accProduct * neighbors[targetNode];
        else{
            for (auto [neighbor, value] : neighbors){
                if (visited.find(neighbor) != visited.end()) continue;
                ret = backtrackEvaluate(neighbor, targetNode, accProduct * value, visited, graph);
                if (ret != -1.0) break;
            }
        }
        visited.erase(currNode);
        return ret;
    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        
        for (int i = 0; i < equations.size(); ++i){
            graph[equations[i][0]][equations[i][1]] = values[i];
            graph[equations[i][1]][equations[i][0]] = 1 / values[i];
        }
        
        vector<double> ans;
        double ret;
        for (vector<string>& query : queries){
            if (graph.find(query[0]) == graph.end() || graph.find(query[1]) == graph.end())
                ret = -1.0;
            else if (query[0] == query[1]) ret = 1.0;
            else{
                unordered_set<string> visited;
                ret = backtrackEvaluate(query[0], query[1], 1, visited, graph);
            }
            ans.push_back(ret);
        }
        
        return ans;
    }
};