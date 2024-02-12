class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        ans, count = None, 0
        
        for num in nums:
            if count == 0:
                ans = num
            
            count += (1 if ans == num else -1)
       
        return ans