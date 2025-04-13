typedef long long ll;

class Solution {
private:
    static constexpr int mod = 1'000'000'007;
    ll quickMul(int x, ll y){
        ll ans = 1, mul = x;

        while (y > 0){
            if (y % 2){
                ans = ans * mul % mod;
            }
            mul = mul * mul % mod;
            y >>= 1;
        }

        return ans;
    }

public:
    int countGoodNumbers(long long n) {
        return quickMul(5, (n + 1) >> 1) * quickMul(4, n >> 1) % mod;
    }
};