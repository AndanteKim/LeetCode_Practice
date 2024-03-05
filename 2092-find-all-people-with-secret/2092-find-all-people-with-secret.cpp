class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // Sort meetings in increasing order of time
        sort(meetings.begin(), meetings.end(), [](auto& a, auto& b){
            return a[2] < b[2];
        });
        
        // Group Meetings in increasing order of time
        map<int, vector<pair<int, int>>> sameTimeMeetings;
        for (auto& meeting : meetings){
            int x = meeting[0], y = meeting[1], t = meeting[2];
            sameTimeMeetings[t].emplace_back(x, y);
        }
        
        // Boolean Array to mark if a person knows the secret or not
        vector<bool> knowsSecret(n);
        knowsSecret[0] = true, knowsSecret[firstPerson] = true;
        
        // Process in increasing order of time
        for (auto& [t, meetings] : sameTimeMeetings){
            // For each person, save all the people whom he/she meets at time t
            unordered_map<int, vector<int>> meet;
            for (auto& [x, y] : meetings){
                meet[x].push_back(y);
                meet[y].push_back(x);
            }
            
            // Start traversal from those who already know the secret at time t
            // Set to avoid redundancy
            unordered_set<int> start;
            for (auto& [x, y] : meetings){
                if (knowsSecret[x]) start.insert(x);
                if (knowsSecret[y]) start.insert(y);
            }
            
            // Do BFS
            queue<int> q;
            for (auto& person : start) q.push(person);
            
            while (!q.empty()){
                int person = q.front();
                q.pop();
                
                for (auto& nextPerson : meet[person]){
                    if (!knowsSecret[nextPerson]){
                        knowsSecret[nextPerson] = true;
                        q.push(nextPerson);
                    }
                }
            }
        }
        
        // List of people who know the secret
        vector<int> ans;
        for (int i = 0; i < n; ++i) if (knowsSecret[i]) ans.push_back(i);
        
        return ans;
    }
};