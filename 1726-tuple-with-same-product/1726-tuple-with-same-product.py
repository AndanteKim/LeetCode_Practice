class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        nums.sort()
        n, product_freq = len(nums), dict()

        for i in range(n - 1):
            for j in range(i + 1, n):
                product_freq[nums[i] * nums[j]] = product_freq.get(nums[i] * nums[j], 0) + 1

        ans = 0
        for product, freq in product_freq.items():
            ans += freq * (freq - 1) * 4
        
        return ans