class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ans, dups = set(), set()
        seen = dict()
        
        for i, val1 in enumerate(nums):
            if val1 not in dups:
                dups.add(val1)
                for j, val2 in enumerate(nums[i + 1:]):
                    complement = - (val1 + val2)
                    if complement in seen and seen[complement] == i:
                        ans.add(tuple(sorted((val1, val2, complement))))
                    seen[val2] = i
        
        return ans