class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // For every person, store the time and label of the person met
        vector<vector<pair<int, int>>> graph(n);
        
        for (vector<int>& meeting:meetings){
            graph[meeting[0]].push_back({meeting[1], meeting[2]});
            graph[meeting[1]].push_back({meeting[0], meeting[2]});
        }
        
        // Earliest time at which a person learned the secret
        // as per current state of knowledge. If due to some new information,
        // the earliest time of knowing the secret changes, we'll update it.
        // and again process all the people whom he/she meets after the time
        // at which he/she learned the secret
        vector<int> earliest(n, INT_MAX);
        earliest[0] = 0;
        earliest[firstPerson] = 0;
        
        // Queue for BFS. It will store (person, time of knowing the secret)
        queue<pair<int, int>> q;
        q.push({0, 0});
        q.push({firstPerson, 0});
        
        // Do BFS
        while(!q.empty()){
            auto [person, time] = q.front();
            q.pop();
            
            for (auto& [nextPerson, t]:graph[person]){
                if (t >= time && earliest[nextPerson] > t){
                    earliest[nextPerson] = t;
                    q.push({nextPerson, t});
                }
            }
        }
        
        // Since we visited only those people who know the secret, 
        // we need to return indices of all visited people.
        vector<int> ans;
        for (int i = 0; i < n; ++i)
            if (earliest[i] != INT_MAX)
                ans.push_back(i);
        
        return ans;
    }
};