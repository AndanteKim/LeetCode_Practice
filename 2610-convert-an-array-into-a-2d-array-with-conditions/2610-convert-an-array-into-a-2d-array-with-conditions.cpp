class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> freq(nums.size() + 1);
        vector<vector<int>> ans;
        
        for (int n: nums){
            if (freq[n] >= ans.size())
                ans.push_back({});
            
            // Store the integer in the list corresponding to its current frequency
            ans[freq[n]].push_back(n);
            ++freq[n];
        }
        
        return ans;
    }
};