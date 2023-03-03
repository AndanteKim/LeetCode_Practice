#define ll long long

class Solution {
public:
    const int RADIX_1 = 26, MOD_1 = 1000000033;
    const int RADIX_2 = 27, MOD_2 = 2147483647;
    
    pair<ll, ll> hashPair(string string, int m){
        ll hash1 = 0, hash2 = 0;
        ll factor1 = 1, factor2 = 1;
        
        for (int i = m - 1; i >= 0; --i){
            hash1 += ((int) (string[i] - 'a') * (factor1)) % MOD_1;
            factor1 = (factor1 * RADIX_1) % MOD_1;
            hash2 += ((int) (string[i] - 'a') * (factor2)) % MOD_2;
            factor2 = (factor2 * RADIX_2) % MOD_2;
        }
        
        return make_pair(hash1 % MOD_1, hash2 % MOD_2);
    }
    
    int strStr(string haystack, string needle) {
        int m = needle.size(), n = haystack.size();
        
        if (n < m) return -1;
        
        ll MAX_WEIGHT_1 = 1, MAX_WEIGHT_2 = 1;
        for (int i = 0; i < m; ++i){
            MAX_WEIGHT_1 = (MAX_WEIGHT_1 * RADIX_1) % MOD_1;
            MAX_WEIGHT_2 = (MAX_WEIGHT_2 * RADIX_2) % MOD_2;
        }
        
        pair<ll, ll> hashNeedle = hashPair(needle, m);
        pair<ll, ll> hashHay = {0, 0};
        
        for (int windowStart = 0; windowStart <= n - m; ++windowStart){
            if (windowStart == 0) hashHay = hashPair(haystack, m);
            else{
                hashHay.first = ((hashHay.first * RADIX_1) % MOD_1
                        - ((int) (haystack[windowStart - 1] - 'a') * MAX_WEIGHT_1) % MOD_1
                        + (int) (haystack[windowStart + m - 1] - 'a') + MOD_1) % MOD_1;
                hashHay.second = ((hashHay.second * RADIX_2) % MOD_2
                                 - ((int) (haystack[windowStart - 1] - 'a') * MAX_WEIGHT_2) % MOD_2
                                 + (int) (haystack[windowStart + m - 1] - 'a') + MOD_2) % MOD_2;
            }
            
            if (hashNeedle.first == hashHay.first && hashNeedle.second == hashHay.second) return windowStart;
        }
        
        return -1;
    }
};