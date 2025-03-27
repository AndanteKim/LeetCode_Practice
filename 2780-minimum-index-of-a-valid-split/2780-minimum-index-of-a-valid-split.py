class Solution:
    def minimumIndex(self, nums: List[int]) -> int:
        n = len(nums)
        first_map, second_map = defaultdict(int), defaultdict(int)

        # Add all elements of nums to second_map
        for num in nums:
            second_map[num] += 1
        
        for i, num in enumerate(nums):
            # Create split at current index
            second_map[num] -= 1
            first_map[num] += 1

            # Check if valid split
            if first_map[num] * 2 > i + 1 and second_map[num] * 2 > n - i - 1:
                return i

        # No valid split exists
        return -1