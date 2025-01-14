class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        n = len(A)
        prefix_common_arr = [0] * n

        # Loop through each index to calculate common elements for each prefix
        for curr_idx in range(n):
            common_cnt = 0

            # Compare elements in A and B within the range of current prefix
            for a_idx in range(curr_idx + 1):
                for b_idx in range(curr_idx + 1):

                    # Check if elements match, and count if they do
                    if A[a_idx] == B[b_idx]:
                        common_cnt += 1
                        break   # Prevent counting duplicates
            
            # Store the count of common elements for the current prefix
            prefix_common_arr[curr_idx] = common_cnt
        
        # Return the final list with counts of common elements in each prefix
        return prefix_common_arr
