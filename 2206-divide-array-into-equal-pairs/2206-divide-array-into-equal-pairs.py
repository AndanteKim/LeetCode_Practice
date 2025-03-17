class Solution:
    def divideArray(self, nums: List[int]) -> bool:
        n = len(nums)
        counts, pairs = Counter(nums), n >> 1

        for val, freq in counts.items():
            if freq % 2:
                return False
            pairs -= (freq >> 1)

        return pairs == 0