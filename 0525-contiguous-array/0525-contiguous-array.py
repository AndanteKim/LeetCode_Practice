class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        n = len(nums)
        ans, arr = 0, [-2] * (2 * n + 1)
        arr[n], ans, count = -1, 0, 0
        
        for i in range(n):
            count += -1 if nums[i] == 0 else 1
            if arr[count + n] >= -1:
                ans = max(ans, i - arr[count + n])
            else:
                arr[count + n] = i
            
        return ans