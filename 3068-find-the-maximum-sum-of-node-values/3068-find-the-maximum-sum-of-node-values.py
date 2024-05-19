class Solution:
    def maximumValueSum(self, nums: List[int], k: int, edges: List[List[int]]) -> int:
        n = len(nums)
        dp = [[0] * 2 for _ in range(n + 1)]
        
        dp[n][1], dp[n][0] = 0, float('-inf')
        
        for i in range(n - 1, -1, -1):
            for is_even in range(2):
                # Case 1: We perform an operation on this element
                xor_done = dp[i + 1][is_even ^ 1] + (nums[i] ^ k)
                
                # Case 2: We don't perform an operation on this element.
                non_xor_done = dp[i + 1][is_even] + nums[i]
                dp[i][is_even] = max(non_xor_done, xor_done)
        
        return dp[0][1]
        