class Solution:
    def largestUniqueNumber(self, nums: List[int]) -> int:
        ans, freq = -1, dict()
        
        for x in nums:
            freq[x] = freq.get(x, 0) + 1
            
        for key, val in freq.items():
            if val == 1 and key > ans:
                ans = key
                
        return ans