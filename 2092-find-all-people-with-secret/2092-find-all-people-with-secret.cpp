class Solution {
private:
    void dfs(int person, int time, auto& earliest, auto& graph){
        for (auto [t, nextPerson] : graph[person]){
            if (t >= time && earliest[nextPerson] > t){
                earliest[nextPerson] = t;
                dfs(nextPerson, t, earliest, graph);
            }
        }
    }       

public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // For every person, we store the meeting time and label of the person met.
        unordered_map<int, vector<pair<int, int>>> graph;
        
        for(vector<int>& meeting:meetings){
            int x = meeting[0], y = meeting[1], t = meeting[2];
            graph[x].push_back({t, y});
            graph[y].push_back({t, x});
        }
        
        // Earliest time at which a person learnt the secret
        // as per current state of knowledge. If due to some new information,
        // the earliest time of knowing the secret changes, we'll update it
        // and again process all the people whom he/she meets after the time
        // at which he/she learned the secret.
        vector<int> earliest(n, INT_MAX);
        earliest[0] = 0, earliest[firstPerson] = 0;
        
        dfs(0, 0, earliest, graph);
        dfs(firstPerson, 0, earliest, graph);
        
        // Since we visited only those people who know the secret
        // we need to return indices of all visited people.
        vector<int> ans;
        for (int i = 0; i < n; ++i)
            if (earliest[i] != INT_MAX) ans.push_back(i);
        return ans;
    }
};