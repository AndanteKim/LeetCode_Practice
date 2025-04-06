class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        if len(nums) == 0:
            return []

        nums.sort()

        # The container keeping the size of the largest divisible subset endings with X_i
        # dp[i] corresponds to len(EDS(X_i))
        dp = [0] * len(nums)

        """ Build the DP matrix/vector """

        for i, num in enumerate(nums):
            max_subset_sz = 0

            for k in range(0, i):
                if nums[i] % nums[k] == 0:
                    max_subset_sz = max(max_subset_sz, dp[k])
            
            max_subset_sz += 1
            dp[i] = max_subset_sz
        
        """ Find both the size of largest divisible set and its index """
        max_size, max_size_idx = max([(v, i) for i, v in enumerate(dp)])
        ans = []

        """ Reconstruct the largest divisible subset """
        # curr_size: the size of the current subset
        # curr_tail: the last element in the current subset
        curr_size, curr_tail = max_size, nums[max_size_idx]

        for i in range(max_size_idx, -1, -1):
            if curr_size == dp[i] and curr_tail % nums[i] == 0:
                ans.append(nums[i])
                curr_size -= 1
                curr_tail = nums[i]
        
        return ans[::-1]