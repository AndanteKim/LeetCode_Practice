class Solution:
    def minIncrementForUnique(self, nums: List[int]) -> int:
        def find(x: int) -> int:
            root[x] = find(root[x] + 1) if x in root else x
            return root[x]
            
        root = dict()
        return sum(find(n) - n for n in nums)