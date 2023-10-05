class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        sorted_spells = [(spell, i) for i, spell in enumerate(spells)]
        
        sorted_spells.sort()
        potions.sort()
        
        ans = [0] * len(spells)
        m = len(potions)
        potion_index = m - 1
        
        for spell, i in sorted_spells:
            while potion_index >= 0 and (spell * potions[potion_index]) >= success:
                potion_index -= 1
            ans[i] = m - (potion_index + 1)
        
        return ans