class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        cache, n, ans = dict(), len(nums), []
        
        for num in nums:
            cache[num] = cache.get(num, 0) + 1
        
        for k, v in cache.items():
            if v > n // 3:
                ans.append(k)
                
        return ans
            