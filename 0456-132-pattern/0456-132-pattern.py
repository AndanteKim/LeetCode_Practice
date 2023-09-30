class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        if len(nums) < 3:
            return False
        n = len(nums)
        min_arr = [-1] * n
        min_arr[0] = nums[0]
        
        for i in range(1, n):
            min_arr[i] = min(min_arr[i - 1], nums[i])
        
        k = n
        for j in range(len(nums) - 1, -1, -1):
            if nums[j] <= min_arr[j]:
                continue
            k = bisect_left(nums, min_arr[j] + 1, k, n)
            if k < n and nums[k] < nums[j]:
                return True
            k -= 1
            nums[k] = nums[j]
        return False