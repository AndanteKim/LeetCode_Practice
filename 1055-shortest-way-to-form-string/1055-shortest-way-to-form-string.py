class Solution:
    def shortestWay(self, source: str, target: str) -> int:
        source_chars = set(source)
        
        for char in target:
            if char not in source_chars:
                return -1
            
        m = len(source)
        source_iterator, count = 0, 0
        
        for char in target:
            if source_iterator == 0:
                count += 1
            
            while source[source_iterator] != char:
                source_iterator = (source_iterator + 1) % m
                
                if source_iterator == 0:
                    count += 1
            
            source_iterator = (source_iterator + 1) % m
        
        return count