class Solution:
    def minNumberOperations(self, target: List[int]) -> int:
        ans, n = target[0], len(target)

        for i in range(1, n):
            ans += max(target[i] - target[i - 1], 0)

        return ans