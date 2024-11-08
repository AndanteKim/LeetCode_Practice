class Solution:
    def getMaximumXor(self, nums: List[int], maximumBit: int) -> List[int]:
        n = len(nums)
        prefixXOR = [0] * n
        prefixXOR[0] = nums[0]
        
        for i in range(1, n):
            prefixXOR[i] = prefixXOR[i - 1] ^ nums[i]
            
        mask = (1 << maximumBit) - 1
        ans = [0] * n
        for i in range(n):
            # Find k to maximize value
            product = prefixXOR[n - 1 - i]
            ans[i] = product ^ mask
            
        return ans