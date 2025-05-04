class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        ans, seen = 0, dict()

        for a, b in dominoes:
            seen[(min(a, b), max(a, b))] = seen.get((min(a, b), max(a, b)), 0) + 1

        for (a, b), freq in seen.items():
            ans += freq * (freq - 1) >> 1

        return ans