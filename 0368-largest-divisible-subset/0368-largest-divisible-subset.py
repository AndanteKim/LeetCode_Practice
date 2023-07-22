class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        nums.sort()
        memo = dict()
        
        def EDS(i: int) -> int:
            if i in memo:
                return memo[i]
            tail = nums[i]
            maxSubset = []
            
            for p in range(0, i):
                if tail % nums[p] == 0:
                    subset = EDS(p)
                    if len(maxSubset) < len(subset):
                        maxSubset = subset
            maxSubset = maxSubset[:]
            maxSubset.append(tail)
            memo[i] = maxSubset
            return maxSubset
        
        return max([EDS(i) for i in range(len(nums))], key = len)