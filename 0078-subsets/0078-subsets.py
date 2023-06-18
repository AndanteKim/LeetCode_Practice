class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        ans = []
        
        for i in range(0, 1 << n):
            curr = []
            for j in range(n):
                if i & (1 << j):
                    curr.append(nums[j])
            ans.append(curr[:])
        
        return ans