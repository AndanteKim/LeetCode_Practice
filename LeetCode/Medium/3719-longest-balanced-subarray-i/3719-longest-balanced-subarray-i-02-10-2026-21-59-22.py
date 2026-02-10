class Solution:
    def longestBalanced(self, nums: List[int]) -> int:
        n, ans = len(nums), 0

        for i in range(n - 1):
            odd_freq, even_freq = dict(), dict()        
            for j in range(i, n):
                if nums[j] & 1:
                    odd_freq[nums[j]] = odd_freq.get(nums[j], 0) + 1
                else:
                    even_freq[nums[j]] = even_freq.get(nums[j], 0) + 1
            
                if len(even_freq) == len(odd_freq):
                    ans = max(ans, j - i + 1)

        return ans 