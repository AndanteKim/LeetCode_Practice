class Solution:
    def canSortArray(self, nums: List[int]) -> bool:
        n = len(nums)
        
        # Avoid modifying the input directly
        # Create a copy of the input array
        values = nums[:]
        
        for i in range(0, n):
            for j in range(0, n - i - 1):
                if values[j] <= values[j + 1]:
                    # No swap needed
                    continue
                else:
                    if bin(values[j]).count('1') == bin(values[j + 1]).count('1'):
                        # Swap the elements 
                        values[j], values[j + 1] = values[j + 1], values[j]
                    else:      
                        return False
                    
        return True