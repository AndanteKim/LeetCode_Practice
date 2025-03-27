class Solution:
    def minimumIndex(self, nums: List[int]) -> int:
        n = len(nums)
        first_map, second_map = defaultdict(int), defaultdict(int)

        for num in nums:
            second_map[num] += 1
        
        for i, num in enumerate(nums):
            second_map[num] -= 1
            first_map[num] += 1

            if first_map[num] * 2 > i + 1 and second_map[num] * 2 > n - i - 1:
                return i

        return -1