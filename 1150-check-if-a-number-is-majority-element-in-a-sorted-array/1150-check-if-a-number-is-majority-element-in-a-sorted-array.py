class Solution:
    def isMajorityElement(self, nums: List[int], target: int) -> bool:
        
        half = len(nums) / 2
        freq = defaultdict(int)
        
        for num in nums:
            freq[num] += 1
        
        return True if freq[target] > half else False