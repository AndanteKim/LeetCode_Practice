class Solution:
    mod = 10 ** 9 + 7
    def sum_of_first_k(self, nums: List[int], n: int, k: int) -> int:
        min_sum, max_sum = min(nums), sum(nums)
        left, right, total_sum, count = min_sum, max_sum, 0, 0
        
        while left <= right:
            mid = (left + right) >> 1
            count, total_sum = self.count_and_sum(nums, n, mid) 
            if count >= k:
                right = mid - 1
            else:
                left = mid + 1
                
        return total_sum - (left * (count - k))
    
    def count_and_sum(self, nums: List[int], n: int, target: int) -> Tuple[int]:
        count, curr_sum, total_sum, window_sum = 0, 0, 0, 0
        i = 0
        for j in range(n):
            curr_sum += nums[j]
            window_sum += nums[j] * (j - i + 1)
            while curr_sum > target:
                window_sum -= curr_sum
                curr_sum -= nums[i]
                i += 1
            count += j - i + 1
            total_sum += window_sum
        return count, total_sum
    
    def rangeSum(self, nums: List[int], n: int, left: int, right: int) -> int:
        mod = int(1e9 + 7)
        ans = (self.sum_of_first_k(nums, n, right) - self.sum_of_first_k(nums, n, left - 1)) % mod
        
        return (ans + mod) % mod