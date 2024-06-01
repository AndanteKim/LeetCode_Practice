class Solution:
    def longestCommonSubsequence(self, arrays: List[List[int]]) -> List[int]:
        def longest_seq(nums1: List[int], nums2: List[int]) -> List[int]:
            longest_common_seq = []
            first, second = 0, 0
            
            # Traverse through both arrays with two pointers
            # Increment the pointer with a smaller value at that index
            # When the values are equal, add to the longest common subsequence
            while first < len(nums1) and second < len(nums2):
                if nums1[first] < nums2[second]:
                    first += 1
                elif nums1[first] > nums2[second]:
                    second += 1
                else:
                    longest_common_seq.append(nums1[first])
                    first += 1
                    second += 1
            return longest_common_seq
         
        # Iterate through the rest of the arrays and
        # If the common subsequence is empty, return immediately
        # Else update the longest common subsequence
        longest_common_subseq = arrays[0]
        
        for i in range(1, len(arrays)):
            if len(longest_common_subseq) == 0:
                return longest_common_subseq
            longest_common_subseq = longest_seq(longest_common_subseq, arrays[i])
            
        return longest_common_subseq