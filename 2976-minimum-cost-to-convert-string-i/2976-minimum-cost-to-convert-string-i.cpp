class Solution {
private:
    void dijkstra(char origin, unordered_map<char, vector<pair<char, int>>>& adj, vector<int>& distances){
        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<>> pq;
        pq.push({0, origin});
        
        while (!pq.empty()){
            auto [currCost, currChar] = pq.top(); pq.pop();
            
            // If the current cost is larger than the saved distance, then ignore it.
            if (currCost > distances[currChar - 97])
                continue;
            
            for (auto& [neighbor, cost] : adj[currChar]){
                if (currCost + cost < distances[neighbor - 97]){
                    distances[neighbor - 97] = currCost + cost;
                    pq.push({currCost + cost, neighbor});
                }
            }
        }
    }
    
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_map<char, vector<pair<char, int>>> adj;
        vector matrix(26, vector<int>(26, INT_MAX));
        
        // Initialize adj and matrix
        for (int i = 0; i < 26; ++i)
            matrix[i][i] = 0;
        
        for (int i = 0; i < original.size(); ++i)
            adj[original[i]].push_back({changed[i], cost[i]});
        
        // Use dijkstra algorithm to set up matrix completely
        for (int i = 0; i < 26; ++i)
            dijkstra((char)(i + 97), adj, matrix[i]);
        
        long long ans = 0;
        
        // Change the source word to target word.
        for (int i = 0; i < source.size(); ++i){
            // If there no exists from source[i] to target[i], then return -1
            if (matrix[source[i] - 97][target[i] - 97] == INT_MAX)
                return -1;
            ans += matrix[source[i] - 97][target[i] - 97];
        }
            
        return ans;
    }
};