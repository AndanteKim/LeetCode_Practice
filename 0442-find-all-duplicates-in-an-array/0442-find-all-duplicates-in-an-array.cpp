typedef long long ll;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i){
            int index = nums[i] & 0x7fffffff;
            if (nums[index - 1] < 0)
                ans.push_back(index);
            else
                nums[index - 1] |= 0x80000000;
        }
        
        return ans;
    }
};