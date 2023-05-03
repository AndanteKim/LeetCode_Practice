class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashTable;
        
        for (int num : nums) ++hashTable[num];
        
        vector<pair<int, int>> frequencies;
        for (auto &[num, freq] : hashTable) frequencies.push_back(make_pair(num, freq));
        sort(frequencies.begin(), frequencies.end(), [](pair<int, int>& n1, pair<int, int>& n2){return n1.second > n2.second;});
        vector<int> ans;
        for (int i = 0; i < k; ++i) ans.push_back(frequencies[i].first);
        return ans;
    }
};