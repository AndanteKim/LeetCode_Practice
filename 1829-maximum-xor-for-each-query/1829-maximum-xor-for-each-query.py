class Solution:
    def getMaximumXor(self, nums: List[int], maximumBit: int) -> List[int]:
        xor_product, n = 0, len(nums)
        for num in nums:
            xor_product ^= num
            
        mask = (1 << maximumBit) - 1
        ans = [0] * n
        
        for i in range(n):
            ans[i] = mask ^ xor_product
            # Remove the last element
            xor_product ^= nums[n - 1 - i]
        
        return ans