class Solution:
    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:
        elems = set(nums1).intersection(set(nums2))

        return -1 if len(elems) == 0 else min(elems)