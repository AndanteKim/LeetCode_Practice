class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        if len(nums1) > len(nums2):
            return self.intersect(nums2, nums1)
        
        d = defaultdict(int)
        
        for n in nums1:
            d[n] += 1
            
        k = 0
        for n in nums2:
            if n in d and d[n] > 0:
                nums1[k] = n
                d[n] -= 1
                k += 1
            
        return nums1[:k]