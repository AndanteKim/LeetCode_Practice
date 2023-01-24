class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        n = len(nums)
        leftSum, rightSum = [0] * n, [0] * n
        
        for i in range(1, n):
            leftSum[i] = leftSum[i-1] + nums[i-1]
        
        for i in range(n-2, -1, -1):
            rightSum[i] = rightSum[i+1] + nums[i+1]
            
        for j in range(n):
            if leftSum[j] == rightSum[j]:
                return j
        return -1
        