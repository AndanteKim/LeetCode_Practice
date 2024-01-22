class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        freqs = dict()
        dup, missing = -1, 1
        
        for n in nums:
            freqs[n] = freqs.get(n, 0) + 1
            
        for i in range(1, len(nums) + 1):
            if i in freqs:
                if freqs[i] == 2:
                    dup = i
            else:
                missing = i
                
        return [dup, missing]