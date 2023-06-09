class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        left, right = 0, len(letters)
        
        while left < right:
            mid = (left + right) // 2
            
            if letters[mid] <= target:
                left = mid + 1
            else:
                right = mid
        
        return letters[0] if left == len(letters) else letters[left] 