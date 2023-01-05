class Solution:
    def signFunc(self, res: int) -> int:
        return 1 if res > 0 else -1
    
    def arraySign(self, nums: List[int]) -> int:
        ans = 1
        for i in range(len(nums)):
            ans *= nums[i]
            if nums[i] == 0:
                return 0
        return self.signFunc(ans)