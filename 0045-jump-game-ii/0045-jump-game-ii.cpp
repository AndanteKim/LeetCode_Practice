class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0, n = nums.size(), cur_far = 0, cur_end = 0;
        
        for (int i = 0; i < n - 1; ++i){
            cur_far = max(cur_far, i + nums[i]);
            
            if (i == cur_end){
                ++ans;
                cur_end = cur_far;
            }
        }
        
        return ans;
    }
};