class Solution:
    def largestPalindromic(self, num: str) -> str:
        cnt = [0] * 10
        for c in num:
            cnt[int(c)] += 1
        
        lp, rp = "", ""
        
        for _ in range(len(num)):
            for i in range(9, -1, -1):
                if cnt[i] > 1 and (i > 0 or lp != ""):
                    lp += str(i)
                    rp += str(i)
                    cnt[i] -= 2
                    break
        
        for i in range(9, -1, -1):
            if cnt[i]:
                lp += str(i)
                break
        
        return lp + rp[::-1]