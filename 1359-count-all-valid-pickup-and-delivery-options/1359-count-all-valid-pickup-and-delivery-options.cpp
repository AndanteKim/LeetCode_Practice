class Solution {
public:
    int countOrders(int n) {
        const int MOD = 1'000'000'007;
        long ans = 1;
        for (int i = 1; i <= 2 * n; ++i){
            ans *= i;
            if (!(i % 2)) ans /= 2;
            ans %= MOD;
        }
        
        return ans;
    }
};