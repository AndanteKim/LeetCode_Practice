class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> frequencies;
        for (string& word : words) ++frequencies[word];
        vector<pair<int, string>> candidates;
        priority_queue<pair<int, string>> pq;
        
        for(auto&[key, val] : frequencies){
            pq.push({-val, key});
            if (pq.size() > k) pq.pop();
        }
        
        while(!pq.empty()){
            candidates.push_back(pq.top());
            pq.pop();
        }
        sort(candidates.begin(), candidates.end());
        vector<string> ans;
        for (auto&[val, key] : candidates) ans.push_back(key);
        return ans;
    }
};