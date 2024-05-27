class Solution:
    def specialArray(self, nums: List[int]) -> int:
        n = len(nums)
        check = [0] * (max(nums) + 1)
        
        for num in nums:
            check[num] += 1
            
        for i in range(1, len(check)):
            check[i] += check[i - 1]
        
        for i in range(len(check) - 1, 0, -1):
            if check[-1] - check[i - 1] == i:
                return i
        
        return -1