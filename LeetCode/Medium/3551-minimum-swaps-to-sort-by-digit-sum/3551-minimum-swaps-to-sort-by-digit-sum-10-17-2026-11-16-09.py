class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        n = len(nums)
        digit_sum = [0] * n

        for i, v in enumerate(nums):
            s = 0
            while v > 0:
                s += v % 10
                v //= 10
            digit_sum[i] = s

        indices = list(range(n))
        indices.sort(key = lambda i: (digit_sum[i], nums[i]))

        target_pos = [0] * n
        for pos, idx in enumerate(indices):
            target_pos[idx] = pos
        
        cycles, visited = 0, [False] * n

        for i in range(n):
            if not visited[i]:
                cycles += 1
                j = i
                while not visited[j]:
                    visited[j] = True
                    j = target_pos[j]
        
        return n - cycles