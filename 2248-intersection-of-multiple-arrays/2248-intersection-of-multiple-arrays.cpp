class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int, int> counts;
        for (const vector<int> &arr: nums){
            for (const int x: arr) ++counts[x];
        }
        int n = nums.size();
        vector<int> ans;
        for (const auto key: counts) if (counts[key.first] == n) ans.push_back(key.first);
        sort(ans.begin(), ans.end());
        return ans;
    }
};