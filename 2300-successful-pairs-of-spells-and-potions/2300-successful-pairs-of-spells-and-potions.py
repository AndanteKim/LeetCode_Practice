class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        sortedSpells = [(spell, index) for index, spell in enumerate(spells)]
        
        sortedSpells.sort()
        potions.sort()
        
        answer = [0] * len(spells)
        m = len(potions)
        potionIndex = m - 1
        
        for spell, index in sortedSpells:
            while potionIndex >= 0 and (spell * potions[potionIndex] ) >= success:
                potionIndex -= 1
            answer[index] = m - (potionIndex + 1);
        return answer