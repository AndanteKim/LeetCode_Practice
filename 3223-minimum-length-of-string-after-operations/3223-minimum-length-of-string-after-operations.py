class Solution:
    def minimumLength(self, s: str) -> int:
        freq = Counter(s)

        for c, val in freq.items():
            if val % 2 == 0:
                freq[c] = 2
            else:
                freq[c] = 1
        
        ans = 0
        for c, val in freq.items():
            ans += val
        
        return ans