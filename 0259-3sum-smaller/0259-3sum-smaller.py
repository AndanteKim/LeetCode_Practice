class Solution:
    def binary_search(self, nums: List[int], start_index: int, target: int) -> int:
        left, right = start_index, self.n - 1
        while left < right:
            mid = (left + right + 1) >> 1
            if nums[mid] < target:
                left = mid
            else:
                right = mid - 1

        return left
    
    def two_sum_smaller(self, nums: List[int], start_index: int, target: int) -> None:
        sum = 0
        for i in range(start_index, self.n - 1):
            j = self.binary_search(nums, i, target - nums[i])
            sum += j - i
        
        return sum
    
    def threeSumSmaller(self, nums: List[int], target: int) -> int:
        self.n, ans = len(nums), 0
        nums.sort()
        for i in range(len(nums) - 2):
            ans += self.two_sum_smaller(nums, i + 1, target - nums[i])
        
        return ans