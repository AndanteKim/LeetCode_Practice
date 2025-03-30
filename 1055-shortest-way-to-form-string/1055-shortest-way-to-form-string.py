class Solution:
    def shortestWay(self, source: str, target: str) -> int:
        # To check it to_check is subsequence of in_string
        def is_subsequence(to_check: str, in_string: str) -> bool:
            i = j = 0
            while i < len(to_check) and j < len(in_string):
                if to_check[i] == in_string[j]:
                    i += 1
                j += 1
            
            return i == len(to_check)

        # Set of all characters of the source. We could use a boolean array as well.
        source_chars = set(source)

        # Check if all characters of the target are present in the source
        # If any character is not present, return -1
        for ch in target:
            if ch not in source_chars:
                return -1

        # Concatenate source until the target is a subsequence of the concatenated string
        concatenated_source = source
        ans = 1

        while not is_subsequence(target, concatenated_source):
            concatenated_source += source
            ans += 1
        
        # Number of concatenations done
        return ans