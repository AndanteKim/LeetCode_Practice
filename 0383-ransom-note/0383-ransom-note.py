class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        """ransom_table, mag_table = defaultdict(int), defaultdict(int)
        
        for c in ransomNote:
            ransom_table[c] += 1
        for c in magazine:
            magazine[c] += 1
        """
        
        return False if Counter(ransomNote) - Counter(magazine) else True