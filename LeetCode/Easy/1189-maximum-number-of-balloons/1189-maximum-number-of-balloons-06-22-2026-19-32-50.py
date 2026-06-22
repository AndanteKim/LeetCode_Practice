class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        freq, ans = Counter(text), float('inf')

        for c in ('b', 'a', 'l', 'o', 'n'):
            if c == 'l' or c == 'o':
                ans = min(ans, freq[c] >> 1)
            else:
                ans = min(ans, freq[c])

        return 0 if ans == float('inf') else ans