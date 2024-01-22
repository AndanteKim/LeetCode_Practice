class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        nums.sort()
        mx = max(nums)
        count = [0] * (mx + 1)
        
        for n in nums:
            count[n] += 1
            
        ans = [-1, -1]
        for i in range(1, mx + 1):
            if count[i] == 2:
                ans[0] = i
            
            if count[i] == 0:
                ans[1] = i
            
        return [ans[0], mx + 1] if ans[1] == -1 else ans
        