class Solution {
public:
    int countOrders(int n) {
        const int MOD = 1'000'000'007;
        long ans = 1;
        for (int i = 1; i <= n; ++i){
            ans *= i;
            ans *= (2 * i - 1);
            ans %= MOD;
        }
        
        return ans;
    }
};