typedef long long ll;

class Solution {
public:
    int numTilings(int n) {
        // Base case
        if (n <= 2) return n;

        int mod = 1'000'000'007;
        ll fPrevious = 1, fCurrent = 2, pCurrent = 1;

        for (int k = 3; k <= n; ++k){
            ll tmp = fCurrent;
            fCurrent = (fPrevious + fCurrent + 2 * pCurrent) % mod;
            pCurrent = (fPrevious + pCurrent) % mod;
            fPrevious = tmp;
        }

        return fCurrent;
    }
};