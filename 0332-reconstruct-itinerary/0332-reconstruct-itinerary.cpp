class Solution {
private:
    vector<string> ans;
    int flights;
    bool backtrack(string& origin, vector<string>& route, unordered_map<string, vector<bool>>& visited, unordered_map<string, vector<string>>& graph){
        if (route.size() == flights + 1){
            ans = route;
            return true;
        }
        
        for (int i = 0; i < graph[origin].size(); ++i){
            if (!visited[origin][i]){
                // mark the visited before the next recursion
                visited[origin][i] = true;
                route.push_back(graph[origin][i]);
                bool ret = backtrack(graph[origin][i], route, visited, graph);
                route.pop_back();
                visited[origin][i] = false;
                if (ret)
                    return true;
            }
        }
        
        return false;
    }
    
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        this -> flights = tickets.size();
        unordered_map<string, vector<string>> graph;
        for (vector<string>& ticket: tickets){
            string origin = ticket[0], dest = ticket[1];
            graph[origin].push_back(dest);
        }
        
        unordered_map<string, vector<bool>> visited;
        for (auto& [origin, itinerary] : graph){
            sort(itinerary.begin(), itinerary.end());
            visited[origin] = vector<bool>(itinerary.size());
        }
        
        vector<string> route{{"JFK"}};
        string start = "JFK";
        backtrack(start, route, visited, graph);
        return ans;
    }
};