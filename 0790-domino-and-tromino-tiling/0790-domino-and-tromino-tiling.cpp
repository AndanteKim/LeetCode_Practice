typedef long long ll;

class Solution {
private:
    int mod = 1'000'000'007;
public:
    int numTilings(int n) {
        // Base case
        if (n <= 2) return n;
        
        // f[k]: the number of ways to "fully cover a board" of width k
        // p[k]: the number of ways to "partially cover a board" of width k
        vector<ll> f(n + 1, 0), p(n + 1, 0);

        // Initialize f and p with results for the base case scenarios
        f[1] = 1; p[2] = 1; f[2] = 2;

        for (int i = 3; i <= n; ++i){
            f[i] = (f[i - 1] + f[i - 2] + 2 * p[i - 1]) % mod;
            p[i] = (f[i - 2] + p[i - 1]) % mod;
        }

        return static_cast<int>(f[n]);
    }
};