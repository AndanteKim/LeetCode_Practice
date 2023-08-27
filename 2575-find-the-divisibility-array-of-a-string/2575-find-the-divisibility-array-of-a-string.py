class Solution:
    def divisibilityArray(self, word: str, m: int) -> List[int]:
        n = len(word)
        ans, num = [0] * n, 0
        for i in range(n):
            num += int(word[i])
            num %= m
            if num == 0:
                ans[i] = 1
            num *= 10
        return ans