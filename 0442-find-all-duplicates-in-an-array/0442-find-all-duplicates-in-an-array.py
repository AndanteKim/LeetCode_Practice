class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        bitwise, ans = 0, []
        
        for num in nums:
            if bitwise ^ (1 << num) < bitwise:
                ans.append(num)
            
            bitwise ^= (1 << num)
            
        return ans