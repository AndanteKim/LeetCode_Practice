class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        map_index = dict()  
        words = s.split(' ')
        
        if len(words) != len(pattern):
            return False
        
        for i in range(len(words)):
            c, w = pattern[i], words[i]
            
            char_key = 'char_{}'.format(c)
            char_word = 'word_{}'.format(w)
            
            if char_key not in map_index:
                map_index[char_key] = i
            
            if char_word not in map_index:
                map_index[char_word] = i
            
            if map_index[char_key] != map_index[char_word]:
                return False
                
        return True