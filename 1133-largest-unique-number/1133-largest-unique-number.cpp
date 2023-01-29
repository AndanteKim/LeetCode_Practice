class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        unordered_map<int, int> lookup;
        for (const int num: nums) ++lookup[num];
        vector<int> ans_candidates;
        for (const auto&[key, value] : lookup){
            if (value == 1) ans_candidates.push_back(key);
        }
        
        return (ans_candidates.empty())? -1 : *max_element(ans_candidates.begin(), ans_candidates.end());
    }
};