class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        nums.sort()
        n = len(nums)
        i, j, ans = 0, n - 1, 0
        
        while i < j:
            if nums[i] + nums[j] == k:
                i += 1
                j -= 1
                ans += 1
            elif nums[i] + nums[j] > k:
                j -= 1
            else:
                i += 1
        
        return ans