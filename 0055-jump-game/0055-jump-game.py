class Solution:
    def canJump(self, nums: List[int]) -> bool:
        def can_jump_from_position(i: int) -> bool:
            if memo[i] != -1:
                return True if memo[i] == 1 else False
            
            furthest_jump = min(n - 1, nums[i] + i)
            for nxt in range(i + 1, furthest_jump + 1):
                if can_jump_from_position(nxt):
                    memo[i] = 1
                    return True
            memo[i] = 0
            return False
        
        good, bad, unknown, n = 1, 0, -1, len(nums)
        memo = [unknown] * n
        memo[n - 1] = good
        return can_jump_from_position(0)