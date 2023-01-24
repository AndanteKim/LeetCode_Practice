class Solution:
    def check(self, pref: List[int], maxCost: int, mid: int) -> int:
        l, r = 0, mid
        flag = False
        while r < len(pref):
            total = pref[r] - pref[l]
            if total <= maxCost:
                flag = True
                break
            l += 1
            r += 1
        return flag
    
    
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        n = len(s)
        pref = [0] * (n+1)
        for i in range(1, n+1):
            pref[i] = pref[i-1] + abs(ord(s[i-1]) - ord(t[i-1]))
        l, h = 0, len(s) + 1
        ans = 0
        while (l <= h):
            mid = l + ((h-l) >> 1)
            if self.check(pref, maxCost, mid):
                ans = mid
                l = mid + 1
            else:
                h = mid - 1
        
        return ans
                