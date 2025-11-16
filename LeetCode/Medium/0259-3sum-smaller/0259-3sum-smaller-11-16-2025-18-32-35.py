class Solution:
    def two_sum(self, nums: List[int], start: int, target: int) -> int:
        left, right = start, self.n - 1
        total = 0

        while left < right:
            if nums[left] + nums[right] < target:
                total += right - left
                left += 1
            else:
                right -= 1
        
        return total


    def threeSumSmaller(self, nums: List[int], target: int) -> int:
        nums.sort()
        ans, self.n = 0, len(nums)

        for i in range(self.n - 2):
            ans += self.two_sum(nums, i + 1, target - nums[i])

        return ans