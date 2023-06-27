class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        for (int num : nums){
            int idx = lower_bound(sub.begin(), sub.end(), num) - sub.begin();
            if (idx == sub.size()) sub.push_back(num);
            else sub[idx] = num;
        }
        
        return sub.size();
    }
};