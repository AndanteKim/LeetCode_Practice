class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0) return 0;
        vector<double> prefix(1, 0);
        double log_k = log(k);
        int ans = 0, j;
        
        for (int x : nums) prefix.push_back(prefix.back()+log(x));
        
        for (int i = 0; i < prefix.size(); ++i){
            j = lower_bound(prefix.begin()+i+1, prefix.end(), prefix[i] + log_k - 1e-9) - prefix.begin();
            ans += j - i-1;
        }
        
        return ans;
    }
};