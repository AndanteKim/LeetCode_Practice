class Solution:
    def firstUniqChar(self, s: str) -> int:
        chars, ans = defaultdict(list), -1
        
        for i in range(len(s)):
            chars[s[i]].append(i)
            
        for key, val in chars.items():
            if len(val) == 1:
                ans = val[0] if ans == -1 else min(ans, val[0])
            
        return ans
        