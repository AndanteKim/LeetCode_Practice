class Solution:
    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:
        first, second = 0, 0

        while first < len(nums1) and second < len(nums2):
            if nums1[first] < nums2[second]:
                first += 1
            elif nums1[first] > nums2[second]:
                second += 1
            else:
                return nums1[first]

        return -1