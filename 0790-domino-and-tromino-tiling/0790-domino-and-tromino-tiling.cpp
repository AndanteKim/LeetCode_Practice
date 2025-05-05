typedef long long ll;

class Solution {
private:
    int mod = 1'000'000'007;
    ll p(int n, vector<ll>& fCache, vector<ll>& pCache){
        if (n == 2) return 1;

        if (pCache[n] != -1) return pCache[n];

        return pCache[n] = (p(n - 1, fCache, pCache) + f(n - 2, fCache, pCache)) % mod;
    }

    ll f(int n, vector<ll>& fCache, vector<ll>& pCache){
        if (n <= 2) return n;

        if (fCache[n] != -1) return fCache[n];

        return fCache[n] = (f(n - 1, fCache, pCache) + f(n - 2, fCache, pCache) + 2 * p(n - 1, fCache, pCache)) % mod;
    }

public:
    int numTilings(int n) {
        vector<ll> fCache(n + 1, -1), pCache(n + 1, -1);
        return static_cast<int>(f(n, fCache, pCache));
    }
};