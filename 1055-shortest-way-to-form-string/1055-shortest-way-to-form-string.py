class Solution:
    def shortestWay(self, source: str, target: str) -> int:
        source_length = len(source)
        next_occurrence = [defaultdict(int) for idx in range(source_length)]
        
        next_occurrence[source_length - 1][source[source_length - 1]] = source_length - 1
        
        for idx in range(source_length - 2, -1, -1):
            next_occurrence[idx] = next_occurrence[idx + 1].copy()
            next_occurrence[idx][source[idx]] = idx
            
        source_iterator, count = 0, 1
        
        for char in target:
            if char not in next_occurrence[0]:
                return -1
            
            if (source_iterator == source_length or \
               char not in next_occurrence[source_iterator]):
                count += 1
                source_iterator = 0
            
            source_iterator = next_occurrence[source_iterator][char] + 1
        
        return count