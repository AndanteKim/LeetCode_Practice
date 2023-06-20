class Solution:
    def getAverages(self, nums: List[int], k: int) -> List[int]:
        radius, n = 2 * k + 1, len(nums)
        ans, left, total = [-1] * n, 0, 0
        
        for right in range(n):
            total += nums[right]
            
            while right - left + 1 >= radius:
                ans[k + left] = total // radius
                total -= nums[left]
                left += 1
        
        return ans