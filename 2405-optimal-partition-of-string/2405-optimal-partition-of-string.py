class Solution:
    def partitionString(self, s: str) -> int:
        ans, hash_table = 1, [0] * 26
        
        for c in s:
            char = ord(c) - 97
            if hash_table[char] == 0:
                hash_table[char] += 1
            else:
                ans += 1
                hash_table = [0] * 26
                hash_table[char] += 1 
        return ans