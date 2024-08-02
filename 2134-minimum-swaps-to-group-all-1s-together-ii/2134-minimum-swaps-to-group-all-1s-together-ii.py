class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        ans, counts1, n = 0, nums.count(1), len(nums)
        for i in range(counts1):
            if nums[i] == 0:
                ans += 1
        
        window = ans
        for left in range(n):
            if nums[(left + counts1) % n] == 0:
                window += 1
            
            if nums[left] == 0:
                window -= 1
            
            ans = min(ans, window)
                
        return ans