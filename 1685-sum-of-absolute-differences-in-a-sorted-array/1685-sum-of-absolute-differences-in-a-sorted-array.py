class Solution:
    def getSumAbsoluteDifferences(self, nums: List[int]) -> List[int]:
        prefix_sum, suffix_sum = 0, sum(nums)
        ans, n = [], len(nums)
        
        for i, num in enumerate(nums):
            ans.append(i * num - prefix_sum + suffix_sum - (n - i) * num)
            prefix_sum += num
            suffix_sum -= num
        
        return ans