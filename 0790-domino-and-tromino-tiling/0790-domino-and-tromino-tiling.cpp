typedef long l;
class Solution {
private:
    int MOD = 1'000'000'007;
    unordered_map<int, l> f_cache, p_cache;
    l p(int k){
        if (p_cache.find(k) != p_cache.end())
            return p_cache[k];
        l val;
        if (k == 2)
            val = 1L;
        else
            val = (p(k - 1) + f(k - 2)) % MOD;
        return p_cache[k] = val;
    }
    
    l f(int k){
        if (f_cache.find(k) != f_cache.end())
            return f_cache[k];
        l val;
        if (k <= 2)
            val = k;
        else
            val = (f(k - 1) + f(k - 2) + 2 * p(k - 1)) % MOD;
        return f_cache[k] = val;
    }
    
public:
    int numTilings(int n) {
        return static_cast<int>(f(n));
    }
};