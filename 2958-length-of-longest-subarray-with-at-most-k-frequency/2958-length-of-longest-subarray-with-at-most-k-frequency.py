class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        # base case
        if k <= 0:
            return 0
        
        count, n, left = defaultdict(int), len(nums), 0
        curr, ans = 0, 0
        
        for right in range(n):
            while count[nums[right]] == k and left < right:
                count[nums[left]] -= 1
                left += 1
                curr -= 1
            
            count[nums[right]] += 1
            curr += 1
            ans = max(ans, curr)
            
        return ans