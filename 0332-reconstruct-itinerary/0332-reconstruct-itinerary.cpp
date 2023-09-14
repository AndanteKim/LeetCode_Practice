class Solution {
private:
    void dfs(string& origin, vector<string>& answer, unordered_map<string, vector<string>>& graph){
        
        while (!graph[origin].empty()){
            string nextDst = graph[origin].back();
            graph[origin].pop_back();
            dfs(nextDst, answer, graph);
        }
        
        answer.push_back(origin);
    }
    
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> graph;
        for (vector<string>& ticket : tickets){
            string origin = ticket[0], dst = ticket[1];
            graph[origin].push_back(dst);
        }
        
        for (auto& [origin, itinerary] : graph){
            sort(itinerary.begin(), itinerary.end(), greater<string>());
        }
        
        vector<string> answer;
        string start = "JFK";
        dfs(start, answer, graph);
        reverse(answer.begin(), answer.end());
        return answer;
    }
};