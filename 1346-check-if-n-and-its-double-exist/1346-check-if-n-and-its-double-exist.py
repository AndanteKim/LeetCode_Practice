class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        seen = set()
        
        for num in arr:
            # Check if 2 * num or num / 2 exists in the set
            if 2 * num in seen or (num % 2 == 0 and (num >> 1) in seen):
                return True
            
            # Add the current number to the set
            seen.add(num)
            
        # No valid pair found
        return False