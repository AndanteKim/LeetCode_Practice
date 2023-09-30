class Solution {
private:
    double backtrack(string currNode, string& targetNode, double accProduct, unordered_set<string>& visited, unordered_map<string, unordered_map<string, double>>& graph){
        visited.insert(currNode);
        unordered_map<string, double> neighbors = graph[currNode];
        double res = -1.0;
        
        if (neighbors.find(targetNode) != neighbors.end())
            res = accProduct * neighbors[targetNode];
        else{
            for (auto& [neighbor, value] : neighbors){
                if (visited.find(neighbor) != visited.end())
                    continue;
                res = backtrack(neighbor, targetNode, accProduct * value, visited, graph);
                if (res != -1.0)
                    break;
            }
        }
        
        visited.erase(currNode);
        return res;
    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        vector<double> ans;
        
        // build the graph from the equations
        for (int i = 0; i < equations.size(); ++i){
            // add nodes and two edges into the graph
            graph[equations[i][0]][equations[i][1]] = values[i];
            graph[equations[i][1]][equations[i][0]] = 1.0 / values[i];
        }
        
        for (vector<string>& query : queries){
            string dividend = query[0], divisor = query[1];
            double res;
            
            // case 1: either doesn't exist 
            if (graph.find(dividend) == graph.end() || graph.find(divisor) == graph.end())
                res = -1.0;
            // case 2: destination is the same node
            else if (dividend == divisor)
                res = 1.0;
            else{
                unordered_set<string> visited;
                res = backtrack(dividend, divisor, 1.0, visited, graph);
            }
            ans.push_back(res);
        }
        
        return ans;
    }
};