class Solution {
public:
    int numTilings(int n) {
        int mod = 1'000'000'007;
        if (n <= 2) return n;
        long fPrev = 1L, fCurr = 2L, pCurr = 1L;
        for (int k = 3; k <= n; ++k){
            int tmp = fCurr;
            fCurr = (fPrev + fCurr + 2 * pCurr) % mod;
            pCurr = (pCurr + fPrev) % mod;
            fPrev = tmp;
        }
        
        return fCurr;
    }
};