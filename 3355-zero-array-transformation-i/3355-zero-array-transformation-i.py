class Solution:
    def isZeroArray(self, nums: List[int], queries: List[List[int]]) -> bool:
        n = len(nums)
        delta = [0] * (n + 1)

        for l, r in queries:
            delta[l] += 1
            delta[r + 1] -= 1
        
        curr_ops, operation_counts = 0, [0] * (n + 1)
        
        for i, d in enumerate(delta):
            curr_ops += d
            operation_counts[i] = curr_ops

        for operations, target in zip(operation_counts, nums):
            if operations < target:
                return False

        return True