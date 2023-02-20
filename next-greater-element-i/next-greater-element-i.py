class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        ans = []
        greater_table = defaultdict(lambda: -1)
        for i in range(len(nums2)):
            j = len(nums2) - 1
            while i < j:
                if nums2[i] < nums2[j]:
                    greater_table[nums2[i]] = nums2[j]
                j -= 1
            
        for i in range(len(nums1)):
            ans.append(greater_table[nums1[i]])
                
        return ans