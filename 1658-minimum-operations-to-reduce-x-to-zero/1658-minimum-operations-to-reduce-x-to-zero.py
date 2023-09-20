class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        n, suffix = len(nums), defaultdict(int)
        ans, total = float('inf'), 0
        for i in range(n - 1, -1, -1):
            total += nums[i]
            suffix[total] = i + 1
            if total == x:
                ans = min(ans, n - i)
        
        total = 0
        for i in range(n):
            total += nums[i]
            
            if total == x:
                ans = min(ans, i + 1)
            if suffix[x - total] != 0 and suffix[x - total] - 1 > i:
                ans = min(ans, i + n - suffix[x - total] + 2)
        return -1 if ans == float('inf') else ans