class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans{{}};
        if (n == 0) return ans;
        
        for (int i = 0; i < n; ++i){
            int sz = ans.size();
            for (int j = 0; j < sz; ++j){
                vector<int> s(ans[j]);
                s.push_back(nums[i]);
                ans.push_back(s);
            }
        }
        
        return ans;
    }
};