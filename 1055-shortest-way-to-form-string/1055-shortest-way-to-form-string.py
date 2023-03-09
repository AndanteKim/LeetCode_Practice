class Solution:
    def shortestWay(self, source: str, target: str) -> int:
        char_to_indices = defaultdict(list)
        
        for i, c in enumerate(source):
            char_to_indices[c].append(i)
        
        source_iterator = 0
        count = 1
        
        for char in target:
            if char not in char_to_indices:
                return -1
            
            index = bisect.bisect_left(char_to_indices[char], source_iterator)
            
            if index == len(char_to_indices[char]):
                count += 1
                source_iterator = char_to_indices[char][0] + 1
            else:
                source_iterator = char_to_indices[char][index] + 1
            
        return count