class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        prefix = dict()
        ans, count, n = 0, 0, len(nums)
        
        for i in range(n):
            count += 1 if nums[i] == 1 else -1
            
            # Array from index 0 to i contains equal number of 0's and 1's
            if count == 0:
                ans = max(ans, i + 1)
            
            if count in prefix:
                ans = max(ans, i - prefix[count])
            else:
                prefix[count] = i
                
        return ans
                
              