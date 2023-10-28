class Solution {
public:
    int countVowelPermutation(int n) {
        long aCnt = 1, eCnt = 1, iCnt = 1, oCnt = 1, uCnt = 1, MOD = 1'000'000'007;
        
        for (int i = 1; i < n; ++i){
            long aNewCnt = (eCnt + iCnt + uCnt) % MOD;
            long eNewCnt = (aCnt + iCnt) % MOD;
            long iNewCnt = (eCnt + oCnt) % MOD;
            long oNewCnt = iCnt % MOD;
            long uNewCnt = (iCnt + oCnt) % MOD;
            aCnt = aNewCnt, eCnt = eNewCnt, iCnt = iNewCnt, oCnt = oNewCnt, uCnt = uNewCnt;
        }
        
        return static_cast<int>((aCnt + eCnt + iCnt + oCnt + uCnt) % MOD);
    }
};