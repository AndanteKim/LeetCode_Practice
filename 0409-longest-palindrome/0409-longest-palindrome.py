class Solution:
    def longestPalindrome(self, s: str) -> int:
        counts = defaultdict(int)
        for c in s:
            counts[c] += 1
        ans = 0
        
        for key, val in counts.items():
            ans += val // 2 * 2
            if ans % 2 == 0 and val % 2 == 1:
                ans += 1
            
        return ans