class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        subsets = {-1: set()}
        nums.sort()
        for num in nums:
            subsets[num] = max([subsets[k] for k in subsets if num % k == 0], key = len) | {num}
        
        return list(max(subsets.values(), key = len))