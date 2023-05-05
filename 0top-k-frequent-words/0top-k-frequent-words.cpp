class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> frequencies;
        for (string& word : words) ++frequencies[word];
        
        vector<pair<int, string>> candidates;
        for (auto&[key, val] : frequencies) candidates.push_back(make_pair(-val, key));
        sort(candidates.begin(), candidates.end());
        
        vector<string> ans;
        for (int i = 0; i < k; ++i) ans.push_back(candidates[i].second);
        return ans;
    }
};