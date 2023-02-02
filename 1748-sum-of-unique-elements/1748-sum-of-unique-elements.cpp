class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> dic;
        int ans = 0;
        
        for (int i = 0; i < nums.size(); ++i) ++dic[nums[i]];
        for (const auto& [key, value] : dic) if (value == 1) ans += key;
        
        return ans;
    }
};