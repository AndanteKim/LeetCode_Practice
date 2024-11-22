class Solution:
    def maxEqualRowsAfterFlips(self, matrix: List[List[int]]) -> int:
        # Dictionary to store frequency of each pattern
        pattern_freq = dict()
        
        for curr_row in matrix:
            # Convert row to pattern using list comprehension and join
            # 'T' if element matches first element, 'F' otherwise
            row_pattern = "".join(
                'T' if num == curr_row[0] else 'F' for num in curr_row
            )
            
            # Update pattern frequency using dict.get() with default value
            pattern_freq[row_pattern] = pattern_freq.get(row_pattern, 0) + 1
            
        # Return maximum frequency using max() with default of 0
        return max(pattern_freq.values(), default = 0)