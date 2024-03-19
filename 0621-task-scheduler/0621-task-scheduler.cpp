class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Build frequencies map
        unordered_map<char, int> freq;
        
        // Max heap to store frequencies
        for (char& c:tasks) ++freq[c];
        int ans = 0;
        
        priority_queue<int, vector<int>> pq;
        for (auto& [_, v]:freq) pq.push(v);
        
        // Process tasks until the pq is empty
        while (!pq.empty()){
            int taskCount = 0, cycle = n + 1;
            vector<int> store;
            
            // Execute tasks until the pq is empty
            while (cycle-- > 0 && !pq.empty()){
                int currFreq = pq.top();
                pq.pop();
                ++taskCount;
                
                if (currFreq > 1) store.push_back(--currFreq);
            }
            
            // restore updated frequencies to the heap
            for (int x:store) pq.push(x);
            
            // Add time for the completed cycle
            ans += (pq.empty())? taskCount : n + 1;
        }
        
        return ans;
    }
};