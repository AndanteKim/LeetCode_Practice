class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        indices = [-1] + [idx for idx, v in enumerate(nums) if v] + [len(nums)]
        ans = 0
        
        if goal == 0:
            for i in range(len(indices) - 1):
                w = indices[i+1] - indices[i] - 1
                ans += (w * (w+1)) // 2
            return ans
        
        for i in range(1, len(indices) - goal):
            j = i + goal - 1
            left = indices[i] - indices[i-1]
            right = indices[j+1] - indices[j]
            ans += left * right
        return ans