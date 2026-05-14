class Solution:
    def isGood(self, nums: List[int]) -> bool:
        n = max(nums)
        remain = {i:2 if i == n else 1 for i in range(n, 0, -1)}        

        for num in nums:
            if num > n or remain[num] == 0:
                return False
            remain[num] -= 1
        
        for _, cnt in remain.items():
            if cnt > 0:
                return False

        return True