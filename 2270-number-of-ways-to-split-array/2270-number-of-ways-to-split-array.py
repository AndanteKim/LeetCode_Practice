class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        n, cnt = len(nums), 0
        prefix_sum, suffix_sum = [nums[0]], [nums[-1]]
        for i in range(1, n):
            prefix_sum.append(prefix_sum[-1]+nums[i])
            suffix_sum.append(suffix_sum[-1]+nums[n-1-i])
        

        for i in range(n-1):
            if prefix_sum[i] >= suffix_sum[n-2-i]:
                cnt += 1
        
        return cnt