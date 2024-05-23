class Solution:
    def beautifulSubsets(self, nums: List[int], k: int) -> int:
        self.n = len(nums)
        return self._count_beautiful_subsets(nums, k, 0, 0)
    
    def _count_beautiful_subsets(self, nums: List[int], diff: int, i: int, mask: int) -> int:
        # Base case: Return 1 if mask is greater than 0 (non-empty subset)
        if i == self.n:
            return 1 if mask > 0 else 0
        
        # Flag to check if the current subset is beautiful
        is_beautiful = True
        
        # Check if the current number forms a beautiful pair with any
        # previous number in the subset
        for j in range(i):
            if ((1 << j) & mask) == 0 or abs(nums[j] - nums[i]) != diff:
                continue
            else:
                is_beautiful = False
                break
        
        # Recursively calculate beautiful subsets including and excluding
        skip = self._count_beautiful_subsets(nums, diff, i + 1, mask)
        take = (self._count_beautiful_subsets(nums, diff, i + 1, mask + (1 << i)) if is_beautiful else 0)
        
        return skip + take
        