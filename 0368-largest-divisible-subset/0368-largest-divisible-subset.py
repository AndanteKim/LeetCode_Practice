class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        def EDS(i: int) -> List[int]:
            # Recursion with memoization
            if i in memo:
                return memo[i]
            
            tail, max_subset = nums[i], []

            # The value of EDS(i) depends on it previous elements
            for p in range(0, i):
                if tail % nums[p] == 0:
                    subset = EDS(p)
                    if len(max_subset) < len(subset):
                        max_subset = subset
            
            # extend the found max subset with the current tail.
            max_subset = max_subset[:]
            max_subset.append(tail)

            # memorize the intermediate solutions for reuse.
            memo[i] = max_subset
            return memo[i]

        
        # Base case
        if len(nums) == 0:
            return []

        nums.sort()
        memo = dict()

        # Find the largest divisible subset
        return max([EDS(i) for i in range(len(nums))], key = len)