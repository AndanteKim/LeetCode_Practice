class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        letters, ans = set(s), 0
        
        for letter in letters:
            i, j = s.index(letter), s.rindex(letter)

            between = set()
            for k in range(i + 1, j):
                between.add(s[k])
            
            ans += len(between)

        return ans