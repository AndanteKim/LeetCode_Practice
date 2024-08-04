class Solution:
    def rangeSum(self, nums: List[int], n: int, left: int, right: int) -> int:
        subarr = []
        
        for i in range(n):
            partial = 0
            for j in range(i, n):
                partial = (partial + nums[j]) % (1_000_000_007)
                subarr.append(partial)
        
        subarr.sort()
        
        return sum(subarr[left - 1: right]) % (1_000_000_007)