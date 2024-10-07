class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        n, ans = len(nums), 0
        arr = [-2] * (2 * n + 1)
        max_len, count, arr[n] = 0, 0, -1
        
        for i in range(n):
            count = count + 1 if nums[i] == 1 else count - 1
            
            if arr[count + n] >= -1:
                max_len = max(max_len, i - arr[count + n])
            else:
                arr[count + n] = i
                
        return max_len