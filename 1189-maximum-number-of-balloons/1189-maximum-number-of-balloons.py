class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        bCnt, aCnt, lCnt, oCnt, nCnt = 0, 0, 0, 0, 0
        
        for c in text:
            if c == 'b':
                bCnt += 1
            elif c == 'a':
                aCnt += 1
            elif c == 'l':
                lCnt += 1
            elif c == 'o':
                oCnt += 1
            elif c == 'n':
                nCnt += 1
        
        lCnt //= 2
        oCnt //= 2
        
        return min([bCnt, aCnt, lCnt, oCnt, nCnt])