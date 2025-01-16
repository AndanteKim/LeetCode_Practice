class Solution:
    def xorAllNums(self, nums1: List[int], nums2: List[int]) -> int:
        # Base case
        if len(nums1) % 2 == 0 and len(nums2) % 2 == 0:
            return 0
        
        num1_xors, num2_xors = 0, 0
        
        if len(nums2) % 2 == 1:
            for n1 in nums1:
                num1_xors ^= n1
        
        if len(nums1) % 2 == 1:
            for n2 in nums2:
                num2_xors ^= n2

        return num1_xors ^ num2_xors