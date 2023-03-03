class Solution {
    int hashValue(string string, int RADIX, int MOD, int m){
        int ans = 0;
        long long factor = 1;
        for (int i = m - 1; i >= 0; --i){
            ans += ((int) (string[i] - 'a') * factor) % MOD;
            factor = (factor * RADIX) % MOD;
        }
        return ans % MOD;
    }
public:
    int strStr(string haystack, string needle) {
        int m = needle.size(), n = haystack.size();
        if (n < m) return -1;
        
        int RADIX = 26, MOD = 1000000033;
        long long MAX_WEIGHT = 1;
        
        for (int i = 0; i < m; ++i) MAX_WEIGHT = (MAX_WEIGHT * RADIX) % MOD;
        
        long long hashNeedle = hashValue(needle, RADIX, MOD, m), hashHay = 0;
        
        for (int windowStart = 0; windowStart <= n - m; ++windowStart){
            if (windowStart == 0) hashHay = hashValue(haystack, RADIX, MOD, m);
            else{
                hashHay = ((hashHay * RADIX) % MOD - ((int) (haystack[windowStart - 1] - 'a') * MAX_WEIGHT) % MOD\
                          + (int) (haystack[windowStart + m - 1] - 'a') + MOD) % MOD;
            }
            
            if (hashNeedle == hashHay){
                for (int i = 0; i < m; ++i){
                    if (needle[i] != haystack[i + windowStart]) break;
                    if (i == m - 1) return windowStart;
                }
            }
        }
        
        return -1;
    }
};