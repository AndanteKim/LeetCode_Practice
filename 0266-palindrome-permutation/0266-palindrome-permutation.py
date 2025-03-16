class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        if len(s) == 1:
            return True

        n, seen = len(s), defaultdict(int)

        for c in s:
            seen[c] += 1

        freq_odd = 0
        for c, val in seen.items():
            freq_odd += (val % 2)

        return freq_odd <= 1
