class Solution:
    def intersection(self, nums: List[List[int]]) -> List[int]:
        
        curr_set = set(nums[0])
        for num in nums:
            curr_set = curr_set.intersection(set(num))
            
        
        return sorted(list(curr_set))