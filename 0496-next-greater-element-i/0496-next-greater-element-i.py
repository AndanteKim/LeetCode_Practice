class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        stack, m, len1, len2 = [], dict(), len(nums1), len(nums2)
        
        for i in range(0, len2):
            while (stack and nums2[i] > stack[-1]):
                m[stack.pop()] = nums2[i]
            stack.append(nums2[i])
        
        while stack:
            m[stack.pop()] = -1
        
        ans = [0] * len1
        
        for i in range(0, len1):
            ans[i] = m[nums1[i]]
        return ans
        
                