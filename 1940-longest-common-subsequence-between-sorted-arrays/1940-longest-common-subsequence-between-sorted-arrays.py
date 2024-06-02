class Solution:
    def longestCommonSubsequence(self, arrays: List[List[int]]) -> List[int]:
        
        def binary_search(target: int, nums: List[int]) -> bool:
            left, right = 0, len(nums) - 1
            
            while left <= right:
                mid = (left + right) >> 1
                if nums[mid] > target:
                    right = mid - 1
                elif nums[mid] < target:
                    left = mid + 1
                else:
                    return True
            
            return False
        
        shortest_arr = arrays[0]
        for arr in arrays:
            if len(arr) < len(shortest_arr):
                shortest_arr = arr
        
        longest_common_subseq = shortest_arr
        
        for arr in arrays:
            # There are no elements that are common to all of the arrays
            if len(longest_common_subseq) == 0:
                return longest_common_subseq
            uncommon = []
            
            # Remove any elements from the longest common subsequence
            # that are not in current array
            for num in longest_common_subseq:
                if not binary_search(num, arr):
                    uncommon.append(num)
            
            for num in uncommon:
                longest_common_subseq.remove(num)
                
        return longest_common_subseq