class Solution:
    def maxDifference(self, s: str) -> int:
        count = Counter(s)
        odd, even = float('-inf'), float('inf')


        for _, freq in count.items():
            if freq % 2 == 0:
                even = min(even, freq)
            else:
                odd = max(odd, freq)

        return odd - even