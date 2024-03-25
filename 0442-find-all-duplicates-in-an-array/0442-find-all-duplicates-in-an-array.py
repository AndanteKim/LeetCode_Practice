class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        # one pass implement
        ans = []
        
        for num in nums:
            if nums[abs(num) - 1] < 0:
                # seen before
                ans.append(abs(num))
            nums[abs(num) - 1] *= -1
       
        return ans