class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        common = Counter(nums1) & Counter(nums2)
        
        ans = []
        for c, v in common.items():
            ans.extend([c] * v)
            
        return ans