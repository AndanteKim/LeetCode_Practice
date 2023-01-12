class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        counter_nums = Counter(nums)
        
        for key, value in counter_nums.items():
            if value > 1:
                return True
        
        return False