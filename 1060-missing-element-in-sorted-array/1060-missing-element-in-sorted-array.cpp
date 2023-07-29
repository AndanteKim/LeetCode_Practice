class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int ans = nums[0];
            
        for (int i = 0; i < nums.size() - 1 && k > 0; ++i){
            if (nums[i + 1] - nums[i] - 1 < k) {
                k -= (nums[i + 1] - nums[i] - 1);
                ans = nums[i + 1];
            }
            else{
                while (k > 0){
                    ++ans;
                    --k;
                }
            }
        }
        
        return ans + k;
    }
};