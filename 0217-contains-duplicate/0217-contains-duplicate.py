class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        return False if set(Counter(nums).values()) == {1} else True