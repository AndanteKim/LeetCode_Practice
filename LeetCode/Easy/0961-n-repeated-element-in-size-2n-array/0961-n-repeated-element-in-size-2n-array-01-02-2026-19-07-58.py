class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        double_n = len(nums)
        n, counts = double_n >> 1, Counter(nums)

        for val, cnt in counts.items():
            if cnt == n:
                return val

        return -1