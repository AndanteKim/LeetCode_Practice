class Solution {
public:
    int minimumPushes(string word) {
        // Frequency map to store count of each letter
        unordered_map<char, int> freqMap;
        for (char& c : word) ++freqMap[c];
        
        // Priority queue to store frequencies in descending order
        priority_queue<int, vector<int>> pq;
        for (auto& [_, val] : freqMap)
            pq.push(val);
        
        int ans = 0, i = 0;
        
        // Calculate total number of presses
        while (!pq.empty()){
            ans += ((i++ / 8) + 1) * pq.top();
            pq.pop();
        }
        
        return ans;
    }
};