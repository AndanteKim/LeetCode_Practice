class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        lookup = dict()
        
        for i in range(len(nums)):
            find = target - nums[i]
            if find in lookup:
                return [i, lookup[find]]
            
            lookup[nums[i]] = i
        return [-1, -1]