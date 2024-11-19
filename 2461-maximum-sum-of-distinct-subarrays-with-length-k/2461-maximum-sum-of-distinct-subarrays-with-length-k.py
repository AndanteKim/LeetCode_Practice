class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        ans, n, left, curr_sum = 0, len(nums), 0, 0
        freq = dict()
        
        for right in range(n):
            freq[nums[right]] = freq.get(nums[right], 0) + 1
            curr_sum += nums[right]
            
            while right - left >= k:
                curr_sum -= nums[left]
                freq[nums[left]] -= 1
                if freq[nums[left]] == 0:
                    del freq[nums[left]]
                left += 1
            
            if len(freq) == k:
                ans = max(ans, curr_sum)
            
        return ans