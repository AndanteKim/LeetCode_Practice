class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        ans = []
        
        for i in range(2 ** n, 2 ** (n + 1)):
            bitmask = bin(i)[3:]
            ans.append([nums[j] for j in range(n) if bitmask[j] == '1'])
        
        return ans