class Solution:
    def anagramMappings(self, nums1: List[int], nums2: List[int]) -> List[int]:
        bitsToShift = 7
        numToGetLastBits = (1 << bitsToShift) - 1
        
        for i in range(len(nums1)):
            nums1[i] = (nums1[i] << bitsToShift) + i
            nums2[i] = (nums2[i] << bitsToShift) + i
            
        nums1.sort()
        nums2.sort()
        
        mappings = [0] * len(nums1)
        for i in range(len(nums1)):
            mappings[nums1[i] & numToGetLastBits] = (nums2[i] & numToGetLastBits)
        
        return mappings