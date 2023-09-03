typedef long long ll;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        bool exist_0 = false;
        int n = nums.size();
        ll sum = 1;
        for (int i = 0; i < n; ++i){
            if (!nums[i]){
                if (exist_0) return vector<int>(n);
                exist_0 = true;
                continue;
            }
            sum *= nums[i];
        }
        
        if (exist_0){
            vector<int> ans(n, 0);
            for (int i = 0; i < n; ++i){
                if(!nums[i]) ans[i] = sum;
            }
            return ans;
        }
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) ans[i] = sum / nums[i];
        
        return ans;
    }
};