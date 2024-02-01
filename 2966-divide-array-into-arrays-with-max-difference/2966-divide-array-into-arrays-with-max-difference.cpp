class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        vector<int> curr;
        
        for (int num:nums){
            if (curr.size() == 3){
                if (abs(curr[0] - curr.back()) > k)
                    return {};
                ans.push_back(curr);
                curr.clear();
            }
            
            if (curr.empty() || abs(num - curr.back()) <= k)
                curr.push_back(num);
            else
                return {};
            
        }
        
        if (curr.size() == 3 && abs(curr[0] - curr.back()) <= k)
            ans.push_back(curr);
        else
            return {};
        return ans;
    }
};