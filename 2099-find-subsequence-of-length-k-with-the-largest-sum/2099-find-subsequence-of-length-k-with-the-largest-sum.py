class Solution:
    def maxSubsequence(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        vals = [[i, nums[i]] for i in range(n)]     # auxiliary array
        
        # Sort by numerical value in descending order
        vals.sort(key = lambda x: -x[1])

        # Select the first k elements and sort them in ascending order by index
        vals = sorted(vals[:k])
        ans = [val for idx, val in vals]
        return ans 