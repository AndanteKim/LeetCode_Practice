class Solution:
    def divisibilityArray(self, word: str, m: int) -> List[int]:
        n = len(word)
        ans, curr = [0] * n, 0
        
        for i in range(n):
            curr = ((curr * 10) + int(word[i])) % m
            if not curr:
                ans[i] = 1
        return ans