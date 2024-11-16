class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n - k + 1, -1);
        
        for (int i = 0; i <= n - k; ++i){
            bool isPower = true;
            for (int j = i; j < i + k - 1 && isPower; ++j){
                if (nums[j] + 1 != nums[j + 1]){
                    isPower = false;
                    break;
                }
            }
            
            if (isPower)
                ans[i] = nums[i + k - 1];
        }
        
        return ans;
    }
};