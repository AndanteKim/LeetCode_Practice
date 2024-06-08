class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        ans, counts = 0, Counter()
        
        for c in s:
            counts[c] += 1
            
        for c in counts:
            ans += (counts[c] * (counts[c] + 1) >> 1)
            
        return ans