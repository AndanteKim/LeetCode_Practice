class Solution:
    def minCost(self, basket1: List[int], basket2: List[int]) -> int:
        freq, m = Counter(), float('inf')
        for b1 in basket1:
            freq[b1] += 1
            m = min(m, b1)

        for b2 in basket2:
            freq[b2] -= 1
            m = min(m, b2)

        merge = []
        for k, c in freq.items():
            if c % 2:
                return -1
            merge.extend([k] * (abs(c) >> 1))

        merge.sort()
        return sum(min(2 * m, x) for x in merge[: len(merge) >> 1])