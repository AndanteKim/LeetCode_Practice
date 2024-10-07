class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        # Dictionary key: count, val: index
        saved, count = {0 : -1}, 0
        ans, n = 0, len(nums)
        
        for i in range(n):
            count = count + 1 if nums[i] == 1 else count - 1
            
            if count in saved:
                ans = max(ans, i - saved[count])
            else:
                saved[count] = i
        
        return ans