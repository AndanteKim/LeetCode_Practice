class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> storePairs;
        
        for (int i = 0; i < nums.size(); ++i){
            // Convert current value to string
            string num = to_string(nums[i]), formed = "";
            
            for (int j = 0; j < num.size(); ++j)
                formed += to_string(mapping[num[j] - 48]);
            
            // Store the mapped value and push a pair consisting of mapped value
            // original value's index.
            storePairs.push_back({stoi(formed), i});
        }
        
        sort(storePairs.begin(), storePairs.end());
        
        // Sort the array in non-decreasing order by the first value (default).
        vector<int> ans;
        for (auto& [_, idx]: storePairs)
            ans.push_back(nums[idx]);
        return ans;
    }
};