class Solution:
    def subsequenceSumOr(self, nums: List[int]) -> int:
        ans, curr = 0, 0
        
        for n in nums:
            ans |= n
            curr += n
            ans |= curr
        
        return ans
        