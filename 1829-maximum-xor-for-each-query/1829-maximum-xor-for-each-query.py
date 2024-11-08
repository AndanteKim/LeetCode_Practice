class Solution:
    def getMaximumXor(self, nums: List[int], maximumBit: int) -> List[int]:
        n, max_num = len(nums), 2 ** maximumBit - 1
        start_nums = 0
        for num in nums:
            start_nums ^= num
            
        ans = [0] * n
        for i in range(n - 1, -1, -1):
            k = max_num ^ start_nums
            start_nums ^= nums[i]
            ans[i] = k
        ans.reverse()
        
        return ans