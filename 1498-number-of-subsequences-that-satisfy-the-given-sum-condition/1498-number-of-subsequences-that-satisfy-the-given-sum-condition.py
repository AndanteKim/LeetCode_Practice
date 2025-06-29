class Solution:
    def numSubseq(self, nums: List[int], target: int) -> int:
        n, mod = len(nums), 1_000_000_007
        nums.sort()
        ans, left, right = 0, 0, n - 1
        power = [0] * n
        power[0] = 1
        for i in range(1, n):
            power[i] = power[i - 1] * 2 % mod
        

        while left <= right:
            if nums[left] + nums[right] <= target:
                ans = (ans + power[right - left]) % mod
                left += 1
            else:
                right -= 1
            
        return ans