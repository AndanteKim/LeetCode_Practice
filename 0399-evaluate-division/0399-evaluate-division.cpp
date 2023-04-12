class Solution {
    unordered_map<string, unordered_map<string, double>> graph;
    double AnswerQuery(string& start, string& end){
        if (graph.find(start) == graph.end()) return -1.0;
        stack<pair<string, double>> stack;
        stack.push({start, 1});
        unordered_set<string> seen;
        
        while (!stack.empty()){
            auto [node, ratio] = stack.top();
            stack.pop();
            if (node == end) return ratio;
            
            for (auto& neighbor_graph : graph[node]){
                string neighbor = neighbor_graph.first;
                if (seen.find(neighbor) == seen.end()){
                    seen.insert(neighbor);
                    stack.push({neighbor, ratio * graph[node][neighbor]});
                }
            }
        }
        
        return -1.0;
    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); ++i){
            string numerator = equations[i][0], denominator = equations[i][1];
            double val = values[i];
            graph[numerator][denominator] = val;
            graph[denominator][numerator] = 1 / val;
        }
        vector<double> ans;
        for (auto& query : queries){
            ans.push_back(AnswerQuery(query[0], query[1]));
        }
        
        return ans;
    }
};