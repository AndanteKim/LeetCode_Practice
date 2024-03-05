class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // For every person, store the time and label of the person met.
        unordered_map<int, vector<pair<int, int>>> graph;
        
        for (auto& meeting : meetings){
            int x = meeting[0], y = meeting[1], t = meeting[2];
            graph[x].push_back({t, y});
            graph[y].push_back({t, x});
        }
        
        // Priority Queue for BFS. It stores (time secret learned, person)
        // It pops the person with the minimum time of knowing the secret.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        pq.push({0, firstPerson});
        
        // Visited array to mark if a person is visited or not.
        // We'll mark a person as visited after it's dequeued
        // from the queue.
        vector<bool> visited(n);
        
        // Do BFS, but pop minimum.
        while(!pq.empty()){
            auto [t, person] = pq.top();
            pq.pop();
            
            if (visited[person])
                continue;
            visited[person] = true;
            for (auto& [time, nextPerson] : graph[person]){
                if (time >= t && !visited[nextPerson]){
                    pq.push({time, nextPerson});
                }
            }
        }
        
        // Since we visited only those people who know the secret
        // we need to return indices of all visited people
        vector<int> ans;
        for (int i = 0; i < n; ++i) if (visited[i]) ans.push_back(i);
        return ans;
    }
};