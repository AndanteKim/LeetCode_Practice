class Solution:
    def uniformArray(self, nums1: list[int]) -> bool:
        mn, has_odd = nums1[0], False

        for num in nums1:
            if num < mn:
                mn = num
            
            if num & 1:
                has_odd = True

        if mn & 1:
            return True
        return not has_odd
        