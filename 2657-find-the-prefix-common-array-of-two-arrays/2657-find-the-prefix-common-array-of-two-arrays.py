class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        n = len(A)
        freq, prefix_common_arr = [0] * (n + 1), [0] * n
        common_count = 0

        # Iterate through the elements of both arrays
        for curr_idx in range(n):
            # Increment frequency of current elements in A and B
            # Check if the element in A has appeared before (common in prefix)
            freq[A[curr_idx]] += 1
            if freq[A[curr_idx]] == 2:
                common_count += 1

            # Check the element in B has appeared before (common in prefix)
            freq[B[curr_idx]] += 1
            if freq[B[curr_idx]] == 2:
                common_count += 1

            # Store the count of common elements for the current prefix
            prefix_common_arr[curr_idx] = common_count

        # Return the final array with counts of common elements in each prefix
        return prefix_common_arr