class Solution:
    def anagramMappings(self, nums1: List[int], nums2: List[int]) -> List[int]:
        mapping_1, mapping_2 = dict(), dict()
        
        for i in range(len(nums1)):
            mapping_1[nums1[i]] = i
        
        for i in range(len(nums2)):
            mapping_2[nums2[i]] = i
        
        return [mapping_2[nums1[i]] for i in range(len(nums1))]