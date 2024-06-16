class Solution:
    def minPatches(self, nums: List[int], n: int) -> int:
        patches, i = 0, 0
        miss = 1
        
        while miss <= n:
            if i < len(nums) and nums[i] <= miss: # miss is covered
                miss += nums[i]
                i += 1
            else:
                # patch miss to the array
                miss += miss
                patches += 1 # increase the answer
        
        return patches
