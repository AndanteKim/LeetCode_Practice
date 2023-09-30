class Solution:
    def countSubarrays(self, nums: List[int]) -> int:
        # greedy algorithm
        ans, i, n = 0, 0, len(nums)
        
        while i < n:
            # length of the current subarray
            curr = 1
            while i + 1 < n and nums[i] < nums[i + 1]:
                curr += 1
                i += 1
                
            # add the total number of different subarrays possible from this length
            ans += (curr * (curr + 1)) // 2
            i += 1
        
        return ans