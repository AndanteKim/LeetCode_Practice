class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        n = len(nums)
        prefixMod, result = 0, 0
        
        modGroups = [0] * k
        modGroups[0] = 1
        
        for num in nums:
            prefixMod = (prefixMod + num % k + k) % k
            result += modGroups[prefixMod]
            modGroups[prefixMod] += 1
        
        return result
        