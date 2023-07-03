class Solution:
    def buddyStrings(self, s: str, goal: str) -> bool:
        if goal == s:
            return len(set(s)) < len(s)
        
        n = len(s)
        l, r = 0, n - 1
        while l < n and s[l] == goal[l]:
            l += 1
        
        while r >= 0 and s[r] == goal[r]:
            r -= 1
        
        if l < r:
            s = list(s)
            s[l], s[r] = s[r], s[l]
        
        return "".join(s) == goal