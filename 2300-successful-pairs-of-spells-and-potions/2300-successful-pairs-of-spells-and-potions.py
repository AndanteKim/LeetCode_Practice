class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        ans = [0] * len(spells)
        potions.sort()
        for i in range(len(spells)):
            left, right = 0, len(potions)
            curr = right
            while left < right:
                mid = (left + right) // 2
                
                if spells[i] * potions[mid] < success:
                    left = mid + 1
                else:
                    right = mid
            ans[i] = curr - left
            
        return ans