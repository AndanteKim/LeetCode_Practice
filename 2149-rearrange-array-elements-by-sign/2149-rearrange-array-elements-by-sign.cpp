class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans, pos, neg;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i){
            if (nums[i] > 0)
                pos.push_back(nums[i]);
            else
                neg.push_back(nums[i]);
        }
        
        int idx = 0;
        
        while (idx < max(pos.size(), neg.size())){
            if (idx < pos.size())
                ans.push_back(pos[idx]);
            
            if (idx < neg.size())
                ans.push_back(neg[idx]);
            
            ++idx;
        }
        
        return ans;
    }
};