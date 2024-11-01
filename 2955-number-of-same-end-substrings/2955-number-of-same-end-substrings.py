class Solution:
    def sameEndSubstringCount(self, s: str, queries: List[List[int]]) -> List[int]:
        # Dictionary to store each character and its positions in the string 's'
        n, char_pos_map = len(s), defaultdict(list)
        
        # Traverse the string and store the index of each character in the dictionary
        for i in range(n):
            char_pos_map[s[i]].append(i)
        
        ans = []
        
        # Process each query
        for left_idx, right_idx in queries:
            count_same_end_substrings = 0
            
            # For each unique character in the string, calculate the number of same-end substrings
            for positions in char_pos_map.values():
                # Get the number of occurrences of the character within the range [left_index, right_index]
                left_bound = bisect_left(positions, left_idx)
                right_bound = bisect_right(positions, right_idx)
                num_occurrences = right_bound - left_bound
                
                # Calculate the number of same-end substrings for this character
                count_same_end_substrings += ((num_occurrences * (num_occurrences + 1)) >> 1)
            
            # Store the result for this query
            ans.append(count_same_end_substrings)
            
        return ans