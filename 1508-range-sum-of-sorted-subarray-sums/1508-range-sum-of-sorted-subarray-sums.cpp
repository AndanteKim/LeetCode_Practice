typedef long long ll;

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<ll> sumSubarr(n * (n + 1) >> 1);
        int k = 0, rem = 1e9 + 7;
        
        for (int i = 0; i < n; ++i){
            ll partial = 0;
            for (int j = i; j < n; ++j){
                partial = (partial + nums[j]) % rem;
                sumSubarr[k++] = partial;
            }
        }
        sort(sumSubarr.begin(), sumSubarr.end());
        
        return accumulate(sumSubarr.begin() + left - 1, sumSubarr.begin() + right, 0LL) % rem;
    }
};