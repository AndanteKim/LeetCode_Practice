class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        num2_table, length2 = {elem : idx for idx, elem in enumerate(nums2)}, len(nums2)
        ans = []
        for num1 in nums1:
            try:
                for i in range(num2_table[num1], length2-1):
                    if num1 < nums2[i+1]:
                        ans.append(nums2[i+1])
                        break
                else:
                    ans.append(-1)
            
            except:
                ans.append(-1)
        return ans
                