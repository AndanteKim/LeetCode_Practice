class Solution:
    def is_subsequence(self, to_check: str, in_string: str) -> bool:
        i = j = 0
        while i < len(to_check) and j < len(in_string):
            if to_check[i] == in_string[j]:
                i += 1
            j += 1
        
        return i == len(to_check)
    
    def shortestWay(self, source: str, target: str) -> int:
        source_chars = set(source)
        
        for char in target:
            if char not in source_chars:
                return -1
            
        concatenated_source = source
        count = 1
        while not self.is_subsequence(target, concatenated_source):
            concatenated_source += source
            count += 1
        
        return count