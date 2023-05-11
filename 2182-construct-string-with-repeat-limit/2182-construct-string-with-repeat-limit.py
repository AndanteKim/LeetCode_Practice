class Solution:
    def repeatLimitedString(self, s: str, repeatLimit: int) -> str:
        cnt = [0] * 26
        ans = ""
        for c in s:
            cnt[ord(c) - ord('a')] += 1
        
        while True:
            i, onlyOne = 25, False
            
            while 0 <= i <= 25:
                if len(ans) and i == ord(ans[-1]) - ord('a') and cnt[i]:
                    onlyOne = True
                    i -= 1
                    continue
                
                if cnt[i]:
                    break
                i -= 1
            
            if i == -1:
                break
            fill = 1 if onlyOne else min(cnt[i], repeatLimit)
            
            cnt[i] -= fill
            
            ans += fill * chr(97 + i)
            
        
        return ans
            
            